/*
  CMPUT201W20 Final Exam Question 2 (Code)
  
  NAME: Vicky Zhao
  CCID: ziwei11
  STUDENT NUMBER: 1593071
  VERSION: 0.9.0

  Finish this C file to get question2_test working.
  
  Do not add a main function!

  You must create a function myfloat_add() that takes two MyFloat, adds
  them, and returns the result as a MyFloat.
  
  You must create a function myfloat_sub() that takes two MyFloat,
  subtracts them, and returns the result as a MyFloat. It's easiest to
  just flip the sign of the second argument, and then call your own
  myfloat_add to do this.
  
  You must create a function myfloat_mul() that takes two MyFloat,
  multiplies them, and returns the result as a MyFloat.
  
  You must create a function myfloat_inv() that takes a MyFloat,
  and returns its reciprocal (1/x).
  
  You must create a function myfloat_div() that takes two MyFloat,
  divides them, and returns the result as a MyFloat.
  It's easiest to just call your own code and multiply the first
  argument by the reciprocal of the second argument.
    
 */
#include "myfloat.h"
#include "myfloat_ops.h"
#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


#define DOUBLE_SIGN_BITS 1UL
#define DOUBLE_EXPONENT_BITS 11UL
#define DOUBLE_MANTISSA_BITS 52UL
#define DOUBLE_MYFLOAT_BITS 64UL
#define DOUBLE_BIAS 1023UL
#define MOVE (DOUBLE_MANTISSA_BITS - MANTISSA_BITS)

/*  */

// a struct to show every bit of double type
struct doubleparts{
    unsigned long long int mantissa : DOUBLE_MANTISSA_BITS;
    unsigned long int exponent : DOUBLE_EXPONENT_BITS;
    unsigned long int sign : DOUBLE_SIGN_BITS;
};

typedef struct doubleparts Parts;

// type pun
union double_type{
    double double_number;
    Parts parts;
};

typedef union double_type DoubleType;


MyFloat myfloat_add(MyFloat myfloat_one, MyFloat myfloat_two){
    // create two DoubleType
    DoubleType new_myfloat_one;
    DoubleType new_myfloat_two;
    // we set these two DoubleType as we want
    new_myfloat_one.parts.sign = myfloat_one.sign;
    // DOUBLE_BIAS is the bias of double
    new_myfloat_one.parts.exponent = myfloat_exponent(myfloat_one) + DOUBLE_BIAS;
    if ((int)myfloat_one.exponent == 0){
        new_myfloat_one.parts.exponent = 0;
    }
    // move left to get the new mantissa
    new_myfloat_one.parts.mantissa = (unsigned long long int)(myfloat_one.mantissa) << MOVE;
    new_myfloat_two.parts.sign = myfloat_two.sign;
    new_myfloat_two.parts.exponent = myfloat_exponent(myfloat_two) + DOUBLE_BIAS;
    if ((int)myfloat_two.exponent == 0){
        new_myfloat_two.parts.exponent = 0;
    }
    new_myfloat_two.parts.mantissa = (unsigned long long int)(myfloat_two.mantissa) << MOVE;
    // a new DoubleType in order to store the result
    DoubleType my_new_float;
    my_new_float.double_number = new_myfloat_one.double_number + new_myfloat_two.double_number;
    MyFloat new_myfloat;
    // change DoubleType to MyFloat
    new_myfloat.sign = my_new_float.parts.sign;
    myfloat_set_exponent(&new_myfloat, (int)(my_new_float.parts.exponent - DOUBLE_BIAS));
    if ((int)my_new_float.parts.exponent == 0){
        myfloat_set_exponent(&new_myfloat, INT_MIN);
    }
    new_myfloat.mantissa = my_new_float.parts.mantissa >> MOVE;
    // return the result
    return new_myfloat;
}


MyFloat myfloat_sub(MyFloat myfloat_one, MyFloat myfloat_two){
    // change the sign 
    if ((int)myfloat_two.sign == 0){
        myfloat_two.sign = (unsigned int)1;
    }
    else if ((int)myfloat_two.sign == 1){
        myfloat_two.sign = (unsigned int)0;
    }
    // use add function
    return myfloat_add(myfloat_one, myfloat_two);
}


MyFloat myfloat_mul(MyFloat myfloat_one, MyFloat myfloat_two){
    // create two DoubleType
    DoubleType new_myfloat_one;
    DoubleType new_myfloat_two;
    // we set these two DoubleType as we want
    new_myfloat_one.parts.sign = myfloat_one.sign;
    // DOUBLE_BIAS is the bias of double
    new_myfloat_one.parts.exponent = myfloat_exponent(myfloat_one) + DOUBLE_BIAS;
    if ((int)myfloat_one.exponent == 0){
        new_myfloat_one.parts.exponent = 0;
    }
    // move left to get the new mantissa
    new_myfloat_one.parts.mantissa = (unsigned long long int)(myfloat_one.mantissa) << MOVE;
    new_myfloat_two.parts.sign = myfloat_two.sign;
    new_myfloat_two.parts.exponent = myfloat_exponent(myfloat_two) + DOUBLE_BIAS;
    if ((int)myfloat_two.exponent == 0){
        new_myfloat_two.parts.exponent = 0;
    }
    new_myfloat_two.parts.mantissa = (unsigned long long int)(myfloat_two.mantissa) << MOVE;
    // a new DoubleType in order to store the result
    DoubleType my_new_float;
    my_new_float.double_number = new_myfloat_one.double_number
    * new_myfloat_two.double_number;
    MyFloat new_myfloat;
    // change DoubleType to MyFloat
    new_myfloat.sign = my_new_float.parts.sign;
    myfloat_set_exponent(&new_myfloat, (int)(my_new_float.parts.exponent - DOUBLE_BIAS));
    if ((int)my_new_float.parts.exponent == 0){
        myfloat_set_exponent(&new_myfloat, INT_MIN);
    }
    new_myfloat.mantissa = my_new_float.parts.mantissa >> MOVE;
    // return the result
    return new_myfloat;
}


MyFloat myfloat_inv(MyFloat myfloat){
    DoubleType new_myfloat;
    new_myfloat.parts.sign = myfloat.sign;
    new_myfloat.parts.exponent = myfloat_exponent(myfloat) + DOUBLE_BIAS;
    new_myfloat.parts.mantissa = (unsigned long long int)(myfloat.mantissa) << MOVE;
    DoubleType my_new_float;
    // get 1/x
    my_new_float.double_number = 1 / new_myfloat.double_number;
    MyFloat newmyfloat;
    newmyfloat.sign = my_new_float.parts.sign;
    myfloat_set_exponent(&newmyfloat, (int)(my_new_float.parts.exponent - DOUBLE_BIAS));
    newmyfloat.mantissa = my_new_float.parts.mantissa >> MOVE;
    return newmyfloat;
}


MyFloat myfloat_div(MyFloat myfloat_one, MyFloat myfloat_two){
    // get the reciprocal of myfloat_two
    MyFloat reciprocal = myfloat_inv(myfloat_two);
    // use multiplication
    return myfloat_mul(myfloat_one, reciprocal);
}
