#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    // Declare variables to store input
    int int1, int2;
    float float1, float2;

    // Read two integers and two floating-point numbers from the user
    scanf("%d %d", &int1, &int2);
    scanf("%f %f", &float1, &float2);

    // Perform operations
    int sumInt = int1 + int2;
    int diffInt = int1 - int2;

    float sumFloat = float1 + float2;
    float diffFloat = float1 - float2;

    // Print the results
    printf("%d %d\n", sumInt, diffInt);
    printf("%.1f %.1f\n", sumFloat, diffFloat);

    return 0;
}
