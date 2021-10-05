#include "parameters.h" // Make sure the guard works
#include "parameters.h" // Make sure the guard works
#include "ppd.h"
#include "ppd.h" 
#include <assert.h>
#include <stdio.h>

// You shouldn't modify this file

#define NAMES 1000
#define NAMECHARS 6
#define NALPHA 26

ParameterDef newParameterDef( char * name, TypeFlag flag ) {
  switch((int)flag) {
  case LONG:
    return longParameterDef( name );
  case DOUBLE:
    return doubleParameterDef( name );
  case STRING:
    return stringParameterDef( name );
  case CHAR:
    return charParameterDef( name );
  default:
    abort();
    break;
  }
}

void testPPDParameterDef() {
  char defNames[NAMES][NAMECHARS];
  for (int i = 0 ; i < NAMES; i++) {
    for (int j = 0 ; j < NAMECHARS-1; j++) {
      defNames[i][j] = (char)(rand()%NALPHA + 'a');
    }
    defNames[i][NAMECHARS-1] = '\0';
  }
  PPDArray array = createPPDArray();
  ParameterDef def;
  for (int i = 0 ; i < NAMES; i++) {
    int type = rand() % 4;
    def = newParameterDef( defNames[i], type );
    addDefPPDArray( array, def );
    assert(sizePPDArray( array ) == (size_t)(i + 1));
    assert(equalParameterDef( parameterDefPPDArray( array, i ), def));
    assert( equalParameterDef( *parameterDefRefPPDArray( array, i ),def));

  }
  freePPDArray( array );
}

void testPPDParameter() {
  char defNames[NAMES][NAMECHARS];
  for (int i = 0 ; i < NAMES; i++) {
    for (int j = 0 ; j < NAMECHARS-1; j++) {
      defNames[i][j] = (char)(rand()%NALPHA + 'a');
    }
    defNames[i][NAMECHARS-1] = '\0';
  }
  PPDArray array = createPPDArray();
  ParameterDef def = stringParameterDef( "Socks" );
  for (int i = 0 ; i < NAMES; i++) {
    Parameter param  = mkStringParameter( def, defNames[i] );
    addParamPPDArray( array, param );
    assert(sizePPDArray( array ) == (size_t)(i + 1));
    assert(equalParameter( parameterPPDArray( array, i ), param));
  }
  freePPDArray( array );
}


#define INT64ARRS 10
#define EXERCISE 1000
void testInt64() {
  PPDArray arrays[INT64ARRS];
  for (int i = 0 ; i < INT64ARRS; i++) {
    arrays[i] = createPPDArray();
  }
  for (int i = 0 ; i < EXERCISE; i++) {
    int64_t input = i * i;
    for (int j = 0 ; j < INT64ARRS; j++) {
      addInt64PPDArray(arrays[j], input);
    }
    for (int j = 0 ; j < INT64ARRS; j++) {
      assert(int64PPDArray(arrays[j], i) == input);
      setInt64PPDArray(arrays[j], i, input + 1);
      assert(int64PPDArray(arrays[j], i) == input+1);
    }
  }
  for (int i = 0 ; i < INT64ARRS; i++) {
    freePPDArray( arrays[i] );
  }
}
#define WEAKPIE 3.14
void testArrays() {
  PPDArray arrays[INT64ARRS];
  for (int i = 0 ; i < INT64ARRS; i++) {
    arrays[i] = createPPDArray();
  }
  PPDArray array = createPPDArray();
  for (int i = 0 ; i < INT64ARRS; i++) {
    addPPDArrayPPDArray( array, arrays[i] );
  }
  for (int i = 0 ; i < INT64ARRS; i++) {
    PPDArray arr = arrayPPDArray( array, i );
    assert(arr == arrays[i]);
    assert(sizePPDArray(arr) == 0);
    ParameterDef def = doubleParameterDef( "Fish" );
    for (int i = 0 ; i < EXERCISE; i++) {
      Parameter param = mkDoubleParameter( def, i * WEAKPIE );
      addParamPPDArray(arr, param);
      assert( sizePPDArray( arr ) == (size_t)(i + 1) );
      assert( equalParameter( parameterPPDArray( arr, i ), param ) );
    }
  }
  freeArrayPPDArray( array );
}
int main() {
  testPPDParameterDef();
  testPPDParameter();
  testInt64();
  testArrays();
  // This should pass valgrind with no leaks :)
}
