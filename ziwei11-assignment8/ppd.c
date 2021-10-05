#include "parameters.h"
#include "ppd.h"
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

// A growing array implementation

PPDArray createPPDArray() {
    PPDArray array = malloc(sizeof(struct ppd_array));
    array->params = NULL;
    array->size = 0;
    return array;
}

size_t sizePPDArray(PPDArray array) {
    return array->size;
}

void freePPDArray(PPDArray array) {
    if(array->params != NULL) {
        free(array->params);
    }
    free(array);
}

void freeArrayPPDArray(PPDArray array) {
    if(array->params != NULL) {
        for(size_t i = 0; i <= array->size - 1; i++){
            freePPDArray(array->params[i].array);
        }
        free(array->params);
        free(array);
    }
}

ParameterDef parameterDefPPDArray(PPDArray array, size_t index) {
  assert(index < array->size);
  return array->params[index].def;
}

ParameterDef * parameterDefRefPPDArray(PPDArray array, size_t index) {
  assert(index < array->size);
  return &(array->params[index].def);
}


Parameter parameterPPDArray(PPDArray array, size_t index) {
  assert(index < array->size);
  return array->params[index].param;
}

PPDArray arrayPPDArray(PPDArray array, size_t index) {
  assert(index < array->size);
  return array->params[index].array;
}

void addPPDPPDArray(PPDArray array, PPD defOrParam) {
    assert(array != NULL);
    size_t nsize = array->size;
    array->params = realloc(array->params, (nsize + 1) * sizeof(PPD));
    assert(array->params != NULL);
    array->params[array->size] = defOrParam;
    array->size++;
}

void addDefPPDArray(PPDArray array, ParameterDef def) {
  addPPDPPDArray(array, (PPD){.def=def});
}

void addParamPPDArray(PPDArray array, Parameter param) {
  addPPDPPDArray(array, (PPD){.param=param});
}

void addPPDArrayPPDArray(PPDArray array, PPDArray newArray  ) {
  addPPDPPDArray(array, (PPD){.array=newArray});
}

void addInt64PPDArray(PPDArray array, int64_t int64  ) {
  addPPDPPDArray(array, (PPD){.int64=int64});
}

void addStringPPDArray(PPDArray array, char * str ) {
  addPPDPPDArray(array, (PPD){.str=str});
}

int64_t int64PPDArray(PPDArray array, size_t index) {
  assert(index < array->size);
  return array->params[index].int64;
}
char * stringPPDArray(PPDArray array, size_t index) {
  assert(index < array->size);
  return array->params[index].str;
}

void setInt64PPDArray(PPDArray array, size_t index, int64_t value) {
  assert(index < array->size);
  array->params[index].int64 = value;
}


