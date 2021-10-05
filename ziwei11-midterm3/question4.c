/*

  CMPUT201W20 Midterm 3 Question 4

  This program is searching for the x after which tanh(x) will always
  return 1.0. Tanh is often used to scale values in a non-linear way
  but once x is too big tanh(x) will return 1.0 all of the time,
  effectively breaking the scaling. Most people expect tanh(x) <
  tanh(y) when x < y, but after the point that this program finds that
  invariant is no longer true.

  Unfortunately the program doesn't work right and is failing asserts.

  On my computer (intel i7) the last double to produce a non 1.0 tanh is:
  X:      1.90615474653984939834572287509218e+01 
  hex(X): 0x40330fc1931f09c9
  You don't have to have exactly the same result, results may vary.
  I changed 2 lines. 

  NAME: Vicky Zhao
  CCID: ziwei11
  STUDENT NUMBER: 1593071

  In this comment please describe how you fixed this problem and what
  tools you used:
  From "bitstring.h", bitString(char * buffer, uint64_t value, const unsigned int bits).
  The second parameter of bitString is value which type is uint64_t.
  However, in line 112 and 122, the second parameters of bitString are inputx and nextx,
  and the type of these two variable is double.
  Thus, we need to change their type.
  

*/
#include "bitstring.h"
#include <assert.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define BUFFSIZE 1024
#define ASCIIBITS 7
#define SEARCHGRAIN 0.999
#define DOUBLEBITS 64

// PUN64 copies the bits of value into a 64bit unsigned int and
// returns it.
uint64_t PUN64(double value) {
  uint64_t output = 0;
  memcpy(&output, &value, sizeof(uint64_t));
  return output;
}

// evalx takes a double inputx and then calculates tanh for the input
// and tanh for next double value after intpux. nextafter is provided
// in <math.h> and it gives you the next closest double (min 1 bit
// difference).
// evalx returns -1 when we've found our goal of 1.0 on the dot with
// inputx
// evalx returns 0 if nextx is not >= 1.0
// evalx returns 1 if tanh(inputx) != 1.0 and tanh(next) == 1.0
int evalx(double inputx) {
  double next = nextafter(inputx,100.0);
  double tix = tanh(inputx);
  double tnx = tanh(next);
  if (tix >= 1.0) {
    return -1; // too big
  }
  return (tnx >= 1.0)?0:1; // just right or too small
}

// tanhSearch searches for the last double that before all further
// doubles produce tanh(x) == 1.0.
// inputx: Given an initial input of inputx to start searching
// grain: Given an a initial search step size of grain.
// interations: Given a pointer to a long to count the number of
// iterations
double tanhSearch(double inputx, double grain, long * iterations) {
  long count = 0;
  int done = 0;
  while( ! done ) {
    int res = evalx(inputx);
    if (res == 0) {
      done = 1;
    } else {
      if (res == -1) {
        inputx -= grain;
      } else {
        inputx += grain;
      }
    }
    grain *= SEARCHGRAIN;
    count++;
  }
  *iterations = count;
  return inputx;
}

// Setup tanhSearch and verify it works
int main() {
  // Make sure that bitString actually works
  char buffer[BUFFSIZE] = {'\0'};// DNC
  bitString(buffer,'a',ASCIIBITS);// DNC
  // Check if bitString produces the right bitString
  assert(strcmp("1100001", buffer) == 0);// DNC
  // Setup our search parameters
  long count = 0;
  const double initialInputX = 1.0;
  const double grain = 1.0;
  // Search for it!
  double inputx = tanhSearch( initialInputX, grain, &count);
  bitString(buffer,PUN64(inputx),DOUBLEBITS);
  printf("Iters: %ld Tanh(X): %.20e Tanh(nextafter(X)): %.20e\nX: %.32e -- hex(X): 0x%lx\n%s\n",
         count, tanh(inputx), tanh(nextafter(inputx,100.0)),
         inputx, PUN64(inputx), buffer);
  // ensure tanh(inputx) < tanh(nextafter(inputx)) == 1.0
  assert(tanh(inputx) < 1.0); // DNC
  double nextx = nextafter(inputx,100.0);
  assert(tanh(nextx) == 1.0); // DNC
  uint64_t pnextx = PUN64(nextx);
  char buffer2[BUFFSIZE] = {'\0'};
  bitString(buffer2,PUN64(nextx),DOUBLEBITS);
  printf("nextafter(X): %.32e hex(nextafter(X)): 0x%lx \n%s\n", nextx, pnextx, buffer2);
  char buffer3[BUFFSIZE] = {'\0'};
  bitString(buffer3,pnextx,DOUBLEBITS);
  // Ensure the bit representation of numbers are comparable
  assert(strcmp(buffer2,buffer3) == 0); // DNC
  assert(strcmp(buffer ,buffer2) <  0); // DNC
  assert(strcmp(buffer ,buffer3) <  0); // DNC
}  
