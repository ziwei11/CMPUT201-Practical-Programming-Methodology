#ifndef _FLOATTEST_H_
// WARNING: DO NOT MODIFY THIS FILE
#define _FLOATTEST_H_
// test cases
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
#endif
