#include <stdio.h>
#include <cs50.h>

int collatz(int k);

int main(void)
{
    int n = get_int("What 'n' is? ");
    printf("%i\n", collatz(n));
}

int collatz(int k)
{
    if (k == 1)
        return 0;
    else if ( k % 2 == 0) // n/2
        return 1 + collatz(k/2);
    else // 3n + 1 
        return 1 + collatz(3*k + 1);
}
