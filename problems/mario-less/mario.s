#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        printf("Height: ");
        scanf("%i", &n);
        if (n <= 0 || n >= 25)
        {
            printf("invalid input. Try again between 1 and 24\n");
        }
    }
    
    while (n <= 0 || n >= 25);    
    int j = n;
    while (j > 0)
    {
        for (int row = 0; row < n; row++)
        {
         
            for (int column_p = 0; column_p < j - 1; column_p++)
            {
                printf(" ");
            }
            for (int column = 0; column < n - j + 1; column++)
            {           
                printf("#");
            }
            j -= 1;
            printf("\n");
        }
    }     
}

