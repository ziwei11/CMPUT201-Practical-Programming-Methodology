/* we need to change N into 17, 
 * because we need to make sure '\0' is on the last position of bufferStack.
 * and we need to free bufferHeap in checkInput function if it is invalid input.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Read a string to the stack and the heap and print it out


/* checkInput: given the result of scanf check if it
 * 0 elements read or EOF. If so exit(1) with a warning.
 *
 */
void checkInput(int err, char * bufferHeap) {
  if (!err || err == EOF) {
    printf("\nInvalid input!\n");
    free(bufferHeap);
    exit(1);
  }
}

#define N 17
#define M 15
int main() {
  char bufferStack[N] = { '\0' };
  char * bufferHeap = calloc(N, sizeof(char));
  char junk[N];
  printf("Enter a string no more than 16 chars long\n0123456789012345\n");
  checkInput(scanf("%16[^\n]", bufferStack), bufferHeap);
  printf("BufferStack: %s\n", bufferStack);
  if (strlen(bufferStack) > M){
      printf("\nInvalid input!\n");
      free(bufferHeap);
      return 0;
  }
  checkInput(scanf("%16[\n]", junk), bufferHeap);
  checkInput(scanf("%16[^\n]", bufferHeap), bufferHeap);
  printf("BufferHeap: %s\n", bufferHeap);
  free(bufferHeap);
  return 0;
}

