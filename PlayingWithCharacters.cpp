#include <stdio.h>

int main() {
    char ch;
    char string[100];
    char sentence[100];

    // Take a character as input
    scanf("%c", &ch);
    printf("%c\n", ch);

    // Take a string as input
    scanf("%s", string);
    printf("%s\n", string);

    // Take a sentence as input
    scanf(" %[^\n]%*c", sentence);
    printf("%s\n", sentence);

    return 0;
}
