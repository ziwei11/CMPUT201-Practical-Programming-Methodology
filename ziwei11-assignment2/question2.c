#include <stdio.h>
#include <stdlib.h>

#define PROMPTINPUT "Enter a number between 1 and 9: "
#define MAX 1024
#define SMALLESTNUMBER 1
#define LARGESTNUMBER 9
#define UNDERSCORE "_"
#define INTEGER "%d"

int main() {
    int input_number, i, left_underscore, left_decreasing_integer, left_increasing_integer, middle_underscore1, middle_underscore2, right_decreasing_integer, right_increasing_integer, right_underscore;  // define some variable which we will use below
    char number[MAX];
    printf(PROMPTINPUT);
    fgets(number, MAX, stdin);  // get the input number and store it in input_number
    input_number = atoi(number);  // change the string into int
    printf("\n");
    if (input_number < SMALLESTNUMBER || input_number > LARGESTNUMBER){  // when input_number is invalid
        printf("Invalid input\n");  // print “invalid input”
    }else{
        for (i = 1; i <= input_number; ++i){  // get the output
            for (left_underscore = input_number - i; left_underscore >= 1; --left_underscore){  // print underscore
                printf(UNDERSCORE);
            }
            for (left_decreasing_integer = i; left_decreasing_integer >= 1; --left_decreasing_integer){  // print integer
                printf(INTEGER, left_decreasing_integer);
            }
            for (left_increasing_integer = 2; left_increasing_integer <= i; ++left_increasing_integer){  // print integer
                printf(INTEGER, left_increasing_integer);
            }
            for (middle_underscore1 = input_number - i; middle_underscore1 >= 1; --middle_underscore1){  // print underscore
                printf(UNDERSCORE);
            }
            for (middle_underscore2 = 1; middle_underscore2 <= i - 1; ++middle_underscore2){  // print underscore
                printf(UNDERSCORE);
            }
            for (right_decreasing_integer = input_number + 1 - i; right_decreasing_integer >= 1; --right_decreasing_integer){  // print integer
                printf(INTEGER, right_decreasing_integer);
            }
            for (right_increasing_integer = 2; right_increasing_integer <= input_number + 1 - i ; ++right_increasing_integer){  // print integer
                printf(INTEGER, right_increasing_integer);
            }
            for (right_underscore = 1; right_underscore <= i - 1; ++right_underscore){  // print underscore
                printf(UNDERSCORE);
            }
            printf("\n");
        }
    }
    return 0;
}


