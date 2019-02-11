#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>	
#include<string.h>
#include<ctype.h>

typedef struct element *POK;
typedef struct element
{
	int broj;
	POK sledeci;
}ELEMENT;

int nePostojiUListi(POK glava, int x) {
	while (glava!=NULL)
	{
		if (glava->broj == x)
			return 0;
		glava = glava->sledeci;
	}
	return 1;
}

void sortiranUnos(POK *glava, int x) {
	POK novi = malloc(sizeof(ELEMENT));
	novi->broj = x;
	novi->sledeci = NULL;
	if ((*glava) == NULL) {
		*glava = novi;
		return;
	}
	if (((*glava)->broj) > x) {
		novi->sledeci = *glava;
		*glava = novi;
		return;
	}
	POK tek = *glava;
	while (tek->sledeci!=NULL && tek->sledeci->broj<x)
	{
		tek = tek->sledeci;
	}
	novi->sledeci = tek->sledeci;
	tek->sledeci = novi;
}

void unosUSortiranuListu(POK *glava, int mat[][10], int dim) {

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if ((i == 0 || i == dim - 1 || j == 0 || j == dim - 1) && nePostojiUListi(*glava, mat[i][j])) {
				sortiranUnos(glava, mat[i][j]);
			}
		}
	}
}

void prikazListe(POK glava) {
	printf("\nElementi liste koji se jednom javljaju u njoj:\n");
	while (glava!=NULL)
	{
		printf("%d  ", glava->broj);
		glava = glava->sledeci;
	}
	printf("\n");
}

void prikazMatrice(int mat[][10],int dim) {
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
}

void ucitajIzFajlaUMatricu(int mat[][10], int *dim) {

	FILE *a = fopen("matrica.txt", "r");
	if (a == NULL) {
		printf("Greska pri otvaranju matrice.\n");
		return;
	}
	fscanf(a, "%d,",dim);
	for (int i = 0; i < *dim; i++)
	{
		for (int j = 0; j < *dim; j++)
		{
			fscanf(a, "%d,",&mat[i][j]);
		}
	}
	prikazMatrice(mat, *dim);
	fclose(a);
}

void prikazNiza(int niz[], int dim) {
	printf("\n");
	for (int i = 0; i < dim; i++)
	{
		printf("%d  ", niz[i]);
	}
	printf("\n");
}

void nizOdElemenataUnutrasnjosti(int mat[][10], int dim, int niz[], int *dim1) {
	for (int i = 1; i < dim-1; i++)
	{
		for (int j = 1; j < dim-1; j++)
		{
				niz[(*dim1)++] = mat[i][j];
		}
	}
	prikazNiza(niz, *dim1);
}



int main(void) {
	int mat[10][10];
	int dim = 0;
	int niz[100];
	int dim1 = 0;
	ucitajIzFajlaUMatricu(mat, &dim);
	//nizOdElemenataUnutrasnjosti(mat, dim, niz, &dim1);
	POK glava = NULL;
	unosUSortiranuListu(&glava, mat, dim);
	prikazListe(glava);

	system("pause");
	return 0;
}