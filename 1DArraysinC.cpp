#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Read the size of the array
    scanf("%d", &n);

    // Dynamically allocate an array of size n
    int *arr = (int*)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Exit with an error code
    }

    // Read values into the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate the sum of the elements
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Print the sum
    printf("%d\n", sum);

    // Free the allocated memory
    free(arr);

    return 0;
}
