#include <stdio.h>

int main() 
{
    // Declare a character array to store the input string
    char s[100];

    // Read input from the user
    scanf("%[^\n]%*c", s);

    // Print "Hello, World!" on one line
    printf("Hello, World!\n");

    // Print the input string on the next line
    printf("%s\n", s);

    return 0;
}
