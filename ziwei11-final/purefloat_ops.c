/*
  CMPUT201W20 Final Exam Question 4 (Code)
  
  NAME: Vicky Zhao
  CCID: ziwei11
  STUDENT NUMBER: 1593071
  VERSION: 0.9.0

  Finish this C file to get question4_test working.
  
  Do not add a main function!

  In this file you must not call upon the power of C half precision,
  single precision, double precision, or extended precision
  floating point numbers. You
  may not use C IO routines to do math for you. You must implement
  pure floating point addition, subtraction, multiplication,
  reciprocal, and divison by hand for your MyFloat. 

  This file, once compiled can replace myfloat_ops.c. It implements
  myfloat_ops.h.

  You must create a function myfloat_add() that takes two MyFloat, adds
  them, and returns the result as a MyFloat.
  
  You must create a function myfloat_sub() that takes two MyFloat, subtracts them, and returns the result as a MyFloat. 
  It's easiest to just flip the sign of the second argument,
  and then call your own myfloat_add to do this.
  
  You must create a function myfloat_mul() that takes two MyFloat,
  multiplies them, and returns the result as a MyFloat.
  
  You must create a function myfloat_inv() that takes a MyFloat,
  and returns its reciprocal (1/x).
  
  You must create a function myfloat_div() that takes two MyFloat,
  divides them, and returns the result as a MyFloat.
  It's easiest to just call your own code and multiply the first
  argument by the reciprocal of the second argument.
    
 */
#include "myfloat_ops.h"
#include <limits.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*  */


MyFloat myfloat_add(MyFloat myfloat_one, MyFloat myfloat_two){
    int expon_one = myfloat_exponent(myfloat_one);
    int expon_two = myfloat_exponent(myfloat_two);
    int manti_one = myfloat_mantissa(myfloat_one);
    int manti_two = myfloat_mantissa(myfloat_two);
    int sign_one = myfloat_negative(myfloat_one);
    int sign_two = myfloat_negative(myfloat_two);
    MyFloat new = myfloat_zero();
    if ((expon_one <= expon_two) && ((sign_one == 1 && sign_two == 1) || (sign_one == 0 && sign_two == 0))){
        myfloat_set_exponent(&new, expon_two + 1);
        myfloat_set_mantissa(&new,
                             ((manti_one >> (expon_two - expon_one)) + manti_two) >> 1);
        myfloat_set_negative(&new, myfloat_negative(myfloat_two));
    }
    if ((expon_one > expon_two) && ((sign_one == 1 && sign_two == 1) || (sign_one == 0 && sign_two == 0))){
        myfloat_set_exponent(&new, expon_one + 1);
        myfloat_set_mantissa(&new,
                             ((manti_two >> (expon_one - expon_two)) + manti_one) >> 1);
        myfloat_set_negative(&new, myfloat_negative(myfloat_one));
    }
    if ((expon_one > expon_two) && ((sign_one == 1 && sign_two == 0) || (sign_one == 0 && sign_two == 1))){
        myfloat_set_exponent(&new, expon_two);
        myfloat_set_mantissa(&new,
                             (manti_one - (manti_two >> (expon_one - expon_two))) << 1);
        myfloat_set_negative(&new, myfloat_negative(myfloat_one));
    }
    if ((expon_one <= expon_two) && ((sign_one == 1 && sign_two == 0) || (sign_one == 0 && sign_two == 1))){
        myfloat_set_exponent(&new, expon_one);
        myfloat_set_mantissa(&new,
                             (manti_two - (manti_one >> (expon_two - expon_one))) << 1);
        myfloat_set_negative(&new, myfloat_negative(myfloat_two));
    }
    return new;
}

MyFloat myfloat_sub(MyFloat myfloat_one, MyFloat myfloat_two){
    if (myfloat_negative(myfloat_two) == 0){
        myfloat_set_negative(&myfloat_two, 1);
    }
    if (myfloat_negative(myfloat_two) == 1){
        myfloat_set_negative(&myfloat_two, 0);
    }
    return myfloat_add(myfloat_one, myfloat_two);
}

MyFloat myfloat_mul(MyFloat myfloat_one, MyFloat myfloat_two){
    int expon_one = myfloat_exponent(myfloat_one);
    int expon_two = myfloat_exponent(myfloat_two);
    int manti_one = myfloat_mantissa(myfloat_one);
    int manti_two = myfloat_mantissa(myfloat_two);
    int sign_one = myfloat_negative(myfloat_one);
    int sign_two = myfloat_negative(myfloat_two);
    MyFloat new;
    myfloat_set_mantissa(&new, manti_one * manti_two);
    myfloat_set_exponent(&new, expon_one + expon_two + 1);
    if ((sign_one == 1 && sign_two == 1) || (sign_one == 0 && sign_two == 0)){
        myfloat_set_negative(&new, 0);
    }
    else{
        myfloat_set_negative(&new, 1);
    }
    return new;
}

MyFloat myfloat_inv(MyFloat myfloat){
    MyFloat new;
    myfloat_set_exponent(&new, -(myfloat_exponent(myfloat)));
    myfloat_set_negative(&new, myfloat_negative(myfloat));
    myfloat_set_mantissa(&new, myfloat_mantissa(myfloat_one()) / myfloat_mantissa(myfloat));
    return new;
}

MyFloat myfloat_div(MyFloat myfloat_one, MyFloat myfloat_two){
    MyFloat reciprocal = myfloat_inv(myfloat_two);
    return myfloat_mul(myfloat_one, reciprocal);
}
