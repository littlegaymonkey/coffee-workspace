// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dict file
    FILE *d = fopen("dictionary", "r");

    if (d == NULL)
    {
        // Print error : perror("Error opening file:");
        printf("Unable to open small dict");
        return false;
    }
    
    //Buffer for word
    char word[LENGTH + 1];
    
    // Loop for adding words into a array of word in memory
    while(fscanf(d, "%45s", word) != EOF)
    {
        // Create a new node for each word
        // Allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Not enough memory for node");
            return false;
        }
        strcpy(n->word, word);
        n->next = NULL;

        // Hash a word to obtain a hash value
        int index = hash(word);

        // Insert node into hash table at that location 
        // If is no words in hash index
        if (table[index] == NULL)
        {
            table[index] = n;
        }
        // If there a word on hash index
        else
        {
            n->next = table[index];
            table[index] = n;
        }
    }
    // Finish
    fclose(d);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
