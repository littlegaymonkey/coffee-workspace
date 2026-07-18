#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int main() {
    char a[1000], b[1000];
    fgets(a, sizeof(a), stdin); a[strcspn(a, "\n")] = 0;
    fgets(b, sizeof(b), stdin); b[strcspn(b, "\n")] = 0;

    // Find and print common characters in sorted order
    char *letters = malloc(1000);
    if (letters == NULL)
    {
        /* code */
        return 1;
    }
    letters[0] = '\0';
    
    int indx = 0;
    bool all = false;
    for (size_t i = 0; i < strlen(b); i++)
    {
        all = false;
        for (size_t j = 0; j < strlen(a); j++)
        {
            if (a[j] == b[i])
            {
                if (strlen(letters) == 0)
                {
                    letters[indx] = a[j];
                    indx++;
                    letters[indx] = '\0';
                }
                else 
                {
                    for (size_t k = 0; k < strlen(letters); k++)
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
            }
            /*printf("i is %i(%c) j is %i(%c) letters is ", i, b[i], j, a[j]);
            for (int l = 0; l < strlen(letters); l++)
            {
                printf("%c", letters[l]);
            }
            printf("\n"); */
        }
    }
    if (strlen(letters) == 0)
    {
        /* code */
        printf("none\n");
        return 0;
    }
    
    for (size_t g = 0; g < strlen(letters) - 1; g++)
    {
        int min = letters[g];
        char temp = letters[g];
        size_t min_ind = g;
        for (size_t h = g + 1; h < strlen(letters); h++)
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
    for (size_t l = 0; l < strlen(letters); l++)
    {
        /* code */
        printf("%c", letters[l]);
    }
    printf("\n");
    free(letters);
}
