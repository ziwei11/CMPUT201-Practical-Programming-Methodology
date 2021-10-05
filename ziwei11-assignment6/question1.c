#include <stdio.h>
#include <stdlib.h>
#define MAXIMUM_HEIGHT_OR_WIDTH 16000
#define FIXEDNUMBER 10
#define MAXIMUM_STRING 1024

enum cell {
    GRASSLAND,
    RIVER,
    NORTHWESTRIVERBEND,
    SOUTHWESTRIVERBEND,
    NORTHEASTRIVERBEND,
    SOUTHEASTRIVERBEND,
    NORTHEASTSOUTHFORK,
    NORTHWESTSOUTHFORK,
    WESTNORTHEASTFORK,
    WESTSOUTHEASTFORK,
    FOURWAYFORK
};
typedef enum cell Cell;


int store_the_number(int sum, int height, int width, Cell array[height][width]){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int success = scanf("%d", (int *)&array[i][j]);
            if (success == 1){
                ++sum;
                //sum = sum + 1;
            }
        }
    }
    return sum;
}


void four_way_fork(int row, int column, int height, int width,
                   Cell array[height][width], Cell array_temp[height][width]){
    if ((row - 1 >= 0) && (column - 1 >= 0) &&
        (row + 1 <= height - 1) && (column + 1 <= width - 1) &&
        (array[row - 1][column] == 1) && (array[row][column - 1] == 1) &&
            (array[row + 1][column] == 1) && (array[row][column + 1] == 1) &&
        (array[row][column] == 1)){
        array_temp[row][column] = FOURWAYFORK;
    }
}


void north_east_south_fork(int row, int column, int height, int width,
                           Cell array[height][width], Cell array_temp[height][width]){
    if ((row - 1 >= 0) && (row + 1 <= height - 1) &&
        (column + 1 <= width - 1) && (array[row - 1][column] == 1)  &&
            (array[row + 1][column] == 1) &&
        (array[row][column + 1] == 1) && (array[row][column] == 1)){
        array_temp[row][column] = NORTHEASTSOUTHFORK;
    }
}


void north_west_south_fork(int row, int column, int height, int width,
                           Cell array[height][width], Cell array_temp[height][width]){
    if ((row - 1 >= 0) && (column - 1 >= 0) &&
        (row + 1 <= height - 1) && (array[row - 1][column] == 1)  &&
            (array[row][column - 1] == 1) &&
        (array[row + 1][column] == 1) && (array[row][column] == 1)){
        array_temp[row][column] = NORTHWESTSOUTHFORK;
    }
}
    

void west_north_east_fork(int row, int column, int height, int width,
                          Cell array[height][width], Cell array_temp[height][width]){
    if ((row - 1 >= 0) && (column - 1 >= 0) &&
        (column + 1 <= width - 1) && (array[row - 1][column] == 1) &&
        (array[row][column - 1] == 1) &&
        (array[row][column + 1] == 1) && (array[row][column] == 1)){
        array_temp[row][column] = WESTNORTHEASTFORK;
    }
}


void west_south_east_fork(int row, int column, int height, int width,
                          Cell array[height][width], Cell array_temp[height][width]){
    if ((column - 1 >= 0) && (row + 1 <= height - 1) &&
        (column + 1 <= width - 1) && (array[row][column - 1] == 1) &&
        (array[row + 1][column] == 1) &&
        (array[row][column + 1] == 1) && (array[row][column] == 1)){
        array_temp[row][column] = WESTSOUTHEASTFORK;
    }
}


void north_west_river_bend(int row, int column, int height, int width,
                           Cell array[height][width], Cell array_temp[height][width]){
    if ((row - 1 >= 0) && (column - 1 >= 0) &&
        (array[row - 1][column] == 1) &&
        (array[row][column - 1] == 1) &&
        (array[row][column] == 1)){
        array_temp[row][column] = NORTHWESTRIVERBEND;
    }
}


void south_west_river_bend(int row, int column, int height, int width,
                           Cell array[height][width], Cell array_temp[height][width]){
    if ((column - 1 >= 0) &&
        (row + 1 <= height - 1) && (array[row][column - 1] == 1) &&
        (array[row + 1][column] == 1) && (array[row][column] == 1)){
        array_temp[row][column] = SOUTHWESTRIVERBEND;
    }
}


void north_east_river_bend(int row, int column, int height, int width,
                           Cell array[height][width], Cell array_temp[height][width]){
    if ((row - 1 >= 0) &&
        (column + 1 <= width - 1) && (array[row - 1][column] == 1) &&
        (array[row][column + 1] == 1) && (array[row][column] == 1)){
        array_temp[row][column] = NORTHEASTRIVERBEND;
    }
}


void south_east_river_bend(int row, int column, int height, int width,
                           Cell array[height][width], Cell array_temp[height][width]){
    if ((row + 1 <= height - 1) &&
        (column + 1 <= width - 1) && (array[row + 1][column] == 1) &&
        (array[row][column + 1] == 1) && (array[row][column] == 1)){
        array_temp[row][column] = SOUTHEASTRIVERBEND;
    }
}


void print_array(int height, int width, Cell array[height][width]){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            printf("%2d ", array[i][j]);
        }
        printf("\n");
    }
}


void temp_to_array(int height, int width,
                   Cell array[height][width], Cell array_temp[height][width]){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            array[i][j] = array_temp[i][j];
        }
    }
}


void print_variable(char * p_number, int width, int height, int number){
    printf("%s\n", p_number); // print p_number
    printf("%d ", width); // print width
    printf("%d\n", height); // print height
    printf("%d\n", number); // print number
}


int decide(const char * p_number, int width, int height, int number){
    if (p_number[0] != 'P'){
        printf("Invalid input!\n");
        return 0;
    }
    if (p_number[1] != '2'){
        printf("Invalid input!\n");
        return 0;
    }
    if (width > MAXIMUM_HEIGHT_OR_WIDTH || height > MAXIMUM_HEIGHT_OR_WIDTH){
        printf("Invalid input!\n");
        return 0;
    }
    if (number != FIXEDNUMBER){
        printf("Invalid input!\n");
        return 0;
    }
    return 1;
}


void fork_or_bend(int row, int column, int height, int width,
                  Cell array[height][width], Cell array_temp[height][width]){
    north_west_river_bend(row, column, height, width, array, array_temp);
    south_west_river_bend(row, column, height, width, array, array_temp);
    north_east_river_bend(row, column, height, width, array, array_temp);
    south_east_river_bend(row, column, height, width, array, array_temp);
    north_east_south_fork(row, column, height, width, array, array_temp);
    north_west_south_fork(row, column, height, width, array, array_temp);
    west_north_east_fork(row, column, height, width, array, array_temp);
    west_south_east_fork(row, column, height, width, array, array_temp);
    four_way_fork(row, column, height, width, array, array_temp);
}


void calculate(int height, int width, Cell array[height][width], Cell array_temp[height][width]){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            array_temp[i][j] = array[i][j];
            fork_or_bend(i, j, height, width, array, array_temp);
        }
    }
}


int main(){
    char p_number[MAXIMUM_STRING];
    int width;
    int height;
    int number;
    int sum = 0;
    scanf("%s", p_number); // scan p_number
    scanf("%d", &width); // scan width
    scanf("%d", &height); // scan height
    scanf("%d", &number); // scan number
    int decide_number = decide(p_number, width, height, number);
    if (decide_number == 0){
        return 0;
    }
    Cell array[height][width];
    sum = store_the_number(sum, height, width, array);
    if (sum != height * width){
        printf("Invalid input!\n");
        return 0;
    }
    Cell array_temp[height][width];
    calculate(height, width, array, array_temp);
    temp_to_array(height, width, array, array_temp);
    print_variable(p_number, width, height, number);
    print_array(height, width, array);
}


