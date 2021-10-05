#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*  setAt: set an entry in an integer array
 *         given `anArray` of `arrLen` length
 *         set anArray[pos] to value if position is valid.
 *         Upon successful setting of the array, `pos` is returned
 *         If pos is < 0 or pos >= arrLen -1 is returned.
 *
 *  @param anArray  an array of integers
 *  @param arrLen   length of anArray
 *  @param position position in the array to set
 *  @param value    to set in anArray[position] if position is value
 *
 *  @return -1 if position is invalid, and position if position is valid.
 *
 *  setAt( arr, 10, 5,  -2 ) ==  5; // set arr[5] = -2
 *  setAt( arr, 10, 10, -2 ) == -1; // Unsuccessful setting
 *  setAt( arr, 10, -1, -2 ) == -1; // Unsuccessful setting
 */
int setAt(int anArray[], int arrLen, int position, int value) {
  // complete the function body
  // if arguments are valid, set the val at idx in an_array.
  // Fill in this function!
    if (position >= 0 && position < arrLen){
        anArray[position] = value;
        return position;
    }
    return -1;
}


/*  subArrPointer: returns a copy of the array elements
 *         given `anArray` of `arrLen` length
 *         return a malloc'd copy of the sub sequence from `position`
 *         to `position`+`size` exclusive
 *         if the range in too long or invalid or position is invalid
 *         NULL is returned.
 *         Otherwise a pointer to heap allocated memory where the sub array
 *         has been copied to will be returned.
 *
 *  @param anArray  an array of integers
 *  @param arrLen   length of anArray
 *  @param position position (index) in anArray of the subarray
 *  @param size     length of the sub array to be returned
 *
 *  @return NULL if position is invalid, NULL if position+size is not
 *  a valid subarray, and a pointer to a copy of the subarray if valid.
 *
 *  @warning memory is allocated with malloc and needs to be free'd later.
 *
 *  subArrPointer( arr, 10, 5,  -2 ) ==  NULL; // invalid size
 *  subArrPointer( arr, 10, 9,  3 ) ==  NULL;  // range does not fit with arrLen
 *  free(subArrPointer( arr, 10, 3,  3 ));  // return a subarray of length 3 and free it
 *
 */
int *subArrPointer(const int anArray[], int arrLen, int position, int size) {
  // complete the function body
  // check if arguments are valid
  // you may create a new array using malloc
  // return the sub-array of siz starting at idx
  // Fill in this function!
    if (size <= 0){
        return NULL;
    }
    if (position < 0 || position > arrLen - 1){
        return NULL;
    }
    if ((position + size - 1) <= arrLen - 1){
        int *subarr = malloc(size * sizeof(int));
        for (int i = 0; i <= size - 1; i++){
            subarr[i] = anArray[position + i];
        }
        return subarr;
    }
    return NULL;
}


/*  insert: insert a single value `value` into an array and returns a
 *  malloc'd copy of that array. The values after `position` will be
 *  shifted 1 index to the right. The original array, `anArray` is
 *  untouched.

 *         given `anArray` of `arrLen` length return a malloc'd copy
 *         of `anArray` with `value` inserted into `position`. The
 *         resulting array will be of size arrLen+1.
 *         If position is invalid or memory cannot be malloc'd NULL is
 *         returned.
 *         If position == arrLen, value will be placed at the end of
 *         the new array.
 *         Otherwise a pointer to heap allocated memory where the array
 *         has been copied to will be returned. The new array will be
 *         arrLen + 1 length iff position was valid.
 *
 *  @param anArray  an array of integers
 *  @param arrLen   length of anArray
 *  @param position position (index) in anArray of the subarray
 *  @param value    value to be inserted at anArray[position]
 *
 *  @return NULL if position is invalid, and a pointer to a copy of
 *  the array with value in position if valid.
 *
 *  @warning memory is allocated with malloc and needs to be free'd later.
 *
 *  insert( arr, 10, 5,  -2 )[5] ==  -2; // -2 was inserted!
 *  insert( arr, 10, 10,  -2 )[10] ==  -2; // -2 was inserted at the end!
 *  arr[0] = 99; insert( arr, 10, 0,  0 )[1] == 99; // 99 was pushed over to index 1
 *  insert( arr, 10, 11,  -2 ) == NULL; // 11 was an invalid position
 *  insert( arr, 10, -1,  -2 ) == NULL; // -1 was an invalid position
 */
int *insert(const int anArray[], int arrLen, int position, int value) {
  // complete the function body
  // if arguments are valid insert val at idx
  // you may have to create a new array using malloc
  // return the new array
  /* inserts the value value at position.
     Shift the elements after position to the right.*/
  // Fill in this function!
    if (position == arrLen){
        int *copyarr = malloc((arrLen + 1) * sizeof(int));
        for (int i = 0; i <= arrLen - 1; i++){
            copyarr[i] = anArray[i];
        }
        copyarr[position] = value;
        return copyarr;
    }
    if (position >= 0 && position < arrLen){
        int *copyarr = malloc((arrLen + 1) * sizeof(int));
        for (int i = 0; i <= position - 1; i++){
            copyarr[i] = anArray[i];
        }
        copyarr[position] = value;
        for (int i = position + 1; i <= arrLen ; i++){
            copyarr[i] = anArray[i - 1];
        }
        return copyarr;
    }
    return NULL;
}


/*  erase: remove a single value at `postion` from `anArray` and returns a
 *  malloc'd copy of modified array. The values after `position` will be
 *  shifted 1 index to the left. The original array, `anArray` is
 *  untouched.

 *         given `anArray` of `arrLen` length return a malloc'd copy
 *         of `anArray` with the value at `position` removed and the
 *         rest of the values shifted to the left. The resulting array
 *         will be of size arrLen-1.
 *         If position is invalid or memory cannot be malloc'd NULL is
 *         returned.
 *         If position == arrLen NULL will be returned.
 *         If the array is size 0 NULL will be returned.
 *         Otherwise a pointer to heap allocated memory where the array
 *         has been copied to will be returned. The new array will be
 *         arrLen - 1 length iff position was valid.
 *
 *  @param anArray  an array of integers
 *  @param arrLen   length of anArray
 *  @param position position (index) in anArray of the subarray
 *
 *  @return NULL if position is invalid, and a pointer to a copy of
 *  the array with value in position if valid.
 *
 *  @warning memory is allocated with malloc and needs to be free'd later.
 *
 *  arr[6] = 7;  erase( arr, 10, 5)[5] ==  7; // arr[5] was removed
 *  arr[8] = -2; erase( arr, 10, 9)[8] == -2; // we still have the end of arr
 *  arr[1] = 99; erase( arr, 10, 0)[0] == 99; // 99 shifted to index 0
 *  erase( arr, 10, -1  ) == NULL; // -1 was an invalid position
 *  insert( arr, 10, 10 ) == NULL; // 10 was an invalid position
 */
int * erase(const int anArray[], int arrLen, int position) {
  /* erases the value val at pos.
     Shift the elements after pos to the left.*/
  // Fill in this function!
    if (arrLen == 0){
        return NULL;
    }
    if (position == arrLen - 1){
        int *copyarr = malloc((arrLen - 1) * sizeof(int));
        for (int i = 0; i <= arrLen - 2; i++){
            copyarr[i] = anArray[i];
        }
        return copyarr;
    }
    if (position >= 0 && position <= arrLen - 1){
        int *copyarr = malloc((arrLen - 1) * sizeof(int));
        for (int i = 0; i <= position - 1; i++){
            copyarr[i] = anArray[i];
        }
        for (int i = position; i <= arrLen - 2; i++){
            copyarr[i] = anArray[i + 1];
        }
        return copyarr;
    }
    return NULL;
}


/////////////////////////////////////////////////////
// This is all driver code, please don't modify it.//
/////////////////////////////////////////////////////

const char * indexOutOfBounds = "\nIndex out of bounds..";

void printArray(int * anArray, int arrLen) {
  for(int idx=0; idx < arrLen; idx++) {
    printf("%d ", anArray[idx]);
  }
  printf("\n");
}

void checkInput(int err) {
  if (!err || err == EOF) {
    printf("\nInvalid input!\n");
    exit(1);
  }
}

void evaluateSetAt(int * anArray, int arrLen) {
  int position = -1;
  int value    = -1;
  printf("Enter index and value to set at index: ");
  checkInput(scanf("%d", &position));
  checkInput(scanf("%d", &value));
  if (-1==setAt(anArray, arrLen, position, value)) {
    puts(indexOutOfBounds);
  }
  printf("Updated array: ");
  printArray(anArray, arrLen);
}

void evaluateSubArrPointer(int * anArray, int arrLen) {
  int position = -1;
  int size     = -1;
  printf("Enter starting index and size of sub-array: ");
  checkInput(scanf("%d",&position));
  checkInput(scanf("%d",&size));
  int *ptr = subArrPointer(anArray, arrLen, position, size);
  if (ptr==NULL) {
    puts(indexOutOfBounds);
  } else {
    printf("Sub-array: ");
    printArray(ptr,size);
    free(ptr);
  }
}

int * evaluateInsert(int * anArray, int arrLen, int * resLen) {
  int anotherValue=  0;
  int position    = -1;
  printf("Enter index and value to insert at index: ");
  checkInput(scanf("%d", &position));
  checkInput(scanf("%d", &anotherValue));
  int *retArray = insert( anArray, arrLen, position, anotherValue);
  if(retArray==NULL) {
    // failed insert
    puts(indexOutOfBounds);
    *resLen = arrLen;
    return anArray;
  }
  printf("\nArray after insertion: ");
  printArray(retArray, arrLen+1);
  *resLen = arrLen+1;
  return retArray;
}

void evaluateDeletion(int * anArray, int arrLen) {
  int position = -1;
  printf("Enter index to delete: ");
  checkInput(scanf("%d",&position));
  int * eraseArray = erase(anArray, arrLen, position);
  if(eraseArray==NULL) {
    puts(indexOutOfBounds);
  } else {
    printf("\nAfter erasing: ");
    printArray(eraseArray, arrLen-1);
    free(eraseArray);
  }
}

int * testAllocArray(int arrLen) {
  size_t size = arrLen * sizeof(int);
  int* array = malloc( size );
  assert(array!=NULL);
  memset((void*)array, 0, size);
  for(int idx=0; idx<arrLen; idx++) {
    array[idx] = idx;
  }
  return array;
}

/* Unit tests for setAt you need to pass
 *
 */
void testSetAt() {
  const int arrLen = 200;
  int* array = testAllocArray(arrLen);
  for(int idx=0; idx<arrLen; idx++) {
    // test if the return value is correct
    assert(idx == setAt(array, arrLen, idx, idx));
    // test if the value was set
    assert(array[idx] == idx);
  }
  assert(setAt(array,arrLen,-1,0)==-1);
  assert(setAt(array,arrLen,-1000,0)==-1);
  assert(setAt(array,arrLen,arrLen,0)==-1);
  assert(setAt(array,arrLen,arrLen+10,0)==-1);
  assert(setAt(array,arrLen,arrLen-1,0)==arrLen-1);
  free(array);
}

void assertCompareArrays(const int * array1, const int * array2, int arrLen) {
  for(int idx=0; idx<arrLen; idx++) {
    assert(array1[idx] == array2[idx]);
  }
}

/* Unit tests for subArrPointer you need to pass
 *
 */
void testSubArrPointer() {
  const int arrLen = 200;
  int* array = testAllocArray(arrLen);
  // verify it can copy a whole array
  int * arrayCopy = subArrPointer( array, arrLen, 0, arrLen );
  assert(arrayCopy != NULL);
  assert(arrayCopy != array);
  assert(&arrayCopy[0] != &array[0]);
  assertCompareArrays(array,arrayCopy,arrLen);
  const int offset = 10;
  int * arrayCopy2 = subArrPointer( array, arrLen, arrLen-offset, offset );
  assert(arrayCopy2 != NULL);
  assertCompareArrays( arrayCopy2, &array[arrLen-offset], offset);
  assert( subArrPointer( array, arrLen, 0, arrLen+1 ) == NULL);
  assert( subArrPointer( array, arrLen, -1, arrLen ) == NULL);
  free(array);
  free(arrayCopy);
  free(arrayCopy2);
}

/* Unit tests for subArrPointer you need to pass
 *
 */
void testInsert() {
  const int arrLen = 200;
  int* array = testAllocArray(arrLen);
  // verify it insert at the front
  int * arrayCopy = insert( array, arrLen, 0, -1 );
  assert(arrayCopy != NULL);
  assert(arrayCopy != array);
  assert(&arrayCopy[0] != &array[0]);
  assert(arrayCopy[0] == -1);
  assert(arrayCopy[1] == 0);
  assert(arrayCopy[arrLen] == arrLen-1);
  assertCompareArrays(array,arrayCopy+1,arrLen);

  int * arrayCopy2 = insert( arrayCopy, arrLen+1, arrLen+1, -1 );
  assert(arrayCopy2 != NULL);
  assert(arrayCopy2[arrLen+1] == -1);
  free(array);
  free(arrayCopy);
  free(arrayCopy2);
}

void testErase() {
  const int arrLen = 200;
  int* array = testAllocArray(arrLen);
  for (int i = 0; i < arrLen ; i++) {
    int * newArray = erase(array, arrLen - i, 0);
    assert(newArray != array);
    if (arrLen - i > 1) {
      // if arrLen - i == 1 then newArray is of size 0
      assert(newArray[0] != array[0]);
      assert(newArray[0] == array[1]);
    }
    free(array);
    array = newArray;
  }
  assert(NULL == erase(array, 0, 0));
  free(array);
}

#define N 20

int main() {
  int array[N]={0};
  for(int idx=0; idx<N; idx++) {
    array[idx]=idx;
  }
  printf("Original array: ");
  printArray(array,N);

  printf("SET-AT\n");
  evaluateSetAt(array, N);
  
  printf("SUB-ARRAY\n");
  evaluateSubArrPointer(array, N);
  
  printf("INSERTION\n");
  int retArrayLen = N;
  int * retArray = evaluateInsert(array, N, &retArrayLen);
  
  printf("DELETION\n");
  evaluateDeletion(retArray, retArrayLen);

  if (retArray!=NULL && retArray != array) {
    free(retArray);
  }
  testSetAt();
  testSubArrPointer();
  testInsert();
  testErase();
  return 0;
}






