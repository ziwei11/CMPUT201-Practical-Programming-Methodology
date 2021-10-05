//#ifndef PPD
//#define PPD

#include "parameters.h"
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>

# pragma once

// forward declaration
union ppd_t;
// This is an array of defs, params, or arrays
// Assume you keep the same sort of values within this array
struct ppd_array {
  union ppd_t * params; // A pointer to an array of ppd_t unions (PPD)
  size_t size;
};
typedef struct ppd_array * PPDArray;

union ppd_t {
  ParameterDef       def;
  Parameter          param;
  struct ppd_array * array;
  int64_t            int64;
  char             * str;
};

typedef union ppd_t PPD;

// create PPDArray
PPDArray createPPDArray();
// get the number of elements in a PPDArray
size_t sizePPDArray(PPDArray array);
// Free a PPD Array
void freePPDArray(PPDArray array);
// Free a PPD Array and all of its PPD Arrays (not recursive)
// Frees an array of arrays, by freeing each contained array
void freeArrayPPDArray(PPDArray array);
// return a parameter def at index of PPDArray array
ParameterDef parameterDefPPDArray(PPDArray array, size_t index);
// return a pointer to parameter def at index of PPDArray array
// pretty unsafe
ParameterDef * parameterDefRefPPDArray(PPDArray array, size_t index);
// return a parameter at index of PPDArray array
Parameter parameterPPDArray(PPDArray array, size_t index);
// return a array at index of PPDArray array
PPDArray arrayPPDArray(PPDArray array, size_t index);
// return an int64 at index of PPDArray array
int64_t int64PPDArray(PPDArray array, size_t index);
// return a string at index of PPDArray array
char * stringPPDArray(PPDArray array, size_t index);
// at index of array set the int64 value to 
void setInt64PPDArray(PPDArray array, size_t index, int64_t value);
// extend PPDArray 1 slot and put this PPD into that slot
// may use realloc!
void addPPDPPDArray(PPDArray array, PPD defOrParam);
// extend PPDArray 1 slot and put this ParameterDef into that slot
// may use realloc!
void addDefPPDArray(PPDArray array, ParameterDef def);
// extend PPDArray 1 slot and put this Parameter into that slot
// may use realloc!
void addParamPPDArray(PPDArray array, Parameter param);
// extend PPDArray 1 slot and put this Array newArray into that slot
// may use realloc!
void addPPDArrayPPDArray(PPDArray array, PPDArray newArray  );
// extend PPDArray 1 slot and put this int64 into that slot
// may use realloc!
void addInt64PPDArray(PPDArray array, int64_t int64  );
// extend PPDArray 1 slot and put this string into that slot
// may use realloc!
void addStringPPDArray(PPDArray array, char * str );

