#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
    // Если хотя бы один символ НЕ цифра
        if (!isdigit((unsigned char)argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int key = atoi(argv[1]);
    if (key < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key2 = key % 26;
    //printf("%i\n",key2);
    // Prompt user for plaintext
    string text = get_string("Plain text: ");
    printf("ciphertext: ");
    // For each character in the plaintext:
    for (int k = 0; k < strlen(text); k++)
    {
        if (isalpha(text[k]))
        {
            printf("%c", rotate(text[k], key2));
        }
        else
            printf("%c", text[k]);
    }
    printf("\n"); 
    // Rotate the character if it's a letter
}

char rotate(char c, int n)
{
    //if(!isalpha(c))
      //  return c;
    if (isupper(c))
    {
        int k = ((int) (c - 'A') + n) % 26; 
        char d = (char)(k + 'A');
        return d;
    }
    else if (islower(c))
    {
        int l = ((int) (c - 'a') + n) % 26; 
        char e = (char)(l + 'a');
        return e;
    }
    return 1;
}