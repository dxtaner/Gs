#include <stdio.h>
#include <stdlib.h>

void update(int *a, int *b) {
    // Modify the value of 'a' to their sum
    *a = *a + *b;

    // Modify the value of 'b' to their absolute difference
    *b = abs(*a - 2 * (*b));
}

int main() {
    int a, b;

    // Input two integers
    scanf("%d%d", &a, &b);

    // Call the update function
    update(&a, &b);

    // Print the modified values
    printf("%d\n%d", a, b);

    return 0;
}
