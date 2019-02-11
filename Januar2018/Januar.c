#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include<stdio.h>	
#include<string.h>
#include<ctype.h>

typedef struct element *POKAZIVAC;

typedef struct element{
	int broj;
	POKAZIVAC sledeci;
}ELEMENT;


int zbirCifaraBroja(int broj) {
	int suma = 0;

	while (broj!=0)
	{
		suma += broj % 10;
		broj = broj / 10;
	}

	return suma;
}

void brojSaNajvecimZbirom() {
	int niz[100];
	int dim;
	puts("Koliko brojeva zelite da unesete: ");
	scanf("%d", &dim);
	for (int i = 0; i < dim; i++)
	{
		scanf("%d", &niz[i]);
	}
	int privSuma = zbirCifaraBroja(niz[0]);
	int poz = 0;
	for (int i = 1; i < dim; i++)
	{
		if (zbirCifaraBroja(niz[i]) > privSuma) {
			privSuma = zbirCifaraBroja(niz[i]);
			poz = i;
		}
	}
	printf("Broj sa najvecom sumom cifara je %d a ona iznosi %d\n", niz[poz], privSuma);
}

int brojTrocifrenihParnihSaSumom13() {

	int brojac = 0;
	for (int i = 100; i < 1000; i++)
	{
		if (i % 2 == 0 && zbirCifaraBroja(i) == 13) {
			brojac++;
		}
	}
	return brojac;
}

void prikaziListu(POKAZIVAC glava) {
	if (glava == NULL) {
		puts("Greska");
		return;
	}
	
	while (glava != NULL) {
		printf("%d ", glava->broj);
		glava = glava->sledeci;
	}
	printf("\n");
}

void trocifreniUListu(POKAZIVAC *glava, int broj) {

	POKAZIVAC tek;
	POKAZIVAC preth;

	for (int i = 100; i < 1000; i++)
	{
		if (i % 2 == 0 && zbirCifaraBroja(i) == broj) { // fali da je paran
			POKAZIVAC novi = malloc(sizeof(ELEMENT));
			novi->broj = i;
			novi->sledeci = NULL;

			if ((*glava) == NULL) {
				*glava = novi;
			}
			else {
				preth = NULL;
				tek = *glava;
				while (tek != NULL && tek->broj <= i) {
					preth = tek;
					tek = tek->sledeci;
				}
				if (tek!=NULL) {
					preth->sledeci = novi;
				}
				else
				{
					if (preth) {
						novi->sledeci = preth->sledeci;
						preth->sledeci = novi;
					}
					else {
						novi->sledeci = glava;
						*glava = novi;
					}
				}
			}
		}
	}
}

void trocifreniParniSuma14UDatoteku() {

	FILE *a = fopen("100.txt", "w");
	FILE *b = fopen("200.txt", "w");
	FILE *c = fopen("300.txt", "w");
	FILE *d = fopen("400.txt", "w");
	FILE *e = fopen("500.txt", "w");
	FILE *f = fopen("600.txt", "w");
	FILE *g = fopen("700.txt", "w");
	FILE *h = fopen("800.txt", "w");
	FILE *k = fopen("900.txt", "w");

	fprintf(a, "Brojevi 1.stotine:\n");
	fprintf(b, "Brojevi 2.stotine:\n");
	fprintf(c, "Brojevi 3.stotine:\n");
	fprintf(d, "Brojevi 4.stotine:\n");
	fprintf(e, "Brojevi 5.stotine:\n");
	fprintf(f, "Brojevi 6.stotine:\n");
	fprintf(g, "Brojevi 7.stotine:\n");
	fprintf(h, "Brojevi 8.stotine:\n");
	fprintf(k, "Brojevi 9.stotine:\n");

	for (int i = 100; i < 200; i++)
	{
		if (i % 2 == 0 && zbirCifaraBroja(i) == 14) {
			fprintf(a, "%d;", i);
		}
	}
	for (int i = 200; i < 300; i++)
	{
		if (i % 2 == 0 && zbirCifaraBroja(i) == 14) {
			fprintf(b, "%d;", i);
		}
	}
	for (int i = 300; i < 400; i++)
	{
		if (i % 2 == 0 && zbirCifaraBroja(i) == 14) {
			fprintf(c, "%d;", i);
		}
	}
	for (int i = 400; i < 500; i++)
	{
		if (i % 2 == 0 && zbirCifaraBroja(i) == 14) {
			fprintf(d, "%d;", i);
		}
	}
	for (int i = 500; i < 600; i++)
	{
		if (i % 2 == 0 && zbirCifaraBroja(i) == 14) {
			fprintf(e, "%d;", i);
		}
	}
	for (int i = 600; i < 700; i++)
	{
		if (i % 2 == 0 && zbirCifaraBroja(i) == 14) {
			fprintf(f, "%d;", i);
		}
	}
	for (int i = 700; i < 800; i++)
	{
		if (i % 2 == 0 && zbirCifaraBroja(i) == 14) {
			fprintf(g, "%d;", i);
		}
	}
	for (int i = 800; i < 900; i++)
	{
		if (i % 2 == 0 && zbirCifaraBroja(i) == 14) {
			fprintf(h, "%d;", i);
		}
	}
	for (int i = 900; i < 1000; i++)
	{
		if (i % 2 == 0 && zbirCifaraBroja(i) == 14) {
			fprintf(k, "%d;", i);
		}
	}

	fclose(a);
	fclose(b);
	fclose(c);
	fclose(d);
	fclose(e);
	fclose(f);
	fclose(g);
	fclose(h);
	fclose(k);
	

}

int postojiUNizu(int niz[], int brEl, int a) {
	if (brEl == 0) {
		return 0;
	}
	for (int i = 0; i < brEl; i++)
	{
		if (niz[i] == a)
			return 1;
	}
	return 0;
}

void unijaElemenataUNoviNiz(int mat[][5], int kol1, int kol2) {

	int niz[20];
	int a = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((j == (kol1-1) || j == (kol2-1)) && postojiUNizu(niz, a, mat[i][j])==0 ) {
				niz[a++]=mat[i][j];
			}
		}
	}

	for (int k = 0; k < a; k++)
	{
		printf("%d\t", niz[k]);
	}
	printf("\n");
}

void prikaziMat(int mat[][5]) {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}


}

int main(void) {

	int mat[5][5] = { 1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5 };
	prikaziMat(mat);
	unijaElemenataUNoviNiz(mat, 2, 3);
	printf("%d\n", zbirCifaraBroja(12467812));
	printf("Ima %d trocifrenih brojeva koji su parni i ciji je zbir cifara 13.\n", brojTrocifrenihParnihSaSumom13());
	puts("\n");
	brojSaNajvecimZbirom();
	trocifreniParniSuma14UDatoteku();
	POKAZIVAC glava = NULL;
	trocifreniUListu(&glava, 13);
	prikaziListu(glava);

	system("pause");
	return 0;
}