#include "parameters.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Implement all of the parameter.h functions
ParameterDef mkParameterDef( char * name, TypeFlag flag ) {
    ParameterDef def;
    def.name = name;
    def.type = flag;
    return def;
}

ParameterDef doubleParameterDef(char * name) {
    ParameterDef def;
    def.name = name;
    def.type = DOUBLE;
    return def;
}

ParameterDef longParameterDef(char * name) {
    ParameterDef def;
    def.name = name;
    def.type = LONG;
    return def;
}

ParameterDef stringParameterDef(char * name) {
    ParameterDef def;
    def.name = name;
    def.type = STRING;
    return def;
}

ParameterDef charParameterDef(char * name) {
    ParameterDef def;
    def.name = name;
    def.type = CHAR;
    return def;
}

Parameter mkDoubleParameter(ParameterDef def, double value) {
    Parameter param;
    param.def = def;
    param.any.aDouble = value;
    return param;
}

Parameter mkLongParameter(ParameterDef def, long value) {
    Parameter param;
    param.def = def;
    param.any.aLong = value;
    return param;
}

Parameter mkStringParameter(ParameterDef def, char * value) {
    Parameter param;
    param.def = def;
    param.any.aString = value;
    return param;
}

Parameter mkCharParameter(ParameterDef def, char value) {
    Parameter param;
    param.def = def;
    param.any.aChar = value;
    return param;
}

TypeFlag typeParameter(Parameter param) {
    ParameterDef deff = param.def;
    return deff.type;
}

double doubleParameter(Parameter param) {
    return param.any.aDouble;
}

long longParameter(Parameter param) {
    return param.any.aLong;
}

char * stringParameter(Parameter param) {
    return param.any.aString;
}

char charParameter(Parameter param) {
    return param.any.aChar;
}

char * nameParameter(Parameter param) {
    ParameterDef deff = param.def;
    return deff.name;
}

bool equalParameterDef(ParameterDef param1, ParameterDef param2) {
    return (param1.name == param2.name) && (param1.type == param2.type);
}

bool equalParameter(Parameter param1, Parameter param2) {
  return ((param1.def.name == param2.def.name) &&
    (param1.def.type == param2.def.type) &&
    ((param1.any.aDouble == param2.any.aDouble) ||
     (param1.any.aLong == param2.any.aLong) ||
     (param1.any.aString == param2.any.aString) ||
     (param1.any.aChar == param2.any.aChar)));
}

void printParam(Parameter param) {
  TypeFlag type = param.def.type;
  switch((int)type) {
  case LONG:
    printf("%ld", param.any.aLong);
    break;
  case STRING:
    printf("%s", param.any.aString);
    break;
  case CHAR:
    printf("%c", param.any.aChar);
    break;
  case DOUBLE:
    printf("%g", param.any.aDouble);
    break;
  default:
    abort();
    break;
  }
}

void printParams(Parameter * params, size_t size) {
  for (size_t i = 0 ; i < size; i ++) {
    printParam(params[i]);
    printf(" ");
  }
  puts("");
}
