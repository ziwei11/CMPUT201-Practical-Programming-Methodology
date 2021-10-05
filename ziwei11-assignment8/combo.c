#include "combo.h"
#include "parameters.h"
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

// implement all of combo.h

struct combo_t {
    Parameter ** parameters;
    ParameterDef * parameterdefs;
    int nParams;
    int *lengths;
    int *indexes;
    bool first;
};

/* end:solution*/

Combo createParameterCombo() {
    Combo combo = malloc(sizeof(struct combo_t));
    combo->parameters = malloc(sizeof(Parameter*));
    combo->parameterdefs = malloc(sizeof(ParameterDef));
    combo->nParams = 0;
    combo->lengths = malloc(sizeof(int));
    combo->indexes = malloc(sizeof(int));
    combo->first = true;
    return combo;
}


void addParameterDefCombo(Combo combo, ParameterDef def) {
    combo->nParams = combo->nParams + 1;
    combo->parameterdefs = realloc(combo->parameterdefs,
                                   (combo->nParams) * sizeof(ParameterDef));
    combo->parameters = realloc(combo->parameters,
                                (combo->nParams) * sizeof(Parameter*));
    (combo->parameters)[combo->nParams - 1] =
    (Parameter *)malloc(sizeof(Parameter));
    combo->lengths = realloc(combo->lengths, (combo->nParams) * sizeof(int));
    (combo->lengths)[combo->nParams - 1] = 0;
    combo->indexes = realloc(combo->indexes, (combo->nParams) * sizeof(int));
    (combo->indexes)[combo->nParams - 1] = 0;
    (combo->parameterdefs)[combo->nParams - 1] = def;
}


size_t addParameterCombo(Combo combo, Parameter param) {
    for (int i = 0; i <= combo->nParams - 1; i++){
        if ((((combo->parameterdefs)[i]).name == param.def.name)
            && (((combo->parameterdefs)[i]).type == param.def.type)){
            (combo->lengths)[i] = (combo->lengths)[i] + 1;
            (combo->parameters)[i] = realloc((combo->parameters)[i],
                                             (combo->lengths)[i] * sizeof(Parameter));
            (combo->parameters)[i][(combo->lengths)[i] - 1] = param;
            return (combo->lengths)[i];
        }
    }
    return 0;
}


size_t nParamsCombo(Combo combo) {
    return combo->nParams;
}


bool hasNextCombo(Combo combo) {
    for(int i = 0; i <= combo->nParams - 1; i++){
        if (combo->indexes[i] != combo->lengths[i] - 1){
            return true;
        }
    }
    return false;
}


Parameter * nextCombo(Combo combo) {
    int nParams = nParamsCombo(combo);
    Parameter * ans = NULL;
    if (!hasNextCombo(combo)) {
        return ans;
    }
    ans = (Parameter *)malloc(nParams * sizeof(Parameter));
    if (combo->first){
        combo->first = false;
        for (int i = 0; i <= nParams - 1; ++i) {
            ans[i] = combo->parameters[i][0];
        }
        return ans;
    }
    for (int i = nParams - 1; i >= 0; --i) {
        if (combo->indexes[i] != combo->lengths[i] - 1) {
            combo->indexes[i] += 1;
            break;
        }
        combo->indexes[i] = 0;
    }
    for (int i = nParams - 1; i >= 0; --i) {
        int second = combo->indexes[i];
        ans[i] = combo->parameters[i][second];
    }
    return ans;
}


void freeParamsCombo(Combo combo, Parameter * params) {
  if (combo == NULL) {
    abort();
  }
  free(params);
}


void freeCombo(Combo combo) {
    for (int i = 0; i <= combo->nParams - 1; i++){
        free((combo->parameters)[i]);
    }
    free(combo->parameters);
    free(combo->parameterdefs);
    free(combo->lengths);
    free(combo->indexes);
    free(combo);
}


