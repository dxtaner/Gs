#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int set_a[26] = {0};
    int set_b[26] = {0};

    // Count distinct characters in string 'a'
    for (int i = 0; a[i] != '\0'; i++) {
        set_a[a[i] - 'a'] = 1;
    }

    // Count distinct characters in string 'b'
    for (int i = 0; b[i] != '\0'; i++) {
        set_b[b[i] - 'a'] = 1;
    }

    // Compare the number of distinct characters
    int count_a = 0, count_b = 0;
    for (int i = 0; i < 26; i++) {
        count_a += set_a[i];
        count_b += set_b[i];
    }

    if (count_a < count_b) return -1;
    else if (count_a > count_b) return 1;

    // If counts are equal, compare lexicographically
    return strcmp(a, b);
}

int sort_by_length(const char* a, const char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);

    if (len_a < len_b) return -1;
    else if (len_a > len_b) return 1;

    // If lengths are equal, compare lexicographically
    return strcmp(a, b);
}

void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
    // Implement your sorting logic (e.g., bubble sort)
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (cmp_func(arr[j], arr[j + 1]) > 0) {
                // Swap strings if they are in the wrong order
                char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
