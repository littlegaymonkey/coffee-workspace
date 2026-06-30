#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

float calc_hours(int weeks, int hours[], char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];
    int hour;
    char output;
    for (int i = 0; i < weeks; i++)
    {
        do
        {
            hour = get_int("Week %i HW Hours: ", i);    
        } while (isdigit(hour) && hour > 0);
        hours[i] = hour;
    }
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    } while (output != 'A' && output != 'a' && output != 'T' && output != 't');
    
    // TODO
    printf("%.1f hours\n", calc_hours(weeks, hours, output));   
}

float calc_hours(int weeks, int hours[], char output)
{
    float T = 0;
    float A = 0;
    if (output == 'T')
    {
        for (int i = 0; i < weeks; i++)
        {
            T += hours[i]; 
        }
        return T; 
    }
    else if (output == 'A')
    {
        for (int k = 0; k < weeks; k++)
        {
            A += hours[k]; 
        } 
        float Average = A / (float) weeks;
        return Average;
    }
}