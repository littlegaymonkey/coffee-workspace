#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct car
{
    int year;
    char plate[5];
    int odometr;
    double engine;
};

int main(void)
{
    struct car *mycar = malloc(sizeof(struct car));
    printf("What is year? ");
    mycar->year = 2015;
    printf("year is %i\n", mycar->year);
    printf("What is plate? ");
    strcpy(mycar->plate, "CS50");
    printf("plate is %s\n", mycar->plate);
}