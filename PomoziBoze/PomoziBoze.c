#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct element* POK;
typedef struct element
{
	int broj;
	POK sledeci;
}ELEMENT;

void dodajSortirano(POK *glava, int x) {
	POK novi = malloc(sizeof(ELEMENT));
	novi->broj = x;
	novi->sledeci = NULL;

	if (*glava == NULL) {
		*glava = novi;
		return;
	}
	if ((*glava)->broj < x) {
		novi->sledeci = *glava;
		*glava = novi;
	}
	POK tek = *glava;
	while (tek->sledeci != NULL && tek->sledeci->broj > x)
	{
		tek = tek->sledeci;
	}
	novi->sledeci = tek->sledeci;
	tek->sledeci = novi;
}

int zbirCifaraBroja(int broj) {
	int suma = 0;
	while (broj != 0) {
		suma += broj % 10;
		broj /= 10;
	}
	return suma;
}
int palindrom(int broj) {
	int pom = 0;
	int br = broj;
	int cifre=0;
	while (br!=0)
	{
		pom = br % 10;
		cifre = cifre * 10 + pom;
		br /= 10;
	}
	if (cifre == broj)
		return 1;
	else
		return 0;
}
int palindromV2(int broj) {
	char s[100];
	_itoa(broj, s, 10);

	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] != s[strlen(s) - i - 1]) {
			return 0;
		}
	}
	return 1;
}
void brojSaNajvecimZbirom() {
	int niz[100];
	int brEl = 0;
	int broj = 0;
	while (1)
	{
		scanf("%d", &broj);
		if (broj == 0) {
			break;
		}
		niz[brEl++] = broj;
	}
	int max = niz[0];
	for (int i = 0; i < brEl; i++)
	{
		if (zbirCifaraBroja(niz[i]) > (zbirCifaraBroja(max))) {
			max = niz[i];
		}
	}
	printf("Broj sa najvecim zbirom je: %d\n", max);
}
void trocifreni13() {
	int brojac = 0;
	for (int i = 100; i < 1000; i++)
	{
		if (zbirCifaraBroja(i) == 13 && i % 2 == 0) {
			brojac++;
		}
	}
	printf("%d\n\n\n\n", brojac);
}




int main(void) {
	//brojSaNajvecimZbirom();
	trocifreni13();
	system("pause");
	return 0;
}