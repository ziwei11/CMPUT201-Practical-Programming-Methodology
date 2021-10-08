/*
  CMPUT201W20 Final Exam Question 1 (Header)

  NAME: Vicky Zhao
  CCID: ziwei11
  STUDENT NUMBER: 1593071
  VERSION: 0.9.0

  Finish this header to get question1_test.c working.
  
  You must define SIGN_BITS, EXPONENT_BITS, and MANTISSA_BITS,
    MYFLOAT_BITS, MYFLOAT_BYTES, and BIAS.
    
    You must create a type called MyFloat.
    
    MyFloat must contain the sign last (in the most significant bit), then the exponent, then the mantissa.
    
    sizeof(MyFloat) must be 4.
    
 */
/*  */

#include <stdbool.h>

#define SIGN_BITS 1UL
#define EXPONENT_BITS 10UL
#define MANTISSA_BITS 21UL
#define MYFLOAT_BITS 32UL
#define MYFLOAT_BYTES 4
#define BIAS 511UL

/*  */
# pragma once


struct myfloat{
    unsigned int mantissa: MANTISSA_BITS;
    unsigned int exponent: EXPONENT_BITS;
    unsigned int sign: SIGN_BITS;
};

typedef struct myfloat MyFloat;


union doublemyfloat{
    double doub;
    MyFloat myflo;
};

typedef union doublemyfloat DoubleMyFloat;


MyFloat myfloat_zero();

MyFloat myfloat_one();

int myfloat_negative(MyFloat myfloat);

int myfloat_exponent(MyFloat myfloat);

int myfloat_mantissa(MyFloat myfloat);

void myfloat_set_negative(MyFloat * myfloat, int number);

void myfloat_set_exponent(MyFloat * myfloat, int number);

void myfloat_set_mantissa(MyFloat * myfloat, int number);

bool myfloat_equals(MyFloat myfloat_one, MyFloat myfloat_two);

/*  */

