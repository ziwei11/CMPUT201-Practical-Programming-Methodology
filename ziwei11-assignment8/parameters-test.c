#include "parameters.h"
#include <assert.h>
#include <string.h>
#define LPARAM 1000
#define CPARAM 'x'

void testDoubles() {
    const double DPARAM = 1.1;
    ParameterDef ddef = doubleParameterDef( "DDEF"   );
    Parameter  dParam = mkDoubleParameter( ddef, DPARAM   );
    assert(doubleParameter(dParam) == DPARAM);
    assert(typeParameter(dParam) == DOUBLE);
    assert(equalParameterDef(ddef, ddef));
    assert(!equalParameterDef(ddef, longParameterDef("LDEF")));
    assert(!equalParameterDef(ddef, stringParameterDef("SDEF")));
}

void testString() {
    ParameterDef sdef = stringParameterDef( "SDEF"   );
    char * SPARAM = "SUP!";
    Parameter  sParam = mkStringParameter( sdef, SPARAM);
    assert(strcmp( SPARAM, stringParameter(sParam)) == 0);
    assert(typeParameter(sParam) == STRING);
    assert(equalParameterDef(sdef, stringParameterDef( "SDEF"   )));
}

int main() {
    testDoubles();
    testString();
    ParameterDef ldef  = longParameterDef(   "LDEF"   );
    ParameterDef ldef2 = longParameterDef(   "LDEF"   );
    ParameterDef ldef3 = charParameterDef(   "LDEF"   );
    ParameterDef cdef = charParameterDef(   "CDEF"   );
    Parameter  lParam = mkLongParameter(   ldef, LPARAM  );
    Parameter  cParam = mkCharParameter(   cdef, CPARAM );
    assert(longParameter(lParam)   == LPARAM);
    assert(charParameter(cParam)   == CPARAM);
    assert(typeParameter(lParam) == LONG);
    assert(typeParameter(cParam) == CHAR);
    assert(equalParameterDef( ldef, ldef ));
    assert(equalParameterDef( ldef, ldef2 ));
    assert(!equalParameterDef( ldef, ldef3 ));
    assert(!equalParameterDef( ldef, cdef ));
}
