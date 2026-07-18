#include <stdio.h>

int main() {
    char name[100];
    scanf("%s", name);
		
    // Print the greeting lines
  
    printf("Hello, ");
  	for (int i = 0; name[i] != '\0'; i++)
    {
    		printf("%c", name[i]);
    }
  	printf("!\n");
  	printf("Welcome to programming!\n");
}
