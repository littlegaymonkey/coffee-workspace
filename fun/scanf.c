#include <stdio.h>

int main (void)
{
    int i;
    int *n = &i;
    //printf("Your number? It will be multiplied by 2. n = ");
    scanf("%i", &i);
    printf("n is :%p i is :%i i addr is :%p\n", n, i, &i);
    printf("int from addr n is: %i\n", *n);
}