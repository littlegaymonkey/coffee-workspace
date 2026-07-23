#include <stdio.h>

struct car
{
    int year;
    char plate[10];
    int odometr;
    double engine;
};

int main(void)
{
    struct car my_car[10];
    printf("What is year? ");
    scanf("%i", &my_car[0].year);
    printf("year is %i\n", my_car[0].year);
}