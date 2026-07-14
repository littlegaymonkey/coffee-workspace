#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK 512

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./recover 'file' \n");
        return 1;
    }
    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open '%s'.\n", argv[1]);
        return 1;
    }
    // Create a buffer for a block of data
    int index = 0;
    uint8_t buffer[BLOCK];
    // While there's still data left to read from the memory card
    while (fread(buffer, 1, BLOCK, card) == BLOCK)
    {
        char name_buffer[8];
        sprintf(name_buffer, "%03i.jpg", index);
        FILE *photo = fopen(name_buffer, "a");
        if (photo == NULL)
        {
            printf("Could not write a '%s'.\n", name_buffer);
            return 1;
        }    
        // Create JPEGs from the data
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {         
            if (index == 0)
            {
            sprintf(name_buffer, "%03i.jpg", index);
            FILE *photo = fopen(name_buffer, "w");
            if (photo == NULL)
            {
                printf("Could not write a '%s'.\n", name_buffer);
                return 1;
            }
                fwrite(buffer, 1, BLOCK, photo);
            }
            else
            {
                fclose(photo);
                index++;
                sprintf(name_buffer, "%03i.jpg", index);
                FILE *photo = fopen(name_buffer, "w");
                if (photo == NULL)
                {
                    printf("Could not write a '%s'.\n", name_buffer);
                    return 1;
                }
                fwrite(buffer, 1, BLOCK, photo);
            }    
        }
        else
        {
            fwrite(buffer, 1, BLOCK, photo);
            fclose(photo);
        }
    }

    fclose(card);
}