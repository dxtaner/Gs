#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

double calculate_area(triangle tr) {
    double s = (tr.a + tr.b + tr.c) / 2.0;
    return sqrt(s * (s - tr.a) * (s - tr.b) * (s - tr.c));
}

// Function to compare triangles based on their areas (used for sorting)
int compare_areas(const void *a, const void *b) {
    double area_a = calculate_area(*(const triangle *)a);
    double area_b = calculate_area(*(const triangle *)b);

    if (area_a < area_b) return -1;
    else if (area_a > area_b) return 1;
    else return 0;
}

// Function to sort an array of triangles based on their areas
void sort_by_area(triangle* tr, int n) {
    qsort(tr, n, sizeof(triangle), compare_areas);
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
