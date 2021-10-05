#include "combo.h"
#include "combo.h" // Make sure the guard works
#include "parameters.h"
#include "parameters.h" // Make sure the guard works
#include "parameters.h" // Make sure it really works!
#include <assert.h>
#include <stdio.h>

// You shouldn't modify this file

// you can use this for debugging
#define PRINT false

static const double temps[] = { 10.0, 22.5, 32.1 };
static const int64_t times[] = { 0, 10, 20 };
static const double trance[] = {
  3.14159265358979323846,
  2.7182818284590452354,
  1.41421356237309504880,
  2.665144142690225188650,
  19.99909997918947576726
};

void comboDriver2Defs(bool print) {
  size_t ntemps = sizeof(temps) / sizeof(temps[0]);
  size_t ntimes = sizeof(times) / sizeof(times[0]);
  Combo combo = createParameterCombo();
  ParameterDef temperature = doubleParameterDef("Temperature");
  ParameterDef recTime     = longParameterDef("RecTime");
  addParameterDefCombo(combo, temperature);
  addParameterDefCombo(combo, recTime);
  for (size_t i = 0; i < ntemps; i++ ) {
    Parameter temp = mkDoubleParameter(temperature, temps[i]);
    addParameterCombo(combo, temp);
  }
  for (size_t i = 0; i < ntimes; i++ ) {
    Parameter time = mkLongParameter(recTime, times[i]);
    addParameterCombo(combo, time);
  }
  const size_t size = nParamsCombo( combo );
  assert(size == 2);
  size_t index = 0;
  while( hasNextCombo(combo) ) {
    Parameter * params = nextCombo(combo);
    //printf("%g",doubleParameter(params[0]));
    //printf("%ld",longParameter(params[1]));
    if (print) {
      printf("%g %ld\n", doubleParameter(params[0]), longParameter(params[1]));
    }
    //printf("%g",doubleParameter(params[0]));
    //printf("%ld",longParameter(params[1]));
    assert(doubleParameter(params[0]) == temps[index / ntemps]);
    assert(longParameter(params[1])   == times[index % ntimes]);    
    freeParamsCombo( combo, params );
    index++;
  }
  freeCombo(combo);
}

void checkCombo3(Combo combo, bool print) {
  size_t ntemps = sizeof(temps) / sizeof(temps[0]);
  size_t ntimes = sizeof(times) / sizeof(times[0]);
  size_t ntrance = sizeof(trance) / sizeof(trance[0]);
  size_t index = 0;
  while( hasNextCombo(combo) ) {
    Parameter * params = nextCombo(combo);
    if (print) {
      printf("%g %ld %g\n",
             doubleParameter(params[0]),
             longParameter(params[1]),
             doubleParameter(params[2]));
    }
    assert(doubleParameter(params[0])   == temps[(index/(ntimes*ntrance)) % ntemps]);    
    assert(longParameter(params[1])   == times[(index/ntrance) % ntimes]);    
    assert(doubleParameter(params[2])   == trance[index % ntrance]);    
    freeParamsCombo( combo, params );
    index++;
  }
}

void comboDriver3Defs(bool print) {
  size_t ntemps = sizeof(temps) / sizeof(temps[0]);
  size_t ntimes = sizeof(times) / sizeof(times[0]);
  size_t ntrance = sizeof(trance) / sizeof(trance[0]);
  Combo combo = createParameterCombo();
  ParameterDef temperature = doubleParameterDef("Temperature");
  ParameterDef recTime     = longParameterDef("RecTime");
  ParameterDef transcend    = doubleParameterDef("Transcend");
  addParameterDefCombo(combo, temperature);
  addParameterDefCombo(combo, recTime);
  addParameterDefCombo(combo, transcend);
  for (size_t i = 0; i < ntemps; i++ ) {
    Parameter temp = mkDoubleParameter(temperature, temps[i]);
    addParameterCombo(combo, temp);
  }
  for (size_t i = 0; i < ntimes; i++ ) {
    Parameter time = mkLongParameter(recTime, times[i]);
    addParameterCombo(combo, time);
  }
  for (size_t i = 0; i < ntrance; i++ ) {
    Parameter trans = mkDoubleParameter(transcend, trance[i]);
    addParameterCombo(combo, trans);
  }
  const size_t size = nParamsCombo( combo );
  assert(size == 3);
  checkCombo3( combo, print );
  freeCombo(combo);
}


void checkCombo4(Combo combo, bool print) {
  size_t ntemps = sizeof(temps) / sizeof(temps[0]);
  size_t ntimes = sizeof(times) / sizeof(times[0]);
  size_t index = 0;
  while( hasNextCombo(combo) ) {
    Parameter * params = nextCombo(combo);
    if (print) {
      printf("%g %ld %ld %ld\n",
             doubleParameter(params[0]),
             longParameter(params[1]),
             longParameter(params[2]),
             longParameter(params[3]));
    }
    
    assert(doubleParameter(params[0])   == temps[(index/(ntimes*ntimes*ntimes)) % ntemps]);    
    assert(longParameter(params[1])   == times[(index/(ntimes*ntimes)) % ntimes]);    
    assert(longParameter(params[2])   == times[(index/ntimes) % ntimes]);    
    assert(longParameter(params[3])   == times[index % ntimes]);    
    freeParamsCombo( combo, params );
    index++;
  }
}


void comboDriver4Defs(bool print) {
  size_t ntemps = sizeof(temps) / sizeof(temps[0]);
  size_t ntimes = sizeof(times) / sizeof(times[0]);
  Combo combo = createParameterCombo();
  ParameterDef temperature = doubleParameterDef("Temperature");
  ParameterDef recTime     = doubleParameterDef("RecTime");
  ParameterDef recTime2     = doubleParameterDef("RecTime2");
  ParameterDef recTime3     = doubleParameterDef("RecTime3");

  addParameterDefCombo(combo, temperature);
  addParameterDefCombo(combo, recTime);
  addParameterDefCombo(combo, recTime2);
  addParameterDefCombo(combo, recTime3);
  for (size_t i = 0; i < ntemps; i++ ) {
    Parameter temp = mkDoubleParameter(temperature, temps[i]);
    addParameterCombo(combo, temp);
  }
  for (size_t i = 0; i < ntimes; i++ ) {
    Parameter time = mkLongParameter(recTime, times[i]);
    addParameterCombo(combo, time);
  }
  for (size_t i = 0; i < ntimes; i++ ) {
    Parameter time = mkLongParameter(recTime2, times[i % ntimes]);
    addParameterCombo(combo, time);
  }
  for (size_t i = 0; i < ntimes; i++ ) {
    Parameter time = mkLongParameter(recTime3, times[i % ntimes]);
    addParameterCombo(combo, time);
  }
  const size_t size = nParamsCombo( combo );
  assert(size == 4);
  checkCombo4( combo, print);
  freeCombo(combo);
}

int main() {
  comboDriver2Defs(PRINT);
  //comboDriver3Defs(PRINT);
  //comboDriver4Defs(PRINT);
}
