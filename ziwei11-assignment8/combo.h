#include "parameters.h"
#include <stdio.h>
#include <stdlib.h>

# pragma once

struct combo_t;

typedef struct combo_t * Combo;

// Create a Cartesian Product Combo generator
Combo createParameterCombo();
// Add parameter definition to the Combo
void addParameterDefCombo(Combo combo, ParameterDef def);
// Add a parameter of a previous parameter definition to the Combo
size_t addParameterCombo(Combo combo, Parameter param);
// How man parameter definitions are defined in this combo
size_t nParamsCombo(Combo combo);
// a boolean of whether or not there are more product combos to come
// used for terminating while loops
bool hasNextCombo(Combo combo);
// The next product combo as a malloc'd array of parameters of
// nParamsCombo(combo) length
Parameter * nextCombo(Combo combo);
// Free a parameter list created by nextCombo
void freeParamsCombo(Combo combo, Parameter * params);
// Free a cartesian product combo generator
void freeCombo(Combo combo);

