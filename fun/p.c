#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char a[1000], b[1000];
    fgets(a, sizeof(a), stdin); a[strcspn(a, "\n")] = 0;
    fgets(b, sizeof(b), stdin); b[strcspn(b, "\n")] = 0;

    // Find and print common characters in sorted order
    char *letters = malloc(4);
    int indx = 0;
    letters[0] = 'a';
    printf("%i", strlen(letters));
    
}
