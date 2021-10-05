/*

  CMPUT201W20 Midterm 3 Question 1
  
  This program attempts to decode the bits of floating point numbers.
  It is meant to allow you access to the mantissa, the sign, and the
  exponent of a floating point number. But something is not right.
  Please fix it. No more than 5 lines are needed to solve this problem.
  I used 3 lines for my solution.

  NAME: Vicky Zhao
  CCID: ziwei11
  STUDENT NUMBER: 1593071

  In this comment please describe how you fixed this problem and what
  tools you used:
  We need to change the order of "unsigned int sign:SIGN",
  "unsigned int exponent:EXPONENT", and "unsigned int mantissa:MANTISSA" (line 47 - 49).
  Because here the code is little endian (line 35),
  so here we need little endian, not big endian.
  Thus, we change the order of these three into "unsigned int mantissa:MANTISSA",
  "unsigned int exponent:EXPONENT", and "unsigned int sign:SIGN" (line 45 - 47).
 

 */
#include <assert.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>

#define SIGN 1
#define MANTISSA 23
#define EXPONENT 8

// float_t is NOT PORTABLE-- we're going to assume x86_64 little endian.
// This is meant to allow you to have access to floating point
// numbers Mantissa, Exponent, and Sign
// Helpful resources:
// - https://en.wikipedia.org/wiki/IEEE_754
// - http://steve.hollasch.net/cgindex/coding/ieeefloat.html
// - sign is the sign bit
// - mantissa is the digits
// - exponent is the raw exponent of a IEEE 754 float
struct float_t {
  unsigned int mantissa:MANTISSA;
  unsigned int exponent:EXPONENT;
  unsigned int sign:SIGN;
  //unsigned int exponent:EXPONENT;
  //unsigned int mantissa:MANTISSA;
};


typedef struct float_t FloatStruct;

// type pun for fun! floatint allows you to type pun a float to a
// uint32_t and to our FloatStruct so we can access its mantissa,
// sign, and exponent bits.
union floatint {
  float f;
  uint32_t i;
  FloatStruct t;
};

// Test cases have
// name - a useful name to describe the test
// rep - a representation as a 32bit unsigned integer
//     - good hex printing during debugging
// sign - the expected sign
// exponent - the expected sign
// mantissa - the expected mantissa
struct test_case {
  char * name;
  uint32_t rep;
  uint32_t sign;
  uint32_t exponent;
  uint32_t mantissa;
};

// floattest.h contains constant definitions that are commented below
// for your convienance.
#include "floattest.h"
/*
const float tests[] = {
  0.0F,
  -0.0F,
  INFINITY,
  -INFINITY,
  NAN,
  0.00001F,
  0.0001F,
  0.001F,
  0.01F,
  0.1F,
  1.0F,
  1/64.0F,
  1/32.0F,
  1/16.0F,
  1/8.0F,
  1/4.0F,
  1/2.0F,
  1.0F,
  2.0F,
  4.0F,
  128.0F,
  65536.0F,
  0.15625F,
  -0.15625F,
  36893488147419103232.0F,
  -36893488147419103232.0F
};
// These are test cases
struct test_case testCases[] = {
  {"0", 0x00000000, 0,   0, 0x000000},
  {"-0", 0x80000000, 1,   0, 0x000000},
  {"inf", 0x7f800000, 0, 255, 0x000000},
  {"-inf", 0xff800000, 1, 255, 0x000000},
  {"nan", 0x7fc00000, 0, 255, 0x400000},
  {"1e-05", 0x3727c5ac, 0, 110, 0x27c5ac},
  {"0.0001", 0x38d1b717, 0, 113, 0x51b717},
  {"0.001", 0x3a83126f, 0, 117, 0x03126f},
  {"0.01", 0x3c23d70a, 0, 120, 0x23d70a},
  {"0.1", 0x3dcccccd, 0, 123, 0x4ccccd},
  {"1", 0x3f800000, 0, 127, 0x000000},
  {"0.015625", 0x3c800000, 0, 121, 0x000000},
  {"0.03125", 0x3d000000, 0, 122, 0x000000},
  {"0.0625", 0x3d800000, 0, 123, 0x000000},
  {"0.125", 0x3e000000, 0, 124, 0x000000},
  {"0.25", 0x3e800000, 0, 125, 0x000000},
  {"0.5", 0x3f000000, 0, 126, 0x000000},
  {"1", 0x3f800000, 0, 127, 0x000000},
  {"2", 0x40000000, 0, 128, 0x000000},
  {"4", 0x40800000, 0, 129, 0x000000},
  {"128", 0x43000000, 0, 134, 0x000000},
  {"65536", 0x47800000, 0, 143, 0x000000},
  {"0.15625", 0x3e200000, 0, 124, 0x200000},
  {"-0.15625", 0xbe200000, 1, 124, 0x200000},
  {"3.68935e+19", 0x60000000, 0, 192, 0x000000},
  {"-3.68935e+19", 0xe0000000, 1, 192, 0x000000}
};
*/

int main() {
  // Our goal is to make sure that FloatStruct can safely decompose
  // float into their parts via bitfields.
  size_t nfloats = sizeof(tests)/sizeof(float);
  for (size_t i = 0; i < nfloats; i++) {
    float test = tests[i];
    struct test_case expected = testCases[i];
    // create our floatint so we can
    // type pun a float to an int or a FloatStruct
    union floatint fint = {.f=test};
    // assert the representation is the same
    assert(fint.i == expected.rep); // DNC
    // if something doesn't match let's print which testcase doesn't
    // match
    if (fint.t.sign != expected.sign ||             // DNC
        fint.t.exponent != expected.exponent ||     // DNC
        fint.t.mantissa != expected.mantissa) {     // DNC
      // A helper so you know which one crashed!
      printf("%s\n", expected.name);                // DNC
      // assert the difference between our float_t and the expected
      // result
      assert(fint.t.sign     == expected.sign);     // DNC
      assert(fint.t.exponent == expected.exponent); // DNC
      assert(fint.t.mantissa == expected.mantissa); // DNC
    }
  }
  return 0;
}
