#include <stdio.h>
#include <stdlib.h>
#define MODULE 10
#define MAXIMUM_ROUND 32000
#define MAXIMUM_HEIGHT_OR_WIDTH 16000

// print the array
void print_array(int height, int width, int array[height][width]){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

// set all elements in an array equal to 0
void set_to_zero(int height, int width, int array[height][width]){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            array[i][j] = 0;
        }
    }
}

// copy temperary array to old array
void temp_to_array(int height, int width, int array[height][width], int array_temp[height][width]){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            array[i][j] = array_temp[i][j];
        }
    }
}

// store the number of success input
int store_the_number(int sum, int height, int width, int array[height][width]){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int success = scanf("%d", &array[i][j]);
            if (success == 1){
                ++sum;
                //sum = sum + 1;
            }
        }
    }
    return sum;
}

// calculate the number in next round
void calculate_the_number(int rounds, int height, int width, int array[height][width]){
    for (int round = 1; round <= rounds; round++){
        printf("Round %d!\n", round);
        int array_temp[height][width];
        set_to_zero(height, width, array_temp);
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                if (i - 1 >= 0){
                    array_temp[i][j] = array_temp[i][j] + array[i - 1][j];
                }
                if (i + 1 <= height - 1){
                    array_temp[i][j] = array_temp[i][j] + array[i + 1][j];
                }
                if (j - 1 >= 0){
                    array_temp[i][j] = array_temp[i][j] + array[i][j - 1];
                }
                if (j + 1 <= width - 1){
                    array_temp[i][j] = array_temp[i][j] + array[i][j + 1];
                }
                array_temp[i][j] = (array_temp[i][j] + array[i][j]) % MODULE;
            }
        }
        temp_to_array(height, width, array, array_temp);
        print_array(height, width, array);
    }
}


int main(){
    int round;
    int height;
    int width;
    //int success = 0;
    int sum = 0;
    scanf("%d", &round); // scan round
    scanf("%d", &height); // scan height
    scanf("%d", &width); // scan width
    if (round > MAXIMUM_ROUND || height > MAXIMUM_HEIGHT_OR_WIDTH
        || width > MAXIMUM_HEIGHT_OR_WIDTH){
        printf("Invalid input!\n");
        return 0;
    }
    int array[height][width];
    set_to_zero(height, width, array);
    //sum = store_the_number(success, sum, height, width, array);
    sum = store_the_number(sum, height, width, array);
    if (sum != height * width){
        printf("Invalid input!\n");
        return 0;
    }
    printf("%d\n", round);
    printf("%d %d\n", height, width);
    print_array(height, width, array);
    calculate_the_number(round, height, width, array);
    return 0;
}


