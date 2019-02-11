#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void prikazMatrice(int mat[][10], int n, int m) {
	puts("MATRICA: \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf(" %d  ", mat[i][j]);
		}
		printf("\n");
	}
}
void ulazUIzlaz(int mat[][10], int *n, int *m) {
	FILE *a, *b;
	a = fopen("matrica.txt", "r");
	if (a == NULL) {
		puts("Greska. (a)");
		return;
	}
	b = fopen("izlaz.txt", "w");
	if (b == NULL) {
		puts("Greska. (b)");
		return;
	}
	fscanf(a, "%d %d", n, m);
	for (int i = 0; i < *m; i++)
	{
		for (int j = 0; j < *n; j++)
		{
			fscanf(a, "%d ", &mat[j][i]);
		}
	}
	prikazMatrice(mat, *n, *m);
	fclose(a);
	fclose(b);
}
typedef struct element* POK;
typedef struct element
{
	int frekv;
	int broj;
	POK sledeci;
}ELEMENT;
void ubaciUListu(POK *glava, int x, int frekvencija) {
	POK novi = malloc(sizeof(ELEMENT));
	novi->broj = x;
	novi->frekv = frekvencija;
	novi->sledeci = *glava;
	*glava = novi;
}
int frekvencija(int mat[][10], int n, int m, int broj) {
	int frekvencija = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mat[i][j] == broj) {
				frekvencija++;
			}
		}
	}
	return frekvencija;
}
int postojiUListi(POK glava, int broj1) {
	while (glava!=NULL)
	{
		if (glava->broj == broj1) {
			return 1;
		}
		glava = glava->sledeci;
	}
	return 0;
}
void frekvencijaElementaMatrice(POK *glava,int mat[][10],int n, int m) {
	int frekvencija1 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			frekvencija1 = frekvencija(mat, n, m, mat[i][j]);
			if (postojiUListi(*glava, mat[i][j]) == 0) {
				ubaciUListu(glava, mat[i][j], frekvencija1);
			}
		}
	}
}
void prikazListe(POK glava) {
	while (glava!=NULL)
	{
		printf("%d se javlja %d. puta\n", glava->broj, glava->frekv);
		glava = glava->sledeci;
	}
}

int main(void) {
	//int mat[10][10];
	//int n, m;
	//ulazUIzlaz(mat, &n, &m);
	//prikazMatrice(mat, n, m);
	//POK glava = NULL;
	//frekvencijaElementaMatrice(&glava, mat, n, m);
	//prikazListe(glava);

	(10 > 3) ? printf("Jeste\n") : printf("Nije\n");

	system("pause");
	return 0;
}