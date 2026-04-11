#include <stdio.h>
#include <cs50.h>

int collatz(int n, int steps);

int main(void)
{
    int j = 0;
    int c = get_int("Put n: ");

    printf("%i\n", collatz(c, j));

}

int collatz(int n, int steps)
{
    if (n == 1)
        return steps;
    else if (n % 2 == 0)
    {
        steps++;
        return collatz(n/2, steps);
    }
    
    else if (n % 2 != 0)
    {
        steps++;
        return collatz(3*n+1, steps);
    }
}


