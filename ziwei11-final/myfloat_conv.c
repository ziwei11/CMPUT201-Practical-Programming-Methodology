/*
  CMPUT201W20 Final Exam Question 3 (Code)
  
  NAME: Vicky Zhao
  CCID: ziwei11
  STUDENT NUMBER: 1593071
  VERSION: 0.9.0

  Finish this C header to get question3_test working.
  
  Do not add a main function!

 You must add a str_to_myfloat that converts a decimal string to
 a MyFloat. It must understand scientific notation.
 It must take a const char * as its only argument, and return a MyFloat.
 For example, -2.0e3 is -2000.
 It must understand the difference between "-0" and "0".
 It must understand "-inf" (negative infinity) and "inf" (infinity).
 
 You must add a myfloat_to_str that converts a MyFloat to 
 a string in decimal notation.
 Always use scientific notation,
 with two digits after the decimal place,
 "e", either a "+" or "-",
 and two digits of exponent.
 For example, instead of printing
 321, print "3.21e+02".
 For zero, print "0".
 For negative zero, print "-0".
 For infninity, print "inf".
 For negative infinity, print "-inf".
 */

/*  */


//#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "myfloat.h"
#include "myfloat_conv.h"

MyFloat str_to_myfloat(const char * string){
    double number = atof(string);
    DoubleMyFloat dmyfloat = {.doub = number};
    return dmyfloat.myflo;
}

char * myfloat_to_str(MyFloat myfloat){
    DoubleMyFloat dmyfloat = {.myflo = myfloat};
    double number = dmyfloat.doub;
    char * string = malloc(100 * sizeof(char));
    sprintf(string,"%f",number);
    return string;
}
