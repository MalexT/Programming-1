#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int prostBroj(int x) {
	if (x == 1)
		return 1;
	if (x == 0)
		return 1;
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0)
			return 1;
	}
	return 0;
}
void prikazNiza(int niz[], int dim) {
	for (int i = 0; i < dim; i++)
	{
		printf("%d ", niz[i]);
	}
	printf("\n");
}
void najduziPodnizProstih(int niz[], int n) {
	int pom[100];
	int najduzi[100];
	int pomBr = 0;
	int najdBr = 0;

	for (int i = 0; i < n; i++)
	{
		if (prostBroj(niz[i])==0) {
			pom[pomBr++] = niz[i];
		}
		else {
			if (najdBr < pomBr) {
				for (int j = 0; j < pomBr; j++)
				{
					najduzi[j] = pom[j];
					najdBr = pomBr;
				}
			}
			pomBr = 0;
		}
		if (prostBroj(niz[n])) {
			if (najdBr < pomBr) {
				for (int j = 0; j < pomBr; j++)
				{
					najduzi[j] = pom[j];
					najdBr = pomBr;
				}
			}
		}
	}
	prikazNiza(najduzi, najdBr);
}

typedef struct element* POK;
typedef struct element
{
	int broj;
	POK sledeci;
}ELEMENT;
int postojiUListi(POK glava, int broj) {

	while (glava != NULL) {
		if (glava->broj == broj) {
			return 1;
		}
		glava = glava->sledeci;
	}
	return 0;
}
void unosUListu(POK *glava, int x) {
	POK novi = malloc(sizeof(ELEMENT));
	novi->broj = x;
	novi->sledeci = *glava;
	*glava = novi;
}
void izDatotekeUMatricu(int mat[][5], POK *glava) {
	FILE *a = fopen("matrica.txt", "r");
	if (a == NULL) {
		printf("GRESKA.\n");
		return;
	}
	int brojac = 0;
	while (fscanf(a, "%d ") != EOF) {
		brojac++;
	}
	rewind(a);
	
	
	for (int i = 0; i < (brojac/2); i++)
	{
		for (int j = 0; j <(brojac/2); j++)
		{
			fscanf(a, "%d ", &mat[i][j]);

		}
	}
	
	for (int i = 0; i <(brojac/2); i++)
	{
		for (int j = 0; j <(brojac/2); j++)
		{
			if (*glava == NULL) {
				unosUListu(glava, mat[i][j]);
			}
			else {
				if(!postojiUListi(*glava, mat[i][j])) {
				unosUListu(glava, mat[i][j]);
				}
			}
		}
		
	}
	fclose(a);
}
void prikazListe(POK glava) {
	printf("Lista: \n");
	while (glava->sledeci != NULL) {
		printf("%d ", glava->broj);
		glava = glava->sledeci;
	}
	printf("\n");
}


void meni() {
	int izbor;

	do
	{
		printf("Korisnicki meni:\n\t1) Unesi novu prijavu\n\t2) Kreiraj izvestaj\n\t3) Kraj programa\n\t    Vas izbor:___");
		scanf("%d", &izbor);
		switch (izbor)
		{
		case 1:
			printf("Bla bla bla.\n");
			break;
		case 2:
			printf("abba abba abba.\n");
			break;
		case 3:
			system("cls");
			printf("Kraj rada.\n");
			break;
		default:
			printf("Losa opcija...\n Unesite ponovo\n");
			break;
		}

	} while (izbor!=3);
}


int main(void) {
	int mat[5][5];
	POK glava = NULL;
	int niz[100] = { 1,2,3,4,5,6,7,8,9,0,11,13,17,3,7};
	//najduziPodnizProstih(niz, 15);
	//izDatotekeUMatricu(mat,&glava);
	//prikazListe(glava);
	meni();
	//menu();

	system("pause");
	return 0;
}