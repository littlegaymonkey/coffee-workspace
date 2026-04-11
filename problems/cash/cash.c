#include <stdio.h>

int main(void)
{
    int cents;
    do
    {
        printf("Change owed: ");
        scanf("%i", &cents);
        if (cents <= 0)
        {
            printf("invalid input. Try again\n");
        }
    }
    while (cents < 0 || cents != 1);
    
    int coins = 0;

    int twfs = cents / 25;
    coins = cents - twfs * 25;
    int tens = coins / 10;
    coins = coins - tens * 10;
    int fif = coins / 5;
    coins = coins - fif * 5;
    int ones = coins / 1;
    coins = coins - ones * 1;
    int sum = twfs + tens + fif + ones;
    printf("%i\n", sum);
}

