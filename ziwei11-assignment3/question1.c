#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <stdint.h>
#include <string.h>

#define STRZERO '0'  // str 0
#define MAX_STRING_LENGTH 1024  // max string length

// get tribonacci number of unsigned long long type
unsigned long long tribonacci1(int tri_input) {  // calculate tribonacci
   unsigned long long triarray[MAX_STRING_LENGTH];
    int index;
    triarray[0] = 0;  // index = 0
    triarray[1] = 0;  // index = 1
    triarray[2] = 1;  // index = 2
    index = 2;
    if (tri_input <= 2){  // base case
        return triarray[tri_input];
    }else{  // ind step
        for(index = 3; index <= tri_input; ++index){
            triarray[index] = triarray[index - 1] + triarray[index - 2] + triarray[index - 3];
        }
        return triarray[tri_input];
    }
}

// get tribonacci number of unsigned short type
unsigned short tribonacci2(int tri_input) {  // calculate tribonacci
   unsigned short triarray[MAX_STRING_LENGTH];
    int index;
    triarray[0] = 0;  // index = 0
    triarray[1] = 0;  // index = 1
    triarray[2] = 1;  // index = 2
    index = 2;
    if (tri_input <= 2){  // base case
        return triarray[tri_input];
    }else{  // ind step
        for(index = 3; index <= tri_input; ++index){
            triarray[index] = triarray[index - 1] + triarray[index - 2] + triarray[index - 3];
        }
        return triarray[tri_input];
    }
}

// get tribonacci number of unsigned int type
unsigned int tribonacci3(int tri_input) {  // calculate tribonacci
   unsigned int triarray[MAX_STRING_LENGTH];
    int index;
    triarray[0] = 0;  // index = 0
    triarray[1] = 0;  // index = 1
    triarray[2] = 1;  // index = 2
    index = 2;
    if (tri_input <= 2){  // base case
        return triarray[tri_input];
    }else{  // ind step
        for(index = 3; index <= tri_input; ++index){
            triarray[index] = triarray[index - 1] + triarray[index - 2] + triarray[index - 3];
        }
        return triarray[tri_input];
    }
}

// get tribonacci number of float type
float tribonacci4(int tri_input) {  // calculate tribonacci
   float triarray[MAX_STRING_LENGTH];
    int index;
    triarray[0] = 0;  // index = 0
    triarray[1] = 0;  // index = 1
    triarray[2] = 1;  // index = 2
    index = 2;
    if (tri_input <= 2){  // base case
        return triarray[tri_input];
    }else{  // ind step
        for(index = 3; index <= tri_input; ++index){
            triarray[index] = triarray[index - 1] + triarray[index - 2] + triarray[index - 3];
        }
        return triarray[tri_input];
    }
}

// get tribonacci number of double type
double tribonacci5(int tri_input) {  // calculate tribonacci
   double triarray[MAX_STRING_LENGTH];
    int index;
    triarray[0] = 0;  // index = 0
    triarray[1] = 0;  // index = 1
    triarray[2] = 1;  // index = 2
    index = 2;
    if (tri_input <= 2){  // base case
        return triarray[tri_input];
    }else{  // ind step
        for(index = 3; index <= tri_input; ++index){
            triarray[index] = triarray[index - 1] + triarray[index - 2] + triarray[index - 3];
        }
        return triarray[tri_input];
    }
}

int main() {
    char number[MAX_STRING_LENGTH];
    int input_number;
    printf("Tribonacci! Type in a positive tribonacci input:\n");
    if (fgets(number, MAX_STRING_LENGTH, stdin) == NULL){  // if input is empty, print tribonacci(0) of 16bit, 32bit, 64bit, float, double
        printf("16bit Tribonacci %hu\n", tribonacci2(0));
        printf("32bit Tribonacci %u\n", tribonacci3(0));
        printf("64bit Tribonacci %llu\n", tribonacci1(0));
        printf("Float Tribonacci %e\n", tribonacci4(0));
        printf("Double Tribonacci %le\n", tribonacci5(0));
        return 0;
    }
    input_number = atoi(number);
    if(number[0] == STRZERO){  // if input is 0
        printf("16bit Tribonacci %hu\n", tribonacci2(input_number));
        printf("32bit Tribonacci %u\n", tribonacci3(input_number));
        printf("64bit Tribonacci %llu\n", tribonacci1(input_number));
        printf("Float Tribonacci %e\n", tribonacci4(input_number));
        printf("Double Tribonacci %le\n", tribonacci5(input_number));
        return 0;
    }else if (input_number > 0 && input_number <= MAX_STRING_LENGTH - 1){  // if input is valid and not 0
        printf("16bit Tribonacci %hu\n", tribonacci2(input_number));
        printf("32bit Tribonacci %u\n", tribonacci3(input_number));
        printf("64bit Tribonacci %llu\n", tribonacci1(input_number));
        printf("Float Tribonacci %e\n", tribonacci4(input_number));
        printf("Double Tribonacci %le\n", tribonacci5(input_number));
        return 0;
    }else{  // print invalid if the input is not valid
        printf("Invalid input!\n");  // print “invalid input”
        return 1;
    }
}





