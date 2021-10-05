/* Line 16, i should be bigger than or equal to 0, not bigger than 0.
 * Because we need to store 0 in myIntegers[99].
 * If i is just bigger than 0, the last iteration of the for loop is myIntegers[98] = 1.
 * The last element of array myIntegers is 1, not 0.
 */

#include <stdio.h>
#include <stdlib.h>
// print in rows of 5, 99 to 0


#define N (5*20)
#define BASE 5
int main() {
  int * myIntegers = malloc( N * sizeof(int) );
  for (int i = N-1; i >= 0; i--) {
    myIntegers[N-1-i] = i;
  }
  int * ints = myIntegers;
  for (int i = 0; i < N / BASE; i++) {
    printf("%d %d %d %d %d\n", ints[i * BASE], ints[i * BASE + 1], 
    ints[i * BASE + 2], ints[i * BASE + 3], ints[i * BASE + 4]);
    //printf("%d %d %d %d %d\n", *ints++, *ints++, *ints++, *ints++, *ints++);
  }
    free(myIntegers);
}


