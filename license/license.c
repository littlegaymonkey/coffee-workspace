#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Open file
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("no such file\n");
        return 1;
    }   

    // Create buffer to read into
    char *buffer = malloc(8);

    // Create array to store plate numbers
    char plates[8][7];

    

    // Create index for copying
    int idx = 0;

    // Itterate thgru all file to copy a string
    while (fread(buffer, 1, 7, infile) == 7)
    {
        // For loop for copying every char to array of our string
        for (int j = 0; j < 7; j++)
        {
            if (j == 6)
                plates[idx][6] = '\0';
            else
                plates[idx][j] = buffer[j];
        }
        idx++;
    }

    // Print all strings from our array       
    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);
    }

    // Free buffer and close a file
    free(buffer);
    fclose(infile);
}
