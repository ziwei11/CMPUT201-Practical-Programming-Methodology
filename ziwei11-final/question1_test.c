/*
  CMPUT201W20 Final Question 1 TEST DRIVER for ziwei11
  
  DO NOT CHANGE THIS FILE!
  
  DO NOT EDIT THIS FILE!
  
  DO NOT MODIFY THIS FILE!
  
   VERSION: 0.9.0
*/

#include "myfloat.h"
#include "myfloat.h"
#include "test.h"
#include <limits.h>
#define Q1LOG "question1_test.log"

int main() {
    setup(Q1LOG);
    
    ASSERT_INT_EQUAL(SIGN_BITS, 1UL);
    ASSERT_INT_EQUAL(EXPONENT_BITS, 10UL);
    ASSERT_INT_EQUAL(MANTISSA_BITS, 21UL);
    ASSERT_INT_EQUAL(MYFLOAT_BITS, 32UL);
    ASSERT_INT_EQUAL(MYFLOAT_BYTES, 4);
    
    ASSERT_INT_EQUAL(sizeof(MyFloat), 4);
    
    MyFloat pzero = myfloat_zero();
    ASSERT_INT_EQUAL(myfloat_negative(pzero), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(pzero), INT_MIN);
    ASSERT_INT_EQUAL(myfloat_mantissa(pzero), 0);
    ASSERT_BYTES_EQUAL(pzero, 0x00000000U);
    
    MyFloat nzero = pzero;
    myfloat_set_negative(&nzero, 1);
    ASSERT_INT_EQUAL(myfloat_negative(nzero), 1);
    ASSERT_INT_EQUAL(myfloat_exponent(nzero), INT_MIN);
    ASSERT_INT_EQUAL(myfloat_mantissa(nzero), 0);
    ASSERT_BYTES_EQUAL(nzero, 0x80000000U);
   
    MyFloat pone = myfloat_one();
    ASSERT_INT_EQUAL(myfloat_negative(pone), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(pone), 0);
    ASSERT_INT_EQUAL(myfloat_mantissa(pone), 1 << MANTISSA_BITS);
    ASSERT_BYTES_EQUAL(pone, 0x3fe00000U);
    
    MyFloat none = pone;
    myfloat_set_negative(&none, 1);
    ASSERT_INT_EQUAL(myfloat_negative(none), 1);
    ASSERT_INT_EQUAL(myfloat_exponent(none), 0);
    ASSERT_INT_EQUAL(myfloat_mantissa(none), 1 << MANTISSA_BITS);
    ASSERT_BYTES_EQUAL(none, 0xbfe00000U);

    MyFloat pinf = pone;
    myfloat_set_negative(&pinf, 0);
    myfloat_set_exponent(&pinf, INT_MAX);
    myfloat_set_mantissa(&pinf, 0);
    ASSERT_INT_EQUAL(myfloat_negative(pinf), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(pinf), INT_MAX);
    ASSERT_INT_EQUAL(myfloat_mantissa(pinf), 0);
    ASSERT_BYTES_EQUAL(pinf, 0x7fe00000U);

    MyFloat ninf = pinf;
    myfloat_set_negative(&ninf, 1);
    ASSERT_INT_EQUAL(myfloat_negative(ninf), 1);
    ASSERT_INT_EQUAL(myfloat_exponent(ninf), INT_MAX);
    ASSERT_INT_EQUAL(myfloat_mantissa(ninf), 0);
    ASSERT_BYTES_EQUAL(ninf, 0xffe00000U);
    
    MyFloat ptwo = pone;
    myfloat_set_exponent(&ptwo, 1);
    ASSERT_INT_EQUAL(myfloat_negative(ptwo), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(ptwo), 1);
    ASSERT_INT_EQUAL(myfloat_mantissa(ptwo), 1 << MANTISSA_BITS);
    ASSERT_BYTES_EQUAL(ptwo, 0x40000000U);
    
    MyFloat n4 = myfloat_zero();
    myfloat_set_negative(&n4, 1U);
    myfloat_set_exponent(&n4, 2U);
    myfloat_set_mantissa(&n4, 2097152U);
    ASSERT_INT_EQUAL(myfloat_negative(n4), 1U);
    ASSERT_INT_EQUAL(myfloat_exponent(n4), 2U);
    ASSERT_INT_EQUAL(myfloat_mantissa(n4), 2097152U);
    ASSERT_BYTES_EQUAL(n4, 0xc0200000U);
    
    MyFloat p8 = myfloat_zero();
    myfloat_set_negative(&p8, 0U);
    myfloat_set_exponent(&p8, 3U);
    myfloat_set_mantissa(&p8, 2097152U);
    ASSERT_INT_EQUAL(myfloat_negative(p8), 0U);
    ASSERT_INT_EQUAL(myfloat_exponent(p8), 3U);
    ASSERT_INT_EQUAL(myfloat_mantissa(p8), 2097152U);
    ASSERT_BYTES_EQUAL(p8, 0x40400000U);
    
    MyFloat n16 = myfloat_zero();
    myfloat_set_negative(&n16, 1U);
    myfloat_set_exponent(&n16, 4U);
    myfloat_set_mantissa(&n16, 2097152U);
    ASSERT_INT_EQUAL(myfloat_negative(n16), 1U);
    ASSERT_INT_EQUAL(myfloat_exponent(n16), 4U);
    ASSERT_INT_EQUAL(myfloat_mantissa(n16), 2097152U);
    ASSERT_BYTES_EQUAL(n16, 0xc0600000U);
    
    MyFloat p32 = myfloat_zero();
    myfloat_set_negative(&p32, 0U);
    myfloat_set_exponent(&p32, 5U);
    myfloat_set_mantissa(&p32, 2097152U);
    ASSERT_INT_EQUAL(myfloat_negative(p32), 0U);
    ASSERT_INT_EQUAL(myfloat_exponent(p32), 5U);
    ASSERT_INT_EQUAL(myfloat_mantissa(p32), 2097152U);
    ASSERT_BYTES_EQUAL(p32, 0x40800000U);
    
    MyFloat n64 = myfloat_zero();
    myfloat_set_negative(&n64, 1U);
    myfloat_set_exponent(&n64, 6U);
    myfloat_set_mantissa(&n64, 2097152U);
    ASSERT_INT_EQUAL(myfloat_negative(n64), 1U);
    ASSERT_INT_EQUAL(myfloat_exponent(n64), 6U);
    ASSERT_INT_EQUAL(myfloat_mantissa(n64), 2097152U);
    ASSERT_BYTES_EQUAL(n64, 0xc0a00000U);
    
    MyFloat r4 = myfloat_zero();
    myfloat_set_negative(&r4, 0U);
    myfloat_set_exponent(&r4, -2U);
    myfloat_set_mantissa(&r4, 2097152U);
    ASSERT_INT_EQUAL(myfloat_negative(r4), 0U);
    ASSERT_INT_EQUAL(myfloat_exponent(r4), -2U);
    ASSERT_INT_EQUAL(myfloat_mantissa(r4), 2097152U);
    ASSERT_BYTES_EQUAL(r4, 0x3fa00000U);
    
    MyFloat r8 = myfloat_zero();
    myfloat_set_negative(&r8, 1U);
    myfloat_set_exponent(&r8, -3U);
    myfloat_set_mantissa(&r8, 2097152U);
    ASSERT_INT_EQUAL(myfloat_negative(r8), 1U);
    ASSERT_INT_EQUAL(myfloat_exponent(r8), -3U);
    ASSERT_INT_EQUAL(myfloat_mantissa(r8), 2097152U);
    ASSERT_BYTES_EQUAL(r8, 0xbf800000U);
    
    MyFloat r16 = myfloat_zero();
    myfloat_set_negative(&r16, 0U);
    myfloat_set_exponent(&r16, -4U);
    myfloat_set_mantissa(&r16, 2097152U);
    ASSERT_INT_EQUAL(myfloat_negative(r16), 0U);
    ASSERT_INT_EQUAL(myfloat_exponent(r16), -4U);
    ASSERT_INT_EQUAL(myfloat_mantissa(r16), 2097152U);
    ASSERT_BYTES_EQUAL(r16, 0x3f600000U);
    
    MyFloat r32 = myfloat_zero();
    myfloat_set_negative(&r32, 1U);
    myfloat_set_exponent(&r32, -5U);
    myfloat_set_mantissa(&r32, 2097152U);
    ASSERT_INT_EQUAL(myfloat_negative(r32), 1U);
    ASSERT_INT_EQUAL(myfloat_exponent(r32), -5U);
    ASSERT_INT_EQUAL(myfloat_mantissa(r32), 2097152U);
    ASSERT_BYTES_EQUAL(r32, 0xbf400000U);
    
    MyFloat r64 = myfloat_zero();
    myfloat_set_negative(&r64, 0U);
    myfloat_set_exponent(&r64, -6U);
    myfloat_set_mantissa(&r64, 2097152U);
    ASSERT_INT_EQUAL(myfloat_negative(r64), 0U);
    ASSERT_INT_EQUAL(myfloat_exponent(r64), -6U);
    ASSERT_INT_EQUAL(myfloat_mantissa(r64), 2097152U);
    ASSERT_BYTES_EQUAL(r64, 0x3f200000U);
    
    MyFloat p10 = myfloat_zero();
    myfloat_set_negative(&p10, 0U);
    myfloat_set_exponent(&p10, 3U);
    myfloat_set_mantissa(&p10, 2621440U);
    ASSERT_INT_EQUAL(myfloat_negative(p10), 0U);
    ASSERT_INT_EQUAL(myfloat_exponent(p10), 3U);
    ASSERT_INT_CLOSE(myfloat_mantissa(p10), 2621440U);
    ASSERT_BYTES_CLOSE(p10, 0x40480000U);
    
    MyFloat r10 = myfloat_zero();
    myfloat_set_negative(&r10, 0U);
    myfloat_set_exponent(&r10, -4U);
    myfloat_set_mantissa(&r10, 3355443U);
    ASSERT_INT_EQUAL(myfloat_negative(r10), 0U);
    ASSERT_INT_EQUAL(myfloat_exponent(r10), -4U);
    ASSERT_INT_CLOSE(myfloat_mantissa(r10), 3355443U);
    ASSERT_BYTES_CLOSE(r10, 0x3f733333U);
    
    MyFloat pi = myfloat_zero();
    myfloat_set_negative(&pi, 0U);
    myfloat_set_exponent(&pi, 1U);
    myfloat_set_mantissa(&pi, 3294199U);
    ASSERT_INT_EQUAL(myfloat_negative(pi), 0U);
    ASSERT_INT_EQUAL(myfloat_exponent(pi), 1U);
    ASSERT_INT_CLOSE(myfloat_mantissa(pi), 3294199U);
    ASSERT_BYTES_CLOSE(pi, 0x401243f7U);
    
    MyFloat rpi = myfloat_zero();
    myfloat_set_negative(&rpi, 0U);
    myfloat_set_exponent(&rpi, -2U);
    myfloat_set_mantissa(&rpi, 2670177U);
    ASSERT_INT_EQUAL(myfloat_negative(rpi), 0U);
    ASSERT_INT_EQUAL(myfloat_exponent(rpi), -2U);
    ASSERT_INT_CLOSE(myfloat_mantissa(rpi), 2670177U);
    ASSERT_BYTES_CLOSE(rpi, 0x3fa8be61U);
    
    MyFloat euc = myfloat_zero();
    myfloat_set_negative(&euc, 0U);
    myfloat_set_exponent(&euc, 1U);
    myfloat_set_mantissa(&euc, 2850325U);
    ASSERT_INT_EQUAL(myfloat_negative(euc), 0U);
    ASSERT_INT_EQUAL(myfloat_exponent(euc), 1U);
    ASSERT_INT_CLOSE(myfloat_mantissa(euc), 2850325U);
    ASSERT_BYTES_CLOSE(euc, 0x400b7e15U);
    
    MyFloat reuc = myfloat_zero();
    myfloat_set_negative(&reuc, 0U);
    myfloat_set_exponent(&reuc, -2U);
    myfloat_set_mantissa(&reuc, 3085996U);
    ASSERT_INT_EQUAL(myfloat_negative(reuc), 0U);
    ASSERT_INT_EQUAL(myfloat_exponent(reuc), -2U);
    ASSERT_INT_CLOSE(myfloat_mantissa(reuc), 3085996U);
    ASSERT_BYTES_CLOSE(reuc, 0x3faf16acU);
    
    teardown(Q1LOG);
}

