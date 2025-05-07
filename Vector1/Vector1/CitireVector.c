#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void citire(int v[], int *n)
{
	FILE* f = fopen("vector.txt", "r");

	if (f == NULL) {
		printf("Vector nu a putut fi citit.\n");
	}

	fscanf(f, "%d", n);

	printf("Numarul de elemente al vectorului este %d\n", *n);

	for (int i = 0; i < *n; i++)
	{
		fscanf(f, "%d", &v[i]);
	}

	printf("Vectorul citit este:\n");
	for (int i = 0; i < *n; i++) {
		printf("%d ", v[i]);
	}
	fclose(f);
}

int main() {
	int v[MAX];
	int n;
	citire(v, &n);

	return 0;
}