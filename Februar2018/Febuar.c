#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct element* POK;
typedef struct element
{
	int broj;
	POK sledeci;
}ELEMENT;

int palindrom(int broj) {
	int pom = broj;
	int br = 0;
	int pamcenje = 0;

	if (broj < 10) {
		return 0;
	}

	while (pom != 0) {
		pamcenje = pom % 10;
		br = br * 10 + pamcenje;
		pom /= 10;
	}
	if (br == broj) {
		return 1;
	}
	else {
		return 0;
	}
}

void unosIUpis() {
	FILE *a, *b;
	a = fopen("palindrom.txt", "w");
	if (a == NULL) {
		printf("Greska.\n");
		return;
	}
	b = fopen("ostali_brojevi.txt", "w");
	if (b == NULL) {
		printf("Greska.\n");
		return;
	}
	printf("Unosite brojeve: \n");
	int broj;
	while (1)
	{
		scanf("%d", &broj);
		if (broj == 0) {
			break;
		}
		if (palindrom(broj)) {
			fprintf(a, "%d\n", broj);
		}
		else {
			fprintf(b, "%d\n", broj);
		}
	}
	fclose(a);
	fclose(b);
}

void prikazDatoteka() {
	FILE *a, *b;
	a = fopen("palindrom.txt", "r");
	b = fopen("ostali_brojevi.txt", "r");
	if (a == NULL) {
		printf("Greska kod a.\n");
		return;
	}
	if (b == NULL) {
		printf("Greska kod b.\n");
		return;
	}
	char red[10];
	printf("\nPalindromi: \n");
	while (fgets(red,10,a)!=NULL)
	{
		printf("%s", red);
	}
	if (fgets(red, 10, b) == NULL) {
		printf("\nOstali brojevi: \n");
	}
	while (fgets(red,10,b)!=NULL)
	{
		printf("%s", red);
	}

	fclose(a);
	fclose(b);
}

void upisPoObodu(int mat[][4],int n) {
	FILE *a = fopen("palindrom.txt", "r");
	if (a == NULL) {
		printf("Greska.\n");
		return;
	}
		int niz[100];
		int brEl = 0;
		int broj;
	while (1) {
		fscanf(a, "%d", &broj);
		niz[brEl++] = broj;
		if (fscanf(a, "%d", &broj) == EOF)
		{
			break;
		}
		else {
			niz[brEl++] = broj;
		}
	 }
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 || i == n-1 || j == 0 || j == n-1) {
				mat[i][j] = niz[k++];
			}
			if (k == brEl) {
				k = 0;
			}
		}
	}
	fclose(a);
}

void prikazMatrice(int mat[][4],int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
}

void unosUListu(POK *glava, int x) {
	POK novi = malloc(sizeof(ELEMENT));
	novi->broj = x;
	novi->sledeci = *glava;
	*glava = novi;
}

void palindromUListu(POK *glava) {
	printf("Unosite brojeve:\n");
	int broj;
	while (1)
	{
		scanf("%d", &broj);
		
		if (broj == 0) {
			break;
		}
		if (palindrom(broj)) {
			unosUListu(glava, broj);
		}
	}
}

void prikazSadrzajaListe(POK glava) {
	POK tek = glava;
	puts("Sadrzaj liste:");
	while (tek!=NULL)
	{
		printf("%d\t", tek->broj);
		tek = tek->sledeci;
	}
}

void elementiIzmedjuPozicija(POK glava) {
	int poc, kraj;
	printf("\nUnesite pozicije: \n");
	scanf("%d %d", &poc, &kraj);
	
	POK tek = glava;
	int brojac=0;
	while (tek != NULL)
	{
		brojac++;
		tek = tek->sledeci;
	}

	if (poc<0 || kraj>brojac) {
		printf("indeks out of bounds [1-%d]", brojac);
		return;
	}
	tek = glava;
	POK pooc = glava;
	POK kraaj = NULL;
	int pocetak = 0;
	while (tek->sledeci != NULL && (poc-1) != pocetak) {
		pocetak++;
		tek = tek->sledeci;
	}
	pooc = tek;
	tek = glava;
	while (tek->sledeci != NULL && kraj < brojac) {
		kraaj = tek;
		tek = tek->sledeci;
	}
	printf("\nTrazeni elementi su:\n");
	while (pooc!=kraaj)
	{
		printf("%d ", pooc->broj);
		pooc = pooc->sledeci;
	}
}

void najduziJednakiBrojevei() {





}




int main(void) {
	POK glava = NULL;
	//unosIUpis();
	//prikazDatoteka();
	int mat[5][5] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	//upisPoObodu(mat, 4);
	//prikazMatrice(mat, 4);
	palindromUListu(&glava);
	prikazSadrzajaListe(glava);
	elementiIzmedjuPozicija(glava, 1, 3);
	system("pause");
	return 0;
}