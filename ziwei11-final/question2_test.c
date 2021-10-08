/*
  CMPUT201W20 Final Question 2 TEST DRIVER for ziwei11
  
  DO NOT CHANGE THIS FILE!
  
  DO NOT EDIT THIS FILE!
  
  DO NOT MODIFY THIS FILE!
  
   VERSION: 0.9.0
*/

#include "myfloat_ops.h"
#include "test.h"
#include <limits.h>

#ifndef LOGFILE
#define LOGFILE "question2_test.log"
#endif

int main() {
    setup(LOGFILE);
    
    MyFloat one = myfloat_one();
    MyFloat two = myfloat_add(one, one);
    ASSERT_INT_EQUAL(myfloat_negative(two), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(two), 1);
    ASSERT_INT_EQUAL(myfloat_mantissa(two), 1 << MANTISSA_BITS);

    MyFloat four = myfloat_add(two, two);
    ASSERT_INT_EQUAL(myfloat_negative(four), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(four), 2);
    ASSERT_INT_EQUAL(myfloat_mantissa(four), 1 << MANTISSA_BITS);

    MyFloat three = myfloat_sub(four, one);
    ASSERT_INT_EQUAL(myfloat_negative(three), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(three), 1);
    ASSERT_INT_EQUAL(myfloat_mantissa(three), 3 << (MANTISSA_BITS-1));
    
    MyFloat n1 = myfloat_sub(one, two);
    ASSERT_INT_EQUAL(myfloat_negative(n1), 1);
    ASSERT_INT_EQUAL(myfloat_exponent(n1), 0);
    ASSERT_INT_EQUAL(myfloat_mantissa(n1), 1 << MANTISSA_BITS);
    
    MyFloat six = myfloat_mul(two, three);
    ASSERT_INT_EQUAL(myfloat_negative(six), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(six), 2);
    ASSERT_INT_EQUAL(myfloat_mantissa(six), 3 << (MANTISSA_BITS-1));
    
    MyFloat eight = myfloat_mul(two, four);
    ASSERT_INT_EQUAL(myfloat_negative(eight), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(eight), 3);
    ASSERT_INT_EQUAL(myfloat_mantissa(eight), 1 << MANTISSA_BITS);
    
    MyFloat zero = myfloat_add(one, n1);
    // Don't care about negative zero
    ASSERT_INT_EQUAL(myfloat_exponent(zero), INT_MIN);
    ASSERT_INT_EQUAL(myfloat_mantissa(zero), 0);
    
    MyFloat zero2 = myfloat_mul(one, zero);
    // Don't care about negative zero
    ASSERT_INT_EQUAL(myfloat_exponent(zero2), INT_MIN);
    ASSERT_INT_EQUAL(myfloat_mantissa(zero2), 0);
    
    MyFloat ntwo = myfloat_mul(n1, two);
    ASSERT_INT_EQUAL(myfloat_negative(ntwo), 1);
    ASSERT_INT_EQUAL(myfloat_exponent(ntwo), 1);
    ASSERT_INT_EQUAL(myfloat_mantissa(ntwo), 1 << MANTISSA_BITS);

    MyFloat four2 = myfloat_mul(ntwo, ntwo);
    ASSERT_INT_EQUAL(myfloat_negative(four2), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(four2), 2);
    ASSERT_INT_EQUAL(myfloat_mantissa(four2), 1 << MANTISSA_BITS);

    MyFloat four3 = myfloat_sub(two, ntwo);
    ASSERT_INT_EQUAL(myfloat_negative(four3), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(four3), 2);
    ASSERT_INT_EQUAL(myfloat_mantissa(four3), 1 << MANTISSA_BITS);

    MyFloat one2 = myfloat_inv(one);
    ASSERT_INT_EQUAL(myfloat_negative(one2), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(one2), 0);
    ASSERT_INT_EQUAL(myfloat_mantissa(one2), 1 << MANTISSA_BITS);

    MyFloat half = myfloat_inv(two);
    ASSERT_INT_EQUAL(myfloat_negative(half), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(half), -1);
    ASSERT_INT_EQUAL(myfloat_mantissa(half), 1 << MANTISSA_BITS);

    MyFloat one3 = myfloat_mul(two, half);
    ASSERT_INT_EQUAL(myfloat_negative(one3), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(one3), 0);
    ASSERT_INT_EQUAL(myfloat_mantissa(one3), 1 << MANTISSA_BITS);

    MyFloat one4 = myfloat_div(four, four);
    ASSERT_INT_EQUAL(myfloat_negative(one4), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(one4), 0);
    ASSERT_INT_EQUAL(myfloat_mantissa(one4), 1 << MANTISSA_BITS);

    MyFloat two2 = myfloat_mul(two, one);
    ASSERT_INT_EQUAL(myfloat_negative(two2), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(two2), 1);
    ASSERT_INT_EQUAL(myfloat_mantissa(two2), 1 << MANTISSA_BITS);

    MyFloat two3 = myfloat_div(one, half);
    ASSERT_INT_EQUAL(myfloat_negative(two3), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(two3), 1);
    ASSERT_INT_EQUAL(myfloat_mantissa(two3), 1 << MANTISSA_BITS);
    
    MyFloat fourth = myfloat_div(one, four);
    ASSERT_INT_EQUAL(myfloat_negative(fourth), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(fourth), -2);
    ASSERT_INT_EQUAL(myfloat_mantissa(fourth), 1 << MANTISSA_BITS);

    MyFloat third = myfloat_div(one, three);
    ASSERT_INT_EQUAL(myfloat_negative(third), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(third), -2);
    // 1/3 should be binary 0.01010101010101...
    // in hex that's zero point 0x55555555
    ASSERT_INT_CLOSE(myfloat_mantissa(third), 0x55555555 >> (30 - MANTISSA_BITS));

    MyFloat seven = myfloat_add(eight, n1);
    ASSERT_INT_EQUAL(myfloat_negative(seven), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(seven), 2);
    ASSERT_INT_EQUAL(myfloat_mantissa(seven), 7 << (MANTISSA_BITS-2) );

    MyFloat ten = myfloat_add(six, four);
    ASSERT_INT_EQUAL(myfloat_negative(ten), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(ten), 3);
    ASSERT_INT_EQUAL(myfloat_mantissa(ten), 10 << (MANTISSA_BITS-3) );
    
    MyFloat p17 = myfloat_add(seven, ten);
    ASSERT_INT_EQUAL(myfloat_negative(p17), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(p17), 4);
    ASSERT_INT_EQUAL(myfloat_mantissa(p17), 17 << (MANTISSA_BITS-4) );

    MyFloat p170 = myfloat_mul(p17, ten);
    ASSERT_INT_EQUAL(myfloat_negative(p170), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(p170), 7);
    ASSERT_INT_EQUAL(myfloat_mantissa(p170), 170 << (MANTISSA_BITS-7) );

    MyFloat p177 = myfloat_add(p170, seven);
    ASSERT_INT_EQUAL(myfloat_negative(p177), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(p177), 7);
    ASSERT_INT_EQUAL(myfloat_mantissa(p177), 177 << (MANTISSA_BITS-7) );

    MyFloat p49 = myfloat_mul(seven, seven);
    ASSERT_INT_EQUAL(myfloat_negative(p49), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(p49), 5);
    ASSERT_INT_EQUAL(myfloat_mantissa(p49), 49 << (MANTISSA_BITS-5) );
    
    MyFloat p45 = myfloat_sub(p49, four);
    ASSERT_INT_EQUAL(myfloat_negative(p45), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(p45), 5);
    ASSERT_INT_EQUAL(myfloat_mantissa(p45), 45 << (MANTISSA_BITS-5) );

    MyFloat d0219 = p45;
    myfloat_set_exponent(&d0219, -6);
    ASSERT_INT_EQUAL(myfloat_negative(d0219), 0);
    ASSERT_INT_EQUAL(myfloat_exponent(d0219), -6);
    ASSERT_INT_EQUAL(myfloat_mantissa(d0219), 45 << (MANTISSA_BITS-5) );
    
    MyFloat sqrt2 = myfloat_zero();
    myfloat_set_negative(&sqrt2, 0U);
    myfloat_set_exponent(&sqrt2, 0U);
    myfloat_set_mantissa(&sqrt2, 2965821U);
    MyFloat sqrt2_squared = myfloat_mul(sqrt2, sqrt2);    ASSERT_INT_EQUAL(myfloat_negative(sqrt2_squared), 0U);
    if (myfloat_exponent(sqrt2_squared) == 1) {
        ASSERT_INT_EQUAL(myfloat_exponent(sqrt2_squared), 1U);
        ASSERT_INT_CLOSE(myfloat_mantissa(sqrt2_squared), 2097152U);
        ASSERT_BYTES_CLOSE(sqrt2_squared, 0x40000000U);
    } else {
        ASSERT_INT_EQUAL(myfloat_exponent(sqrt2_squared), 0U);
        ASSERT_INT_CLOSE(myfloat_mantissa(sqrt2_squared), 4194303U);
        ASSERT_BYTES_CLOSE(sqrt2_squared, 0x40000000U);
    }
    
    MyFloat pi = myfloat_zero();
    myfloat_set_negative(&pi, 0U);
    myfloat_set_exponent(&pi, 1U);
    myfloat_set_mantissa(&pi, 3294199U);
    MyFloat euc = myfloat_zero();
    myfloat_set_negative(&euc, 0U);
    myfloat_set_exponent(&euc, 1U);
    myfloat_set_mantissa(&euc, 2850325U);
    MyFloat pi_euc = myfloat_mul(pi, euc);    ASSERT_INT_EQUAL(myfloat_negative(pi_euc), 0U);
    ASSERT_INT_EQUAL(myfloat_exponent(pi_euc), 3U);
    ASSERT_INT_CLOSE(myfloat_mantissa(pi_euc), 2238640U);
    ASSERT_BYTES_CLOSE(pi_euc, 0x404228b0U);
    
    {
        MyFloat p64 = myfloat_zero();
        myfloat_set_negative(&p64, 0U);
        myfloat_set_exponent(&p64, 6U);
        myfloat_set_mantissa(&p64, 2097152U);
        MyFloat r64 = myfloat_zero();
        myfloat_set_negative(&r64, 0U);
        myfloat_set_exponent(&r64, -6U);
        myfloat_set_mantissa(&r64, 2097152U);
        MyFloat p64_over_r64 = myfloat_div(p64, r64);        ASSERT_INT_EQUAL(myfloat_negative(p64_over_r64), 0U);
        if (myfloat_exponent(p64_over_r64) == 12) {
            ASSERT_INT_EQUAL(myfloat_exponent(p64_over_r64), 12U);
            ASSERT_INT_CLOSE(myfloat_mantissa(p64_over_r64), 2097152U);
            ASSERT_BYTES_CLOSE(p64_over_r64, 0x41600000U);
        } else {
            ASSERT_INT_EQUAL(myfloat_exponent(p64_over_r64), 11U);
            ASSERT_INT_CLOSE(myfloat_mantissa(p64_over_r64), 4194303U);
            ASSERT_BYTES_CLOSE(p64_over_r64, 0x41600000U);
        }
    }
    
    {
        MyFloat one = myfloat_zero();
        myfloat_set_negative(&one, 0U);
        myfloat_set_exponent(&one, 0U);
        myfloat_set_mantissa(&one, 2097152U);
        MyFloat three = myfloat_zero();
        myfloat_set_negative(&three, 0U);
        myfloat_set_exponent(&three, 1U);
        myfloat_set_mantissa(&three, 3145728U);
        MyFloat one_over_three = myfloat_div(one, three);        ASSERT_INT_EQUAL(myfloat_negative(one_over_three), 0U);
        ASSERT_INT_EQUAL(myfloat_exponent(one_over_three), -2U);
        ASSERT_INT_CLOSE(myfloat_mantissa(one_over_three), 2796203U);
        ASSERT_BYTES_CLOSE(one_over_three, 0x3faaaaabU);
    }
    
    {
        MyFloat one = myfloat_zero();
        myfloat_set_negative(&one, 0U);
        myfloat_set_exponent(&one, 0U);
        myfloat_set_mantissa(&one, 2097152U);
        MyFloat five = myfloat_zero();
        myfloat_set_negative(&five, 0U);
        myfloat_set_exponent(&five, 2U);
        myfloat_set_mantissa(&five, 2621440U);
        MyFloat one_over_five = myfloat_div(one, five);        ASSERT_INT_EQUAL(myfloat_negative(one_over_five), 0U);
        ASSERT_INT_EQUAL(myfloat_exponent(one_over_five), -3U);
        ASSERT_INT_CLOSE(myfloat_mantissa(one_over_five), 3355443U);
        ASSERT_BYTES_CLOSE(one_over_five, 0x3f933333U);
    }

    teardown(LOGFILE);
}


