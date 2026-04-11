#include <stdio.h>
#include <cs50.h>

int collatz(int n);

int main(void)
{
    int c = get_int("Put n: ");

    printf("%i\n", collatz(c));

}

int collatz(int n)
{
    if (n == 1)
        return 0;
    else if (n % 2 == 0)
        return 1 + collatz(n/2);
    else 
        return 1 + (3*n+1);
}


