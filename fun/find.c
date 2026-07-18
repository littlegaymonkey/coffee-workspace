#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[1000], b[1000];
    fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\n")] = 0;
    fgets(b, sizeof(b), stdin);
    b[strcspn(b, "\n")] = 0;
    
    // Define sizes of inputs
    int size_a = strlen(a);
    int size_b = strlen(b);
    // Define string for same letters
    char *letters = malloc(1000);
    if (letters == NULL)
    {
        /* code */
        return 1;
    }
    letters[0] = '\0';

    // Add same letters to letters string
    int indx = 0;
    bool all = false;
    for (int i = 0; i < size_b; i++)
    {
        all = false;
        for (int j = 0; j < size_a; j++)
        {
            if (a[j] == b[i])
            {
                if (indx == 0)
                {
                    letters[indx] = a[j];
                    indx++;
                    letters[indx] = '\0';
                }
                for (int k = 0; k < indx; k++)
                {
                    if (letters[k] == a[j])
                        all = true;
                }
                if (all == false)
                {
                    /* code */
                    letters[indx] = a[j];
                    indx++;
                    letters[indx] = '\0';
                }
            }
            break;
        }
    }

    // Check if is it no letters in letters string and return none
    if (indx == 0)
    {
        /* code */
        printf("none\n");
        return 0;
    }
    
    // Sort string of letters
    if (indx > 1)
    {
        for (int g = 0; g < indx - 1; g++)
        {
            int min = letters[g];
            char temp = letters[g];
            int min_ind = g;
            for (int h = g + 1; h < indx; h++)
            {
                if (letters[h] < min)
                {
                    /* code */
                    min_ind = h;
                    min = letters[h];
                }
            }
            if (min_ind != g)
            {
                /* code */
                letters[g] = letters[min_ind];
                letters[min_ind] = temp;
            }
        }
    }

    // Print all letters from letters string
    for (int l = 0; l < indx; l++)
    {
        /* code */
        printf("%c", letters[l]);
    }
    printf("\n");

    // Free mem from letter malloc
    free(letters);
}
