#include <stdio.h>
#define NUMBER5 5
#define NUMBER10 10

int main() {
    int print[NUMBER5];
    for (int i = 0; i <= 4; i++){
        print[i] = i;
    }
    int ten = NUMBER10;
    int five = NUMBER5;
    print[ten] = five;
    return 0;
}

