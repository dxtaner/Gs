#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    // Calculate the sum of the digits
    int sum = 0;
    
    // Loop through each digit using modulo 10
    for (int i = 0; i < 5; i++) {
        int digit = n % 10;
        sum += digit;
        n /= 10;
    }

    printf("%d\n", sum);

    return 0;
}
