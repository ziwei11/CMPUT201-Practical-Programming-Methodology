#define _POSIX_C_SOURCE 200809L // <-- needed for getline
#include "checkinput.h"
#include "combo.h"
#include "combo.h" // Make sure the guard works
#include "parameters.h"
#include "parameters.h" // Make sure the guard works
#include "parameters.h" // Make sure it really works!
#include "ppd.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// You don't have to modify this file

/* Example input:
string Name
5
Pikachu Raichu Jigglypuff Charmander Bulbasaur
long Magnitude
4
0 10 100 1000 
string Class
Water Earth Fire Electric
double Trance
3
3.1415926535897932384
2.7182818284590452354
1.4142135623730950488
char X
A
B
C
*/

#define NTYPEFLAGS 4
const char * types[] = {
  "long",
  "double",
  "string",
  "char"
};

#define BUFFSIZE 1024

void invalidInput() {
  printf("Invalid Input!\n");
  exit(1);
}

TypeFlag typeFlagOfString(char * typeFlagString) {
  for (int i = 0 ; i < NTYPEFLAGS; i++) {
    if (strncmp(typeFlagString, types[i], BUFFSIZE) == 0) {
      return (TypeFlag)i;
    }
  }
  invalidInput();
  return -1;
}

bool notEOF(int scanfRes) {
  if (scanfRes == 1) {
    return true;
  }
  if (scanfRes == EOF) {
    return false;
  }
  invalidInput();
  return false;
}

Parameter readParameter(PPDArray array, TypeFlag flag, ParameterDef def) {
  char strinput[BUFFSIZE] = { '\0' };
  long int linput;
  double dinput;
  switch((int)flag) {
  case LONG:
    checkInput(scanf("%ld", &linput));
    return mkLongParameter( def, linput );
  case CHAR:
    checkInput(scanf("%s", strinput));
    if (strlen(strinput)!=1) {
      invalidInput();
    }
    return mkCharParameter( def, strinput[0] );
  case STRING:
    checkInput(scanf("%s", strinput));
    char * strbuf = strndup(strinput, BUFFSIZE); // leak prone
    addStringPPDArray( array, strbuf );
    return mkStringParameter( def, strbuf );
  case DOUBLE:
    checkInput(scanf("%lf", &dinput));
    return mkDoubleParameter( def, dinput );
  default:
    invalidInput();
    break;
  }
  abort();
}

void readParameters(PPDArray array, Combo combo, char * type) {
  char name[BUFFSIZE] = { '\0' };
  TypeFlag flag = typeFlagOfString( type );
  checkInput(scanf("%s", name));
  char * nameHeap = strdup(name);
  addStringPPDArray( array, nameHeap );
  ParameterDef def = mkParameterDef( nameHeap, flag);
  addParameterDefCombo( combo, def );
  size_t size = 0;
  checkInput(scanf("%lu", &size));
  if (size > BUFFSIZE) {
    invalidInput();         
  }
  for (size_t i = 0 ; i < size ; i++) {
    Parameter param = readParameter(array, flag, def);
    addParameterCombo( combo, param );
  }  
}

int main() {
  Combo combo = createParameterCombo();
  PPDArray strArray = createPPDArray();
  char type[BUFFSIZE] = { '\0' };
  while( notEOF(scanf("%s", type)) ) {
    readParameters( strArray, combo, type );
  }
  // Now it's all loaded up ready to go
  size_t nparams = nParamsCombo(combo);
  if (nparams < 1) {
    invalidInput();
  }
  while( hasNextCombo(combo) ) {
    Parameter * params = nextCombo(combo);
    printParams(params, nparams);
    freeParamsCombo( combo, params );
  }
  // clean up strings we strdup'd
  size_t allocatedStrings = sizePPDArray( strArray );
  for (size_t i = 0; i < allocatedStrings; i++) {
    char * str = stringPPDArray( strArray, i );
    free(str);
  }
  freePPDArray( strArray );
  freeCombo(combo);
}
