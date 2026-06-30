// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 0;
    }
    string word = argv[1];
    
    for (int i = 0; word[i] != '\0'; i++)
    {
    switch (word[i]) {
    case 'a':
      printf("6");
      break;
    case 'e':
      printf("3");
      break;
    case 'i':
      printf("1");
      break;
    case 'o':
      printf("0");
      break;
    default:
      printf("%c",word[i]);
    }
    }
    printf("\n");
}
