#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024  // max string length
#define STOP_CHAR 'X'
#define START_CHAR 'a'
#define END_CHAR 'z'


int main(){
    char character[MAX_STRING_LENGTH], new_character[MAX_STRING_LENGTH], count[MAX_STRING_LENGTH], array1[MAX_STRING_LENGTH];
    int char_number, int_count, array2[MAX_STRING_LENGTH], size, array1_size = 0 , array2_size = 0, char_size = sizeof(char);
    bool stop = false;
    printf("Welcome to variable counter! Please record your counts! Type X to end.\n");
    while (!stop){  // if player does not input 'X', the program will never stop
        bool exist = false;
        printf("Input character variable a-z: \n");  // prompt player to input character
        scanf("%1024s", character);  // scanf the character we want
        new_character[0] = 0;
        int str_length = strlen(character);  // the length of str
        for (int i = 0; i <= (str_length - 1) ; ++i){  // if there are some blank space before the character, delete them
            if (character[i] != ' '){
                new_character[strlen(new_character)] = character[i];
            }
        }
        int char_length = strlen(new_character);
        char_number = char_length / char_size;
        if (char_number == 1){  // the length of the character must be 1
            if (new_character[0] >= START_CHAR && new_character[0] <= END_CHAR){  // new_character must be a letter between a and z
                printf("Input count variable a-z: \n");
                scanf("%1024s", count);  // scanf the character we want
                int_count = atoi(count);
                if (int_count > 0){  // invalid int count must be bigger than 0
                    if (array1_size == 0){
                        array1[0] = new_character[0];
                        array2[0] = int_count;
                        array1_size = array1_size + 1;  // array1 increases 1
                        array2_size = array2_size + 1;  // array2 increases 1
                    }else{
                        for (size = 0; size <= (array1_size - 1) ; ++size){
                            if (array1[size] == new_character[0]){
                                array2[size] = array2[size] + int_count;
                                exist = true;
                            }
                        }if (exist == false){
                            array1[array1_size] = new_character[0];
                            array2[array2_size] = int_count;
                            array1_size = array1_size + 1;  // array1 increases 1
                            array2_size = array2_size + 1;  // array2 increases 1
                        }
                    }
                }else{
                    break;
                }
            }else if (new_character[0] == STOP_CHAR){  // if player input is X
                stop = true;  // stop becomes true
            }else{
                break;
            }
        }else{
            break;
        }
    }
    for (size = 0; size <= ((array1_size) - 1) ; ++size){  // print the value
        printf("%c", array1[size]);
        printf(" - ");
        printf("%d\n", array2[size]);
    }
    return 0;
}



