#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1024
#define DOORNUMBER 3
#define FIRSTDOOR 0
#define LASTDOOR 2
#define CHOOSEDOOR "Choose a door from 1 to 3: "
#define ERROR "Error: please enter Y or N: "
#define REVEALCAR "Monty opens door #%d, revealing a car! You win!\n"
#define REVEALGOAT "Monty opens door #%d, revealing a goat. You lose.\n"

int main() {
    bool play_again = true;  // set a bool of whether or not play again
    while (play_again) {
        char input[MAX], switch_input[MAX], play[MAX];
        int input_number, door_of_car, second_door, third_door;
        bool ask = true, ask_play_again = true;
        door_of_car = rand() % DOORNUMBER;  // get a random number of 0, 1, 2
        printf(CHOOSEDOOR);
        fgets(input, MAX, stdin);  // get and store the input
        input_number = atoi(input);  //change string input into int input
        while (input_number != 1 && input_number != 2 && input_number != 3){  // if input is not 1, 2, or 3, prompt player to input again
            printf(CHOOSEDOOR);
            fgets(input, MAX, stdin);
            input_number = atoi(input);
        }
        printf("You chose door #%d.\n", input_number);  // print which door player choose
        for (second_door = FIRSTDOOR; second_door <= LASTDOOR; ++second_door){
            if (second_door != input_number - 1){  // the door that Monty chooses cannot be the door that player chooses
                if (second_door != door_of_car){  // the door that Monty chooses cannot be the door of the car
                    printf("Monty opens door #%d, revealing a goat!\n", second_door + 1);
                    break;
                }
            }
        }
        for (third_door = FIRSTDOOR; third_door <= LASTDOOR; ++third_door){
            if (third_door != input_number - 1){  // the door that player chooses to switch cannot be the door that player chooses at the beginning
                if (third_door != second_door){  // the door that player chooses to switch cannot be the door of that Monty choose
                    printf("Would you like to switch to door #%d? ", third_door + 1);
                    fgets(switch_input, MAX, stdin);
                    break;
                }
            }
        }
        while (ask) {
            if (switch_input[0] == 'Y' || switch_input[0] == 'y'){  // if player wants to switch
                if (third_door == door_of_car){
                    printf(REVEALCAR, third_door + 1);  // print revealing a car
                }else{
                    printf(REVEALGOAT, third_door + 1);  // print revealing a goat
                }
                ask = false;
            }else if (switch_input[0] == 'N' || switch_input[0] == 'n'){  // if player does not want to switch
                if (input_number - 1 == door_of_car){
                    printf(REVEALCAR, input_number);  // print revealing a car
                }else{
                    printf(REVEALGOAT, input_number);  // print revealing a goat
                }
                ask = false;
            }else{  // if there is an error
                printf(ERROR);
                fgets(switch_input, MAX, stdin);  // reget y or n
            }
        }
        printf("Would you like to play again? ");
        fgets(play, MAX, stdin);
        while (ask_play_again){  // ask if player wants to play again
            switch(play[0]) {
                case 'Y':
                    ask_play_again = false;
                    play_again = true;
                    break;
                case 'y':
                    ask_play_again = false;
                    play_again = true;
                    break;
                case 'N':
                    ask_play_again = false;
                    play_again = false;
                    break;
                case 'n':
                    ask_play_again = false;
                    play_again = false;
                    break;
                default:  // if there is an error
                    printf(ERROR);
                    fgets(play, MAX, stdin);
            }
        }
    }
    return 0;
}


