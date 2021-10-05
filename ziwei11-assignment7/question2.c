#include <stdio.h>
#include <stdlib.h>
#define NUMBER5 5
#define BIGNUMBER 100000000000

int main() {
    int five = NUMBER5;
    int * print = (int *)malloc(five * sizeof(int));
    for (int i = 0; i <= 4; i++){
        print[i] = i;
    }
    printf("%d\n",print[BIGNUMBER]);
    return 0;
}


