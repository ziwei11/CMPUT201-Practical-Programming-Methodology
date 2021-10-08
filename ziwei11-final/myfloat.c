/*
  CMPUT201W20 Final Exam Question 1 (Code)
  
  NAME: Vicky Zhao
  CCID: ziwei11
  STUDENT NUMBER: 1593071
  VERSION: 0.9.0

  Finish this C file to get question1_test working.
  
  Do not add a main function!

    You must create a function called myfloat_zero() which returns
    a MyFloat representing 0 (positive 0).
    
    You must create a function called myfloat_one() which returns
    a MyFloat representing 1.0.

    You must create a function called myfloat_negative() that takes a 
    MyFloat and returns an int:
    0 for positive,
    1 for negative.
    
    You must create a function called myfloat_exponent() that takes a
    MyFloat and returns just the exponent, as an int. This should be
    negative if the number is between 1 and -1. For infinity or
    negative infinity, it sould return INT_MAX. For 0.0 or -0.0, it
    should return INT_MIN.

    You must create a function called myfloat_mantissa() that takes a
    MyFloat and returns just the mantissa, as an int. This should be
    always be positive. You must include the implied bit.
    For 0.0, -0.0, infinity, or negative infinity, it should return 0.

    You must create a function called myfloat_set_negative() which:
    takes a POINTER to a MyFloat and an int,
    and changes ONLY the sign to match the value of the of the int.
    0 for positive,
    1 for negative.
    It must set the sign of the MyFloat being pointed to positive
    or negative as specified by the second argument.
    
    You must create a function called myfloat_set_exponent() which:
    takes a POINTER to a MyFloat and an int,
    and changes only the exponent to the value passed by the int.
    The int might be negative, so you still have to adjust for bias.
    
    You must create a function called myfloat_set_mantissa() which:
    takes a POINTER to a MyFloat and an int,
    and changes only the mantissa to the value passed by the int.
    The int will include all implied bits, so you will have to remove them.

    You must create a function called myfloat_equals() which:
    takes compares two MyFloat and returns true if they are exactly equal
    and false if they are not exactly equal.

    
 */

#include "myfloat.h"
#include <limits.h>

/*  */

// make a myfloat which is 0
MyFloat myfloat_zero(){
    MyFloat zero;
    // set sign bit = 0
    zero.sign = 0;
    // set exponent bit = 0
    zero.exponent = 0;
    // set mantissa bit = 0
    zero.mantissa = 0;
    return zero;
}


// make a myfloat which is 1
MyFloat myfloat_one(){
    MyFloat one;
    // set sign bit = 0
    one.sign = 0;
    // set exponent bit = 0 + BIAS
    one.exponent = 0 + BIAS;
    // set mantissa bit = 0
    one.mantissa = 0;
    return one;
}


// get myfloat.sign
int myfloat_negative(MyFloat myfloat){
    return (int)myfloat.sign;
}


//get myfloat.exponent - BIAS
int myfloat_exponent(MyFloat myfloat){
    if (((int)myfloat.exponent == 0) &&
        ((int)myfloat.mantissa == 0)){
        // INT_MIN
        return INT_MIN;
    }
    // BIAS * 2 + 1 means every exponent bit equals to 1
    if (((int)myfloat.exponent == BIAS * 2 + 1) &&
        ((int)myfloat.mantissa == 0)){
        // INT_MAX
        return INT_MAX;
    }
    return (int)myfloat.exponent - (int)BIAS;
}


// get myfloat.mantissa - BIAS
int myfloat_mantissa(MyFloat myfloat){
    // INT_MAX or INT_MIN
    if ((((int)myfloat.exponent == 0) && ((int)myfloat.mantissa == 0)) ||
        (((int)myfloat.exponent == BIAS * 2 + 1) && ((int)myfloat.mantissa == 0))){
        return 0;
    }
    // add 1 before mantissa bit
    return (int)(myfloat.mantissa | ((unsigned int)1 << MANTISSA_BITS));
}


// set myfloat.sign
void myfloat_set_negative(MyFloat * myfloat, int number){
    myfloat->sign = number;
}


// set myfloat.exponent
void myfloat_set_exponent(MyFloat * myfloat, int number){
    if (number == INT_MAX){
        // every exponent bit equals to 1
        myfloat->exponent = BIAS * 2 + 1;
    }
    else if (number == INT_MIN){
        // exponent = 0
        myfloat->exponent = 0;
    }
    else{
        myfloat->exponent = BIAS + number;
    }
}


// set myfloat.mantissa
void myfloat_set_mantissa(MyFloat * myfloat, int number){
    // delete 1 before mantissa bit
    myfloat->mantissa = (unsigned int)number & (~((unsigned int)1 << MANTISSA_BITS));
}


// compare two myfloats
bool myfloat_equals(MyFloat myfloat_one, MyFloat myfloat_two){
    return (((int)myfloat_one.sign == (int)myfloat_two.sign) &&
            ((int)myfloat_one.exponent == (int)myfloat_two.exponent) &&
            ((int)myfloat_one.mantissa == (int)myfloat_two.mantissa));
}
