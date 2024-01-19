#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *s;
    s = malloc(1024 * sizeof(char));

    // Read the sentence
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);

    // Use strtok to tokenize the sentence
    char *token = strtok(s, " ");

    // Iterate through the tokens and print each one
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    // Free the allocated memory
    free(s);

    return 0;
}
