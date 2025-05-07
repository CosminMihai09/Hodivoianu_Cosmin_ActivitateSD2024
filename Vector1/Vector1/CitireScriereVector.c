//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX 100
//
//void citire(int v[], int *n)
//{
//	FILE* f = fopen("vector.txt", "r");
//
//	if (f == NULL) {
//		printf("Vector nu a putut fi citit.\n");
//	}
//
//	fscanf(f, "%d", n);
//
//	printf("Numarul de elemente al vectorului este %d\n", *n);
//
//	for (int i = 0; i < *n; i++)
//	{
//		fscanf(f, "%d", &v[i]);
//	}
//
//	printf("Vectorul citit este:\n");
//	for (int i = 0; i < *n; i++) {
//		printf("%d ", v[i]);
//	}
//	fclose(f);
//}
//
//int main() {
//	int v[MAX];
//	int n;
//	citire(v, &n);
//
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void citire(int v[], int* n)
{
	FILE* f = fopen("vector.txt", "r");

	if (f == NULL)
	{
		printf("Nu s-a putut citi fisierul.\n");
	}

	fscanf(f, "%d", n);

	printf("Numarul de elemente al vectorului este %d.\n", *n);

	for (int i = 0; i < *n; i++)
	{
		fscanf(f, "%d", &v[i]);
	}


	fclose(f);

	printf("Vectorul este:\n");
	for (int i = 0; i < *n; i++)
	{
		printf("%d ", v[i]);
	}
	
	return;
}

void scriere(int v[], int n) {
	FILE* f = fopen("outVector.txt", "w");

	fprintf(f, "%d\n", n);

	for (int i = 0; i < n; i++) {
		fprintf(f, "%d ", v[i]);
	}

	fclose(f);
}

//void insereaza(int v[], int* n, int poz, int val)
//{
//	if (poz <0 || poz > *n)
//	{
//		printf("Pozitia nu are sens.\n");
//		return;
//	}
//
//	if (*n >= MAX)
//	{
//		printf("Vectorul a ajuns la capacitatea maxima.\n");
//		return;
//	}
//
//	//Mutare elemente la dreapta
//	for (int i = *n; i > poz; i--)
//	{
//		v[i] = v[i - 1];
//	}
//
//	v[poz] = val;
//
//	(*n)++;
//
//	printf("Inserarea a fost realizata cu succes.\n");
//	printf("Iata vectorul:\n");
//	for (int i = 0; i < *n; i++) {
//		printf("%d ", v[i]);
//	}
//	return;
//}

//void sterge(int v[], int* n, int poz)
//{
//	for (int i = poz; i < *n-1; i++)
//	{
//		v[i] = v[i + 1];
//	}
//
//	(*n)--;
//}

void sterge(int v[], int* n, int poz)
{
	if (poz <0 || poz > *n) {
		printf("Pozitia este invalida\n");
	}

	for (int i = poz; i < *n - 1; i++)
	{
		v[i] = v[i + 1];
	}

	(*n)--;
}

void insereaza(int v[], int* n, int poz, int val)
{
	if (poz <0 || poz >*n)
	{
		printf("Pozitia este invalida\n");
	}

	if (*n > MAX) {
		printf("Vector la capacitate maxima\n");
	}

	for (int i = *n; i > poz; i--)
	{
		v[i] = v[i - 1];
	}

	v[poz] = val;

	(*n)++;
}

void citireDinFisier(int v[], int* n)
{
	FILE* f = fopen("vector.txt", "r");

	if (f == NULL) {
		printf("Fisierul nu a putut fi citit.\n");
	}

	fscanf(f, "%d", n);

	for (int i = 0; i < *n; i++) {
		fscanf(f, "%d ", &v[i]);
	}

	for (int i = 0; i < *n; i++)
	{
		printf("%d ", v[i]);
	}
}

int main()
{
	int n;
	int v[MAX];

	citireDinFisier(v, &n);
	insereaza(v, &n, 3, 123);
	sterge(v, &n, 1);
	scriere(v, n);
}