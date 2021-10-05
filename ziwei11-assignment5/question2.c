#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


/*  strCat: append the string `str2` to the end of `str1` and return
 *  the concatenated string.
 *
 *         given `str1` and `str2` are two non-empty strings, you
 *         have to concatenate `str2` to the end of `str1`. The null
 *         char of `str1` is overwritten by the first char of `str2`
 *         If `str2` is empty `str1` remains unchanged.
 *
 *         you must not use the string.h functions other than mem*
 *         functions like memcpy.
 *
 *  @param `str1`  an array of char to be concatenated to
 *  @param `str2`  an array of char to concatenate to the end of `str1`
 *
 *  @return the concatenated string `str1` with `str2` copied on the end
 *          if str1 or str2 is NULL, NULL is returned
 *
 *  @Warning str1 needs to be allocated enough memory to allow for the concatenation.
 *
 *  char strCat(char *str1, const char *str2)
 *  str1="Hello World"; str2="Hello";  strCat(str1,str2)    // returns Hello WorldHello
 *  //if user enters empty string the program should exit with invalid input error.
 */


int my_strlen(char *str){
    int count = 0;
    while (*str != '\0'){
        count++;
        str++;
    }
    return count;
}


char *strCat( char *str1, const char *str2) {
  // Fill in this function!
    if (str1 == NULL || str2 == NULL){
        return NULL;
    }
    int count1 = my_strlen(str1);
    char * string2 = (char *)str2;
    int count2 = my_strlen(string2);
    for (int i = count1; i <= count1 + count2 - 1; i++){
        str1[i] = str2[i - count1];
    }
    str1[count1 + count2] = '\0';
    return str1;
}


/*  strFind: find a string `str2` within another string `str1` and return an
 *  integer value. If string is found the returned value is the starting index
 *  of `str2` inside `str1`
 *
 *         given `str1` search for `str2` in it by traversing the `str1`
 *         till the end.
 *         If `str2` is found in `str1` return the starting index of `str2`.
 *         If `str2` is no in `str1` return -1.
 *
 *         you must not use the string.h functions other than mem*
 *         functions like memcpy.
 *
 *  @param `str1`  an array of char to search within
 *  @param `str2`  an array of char to search for within `str1`
 *
 *  @return -1 if `str2` not found in `str1` , otherwise the index
 *  within the array where `str2` begins in `str1`.
 *  @return -1 if `str1` or `str2` are NULL
 *
 *  int strFind(const char *str1, const char *str2)
 *  str1= "This string has Hello in it";
 *  str2= "Hello;
 *  strFind(str1,str2);                 //returns 16
 *  str2="Happy"; strFind(str1,str2);     //returns -1
 */


int strFind(const char* str1, const char* str2) {
  // Fill in this function!
    //if (*str2 == ""){
        //return 0;
    //}
    if (str1 == NULL || str2 == NULL){
        return -1;
    }
    char * string1 = (char *)str1;
    char * string2 = (char *)str2;
    int count1 = my_strlen(string1);
    int count2 = my_strlen(string2);
    if (count2 == 0){
        return 0;
    }
    for (int i = 0; i <= count1 - 1; i++){
        if (str2[0] == str1[i]){
            int beginning = i;
            int newcount = 0;
            for (int j = 0; j <= count2 - 1; j++){
                if (str2[j] == str1[i + j]){
                    newcount = newcount + 1;
                }
            }
            if (newcount == count2){
                return beginning;
            }
        }
    }
    return -1;
}


/////////////////////////////////////////////////////////////
// Below, this is all driver code, please don't modify it. //
/////////////////////////////////////////////////////////////

void checkInput(int err) {
  if (!err || err == EOF) {
    printf("\nInvalid input!\n");
    exit(1);
  }
}

#define TESTMAXLEN 1024
#define TESTEXAMPLES 7

// this tests strFind pretty well
void testStrFind() {
  char str1[TESTMAXLEN] = "AAAAAAAB";
  char strs[TESTEXAMPLES][TESTMAXLEN] = {
    {"AAAAAAB"},
    {"AAAAAB"},
    {"AAAAB"},
    {"AAAB"},
    {"AAB"},
    {"AB"},
    {"B"}
  };
  for (int i = 0 ; i < TESTEXAMPLES; i ++) {
    assert( i+1 == strFind( str1, strs[i] ));
  }
  assert(strFind(str1,"X") == -1);
  assert(strFind(str1,"AAAAAAAB") == 0);
  assert(strFind(str1,"AAAAAAAAB") == -1);
  assert(strFind(str1,"") == 0);
  assert(strFind("",str1) == -1);
  assert(strFind("",NULL) == -1);
}

// this tests strCat pretty well
void testStrCat() {
  char str1[TESTMAXLEN] = "";
  char str2[TESTMAXLEN] = "7890";
  char answer[] = "0908907890";
  const int answerLen = 10;
  const int str2len = 4;
  for (int i = 0 ; i < str2len; i ++) {
    strCat(str1, str2 + str2len - i - 1);
  }
  for (int i = 0 ; i < answerLen; i++) {
    assert(str1[i] == answer[i]);
  }
  strCat(str1, "");
  for (int i = 0 ; i < answerLen; i++) {
    assert(str1[i] == answer[i]);
  }
  assert(NULL == strCat( NULL, NULL ));
}


void driver() {
  const int MAXLEN = 1024;
  char str1[MAXLEN];
  char str2[MAXLEN];
  char str3[MAXLEN];
  char str4[MAXLEN];
  printf("Enter first string\n");
  checkInput(scanf("%1024[^\n]%*c", str1));
  printf("Enter second string\n");
  checkInput(scanf("%1024[^\n]%*c", str2));
  char *ptr1 = str1;
  char *ptr2 = str2;
  char *ptr3 = str3;
  char *ptr4 = str4;
  printf("STRCAT\n");
  char *result = strCat(ptr1, ptr2);
  printf("String after concatenation: ");
  for (int idx = 0; result[idx] != '\0'; idx++) {
    printf("%c",result[idx]);
  }
  printf("\nSTRFIND");
  printf("\nEnter string you want to look up in:");
  checkInput(scanf("%1024[^\n]%*c", str3));
  printf("\nEnter string you want to look up for:");
  checkInput(scanf("%1024[^\n]%*c", str4));
  int index = strFind(ptr3, ptr4);
  if (index == -1) {
    printf("\nString not found!\n");
  }
  else {
    printf("\nString found at index: %d\n",index);
  }
}

int main() {
  driver();
  // Run the unit tests
  testStrFind();
  testStrCat();
  return 0;
}



