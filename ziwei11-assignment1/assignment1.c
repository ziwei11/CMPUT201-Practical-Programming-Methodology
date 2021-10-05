#include <stdio.h>

int main()
{
    char name[1024], quest[1024], color[1024];
    printf("Hello World!\n");
    printf("I was written by Vicky Zhao\n");
    printf("Bridgekeeper: What...is your name?\n");
    fgets(name, 1024, stdin);
    printf("Bridgekeeper: Ahh your name is %s", name);
    printf("Bridgekeeper: What...is your quest?\n");
    fgets(quest, 1024, stdin);
    printf("Bridgekeeper: Ahh your purpose is %s", quest);
    printf("Bridgekeeper: What...is your favorite colour?\n");
    fgets(color, 1024, stdin);
    printf("Bridgekeeper: Ahh your favorite colour is %s", color);
    printf("Bridgekeeper: Right, off you go.\n");

    return 0;
}
