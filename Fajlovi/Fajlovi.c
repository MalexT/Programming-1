#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#define SCREEN_HEIGHT 25

void alal(char *s) {
	FILE *dat = fopen(s, "w");
	if (dat == NULL) {
		puts("Doslo je do greske...");
		return;
	}
	int broj;
	printf("Unesite neki broj\n");
	scanf("%d", &broj);
	for (int i = 1; i < broj; i++)
	{
		fprintf(dat, "%d\t%d\t%d\n", i, i*i, i*i*i);
	}
	fclose(dat);
}

void minIMaxUFajlu(char s[]) {
	int max, min, i;

	FILE *dat = fopen(s, "r");
	if (dat == NULL) {
		puts("Greska fajl ne postoji.");
		return;
	}
	if (fscanf(dat, "%d", &i) == EOF) {
		puts("Fajl je prazan.");
		return;
	}
	min = max = i;
	while (fscanf(dat,"%d",&i)!=EOF)
	{
		if (i>max)
		{
			max = i;
		}
		else if (min>i)
		{
			min = i;
		}
	}

	printf("Najveci broj u fajlu je %d, a najmanji je %d\n",max,min);
	fclose(dat);
}

void dupliranaVrednost(char s[],char t[]) {

	FILE *a, *b;
	int broj, i = 1;
	if ((a = fopen(s, "r")) == NULL) {
		puts("Greska prilikom citanja fajla.");
		return;
	}
	if ((b = fopen(t, "w")) == NULL) {
		puts("Greska pri otvaranju fajla.");
		return;
	}

	while (fscanf(a, "%d", &broj) != EOF) {
		fprintf(b, "%d\n", (i % 2 == 1) ? 2 * broj : broj);
		i++;
	}
	fclose(a);
	fclose(b);
}

int prostBroj(int a) {
	for (int i = 2; i < a; i++)
	{
		if (i%a == 0)
			return 0;
	}
	return 1;
}

int sumaCif(int a) {
	int suma = 0;
	while (a != 0) {
		suma += a % 10;
		a /= 10;
	}
	return suma;
}

void upisUfajl(char s[]) {
	FILE *ab;
	if ((ab = fopen(s, "w")) == NULL) {
		puts("Greska prilikom otvaranja fajla.");
		return;
	}
	for (int i = 100; i < 1000; i++)
	{
		if (sumaCif(i) % 2 == 0 && prostBroj(i) == 1) {
			fprintf(ab, "%d\n", i);
		}
	}
	fclose(ab);
}

void randomBrojeviUFajl(char s[]) {
	int niz[100];
	int dim;
	double arSredina;
	puts("Unesite dimenziju niza:");
	scanf("%d", &dim);
	for (int i = 0; i < dim; i++)
	{
		niz[i] = rand() % 2001 - 1000;

	}
	int suma = 0;
	for (int i = 0; i < dim; i++)
	{
		suma += niz[i];
	}
	arSredina = (double)suma / dim;
	for (int i = 0; i < dim; i++)
	{
		printf("%d\n", niz[i]);
	}

	FILE *dat = fopen(s, "w");
	if (dat == NULL) {
		puts("Greska prilikom otrvaranja fajla.");
		return;
	}

	for (int i = 0; i < dim; i++)
	{
		if (niz[i] > arSredina) {
			fprintf(dat, "%d\n", niz[i]);
		}
	}
	

	fclose(dat);
}

void malaUVelikaSlova(char s[], char t[]) {

	FILE *a, *b;
	char c;
	a = fopen(s, "r");
	if (a == NULL) {
		puts("Greska prilikom otvarnaja falja.");
		return;
	}
	b = fopen(t, "w");
	if (b == NULL) {
		puts("Greska prilikom otvarnaja falja.");
		return;
	}
	while ((c=fgetc(a))!=EOF)
	{
		if (c >= 'a' && c <= 'z') {
			c = c + 'A' - 'a';
			fputc(c, b);
		}
		else {
			fputc(c, b);
		}
		
	}

	fclose(a);
	fclose(b);
}

void slovaAuRecima(char s[]) {

	FILE *dat = fopen(s, "r");
	if (dat == NULL) {
		puts("Greska.");
		return;
	}
	char slovo = 'A';
	char rec[20];
	int brojac = 0;
	while (fscanf(dat, "%s", rec) != EOF) {
		if (strchr(rec, slovo) != NULL)
			brojac++;
	}
	printf("Ima %d reci sa bar jednim slovom 'A'...\n",brojac);
	fclose(dat);
}

void brojKarakteraUReci(char s[],char t[]) {
	FILE *data = fopen(t, "w");
	FILE *dat = fopen(s, "r");
	char rec[20];
	if (dat == NULL) {
		puts("Greska prilikom otvaranja falja.");
		return;
	}
	if (data == NULL) {
		puts("Greska prilikom otvaranja falja.");
		return;
	}

	while (fscanf(dat, "%s", rec) != EOF) {
		fprintf(data, "%s\t%d\n", rec, strlen(rec));
	}
	fclose(data);
	fclose(dat);
}

void zadatakNeki(char s[], char t[]) {
	FILE *a, *b;
	a = fopen(s, "r");
	b = fopen(t, "w");
	if (a == NULL) {
		puts("Greska kod a fajla.");
		return;
	}
	if (b == NULL) {
		puts("Greska kod fajla b");
		return;
	}
	char ca = '\n';
	char c;
	int duzinaReda = 0;
	int brojac = 0;
	int pom = 0;
	while ((c = fgetc(a)) != EOF) {
		pom++;
		if (c == ca) {
			brojac++;
			pom--;
		if (pom > duzinaReda)
			duzinaReda = pom;
		pom = 0;
		}
	}
	fprintf(b, "U prvom fajlu ima %d novih redova.\n",brojac);
	fprintf(b, "Najduza duzina reda je %d", duzinaReda);
}

void redoviIRec(char s[]) {
	FILE *dat = fopen(s, "r");
	if (dat == NULL) {
		puts("Doslo je do greske.");
		return;
	}
	char rec[50];
	puts("Unesite zeljenu rec za pretragu.");
	gets(rec);
	char red[81];
	while (fgets(red, 81, dat) != NULL) {
		if (strstr(red, rec)) {
			printf("%s", red);
		}
	}
	fclose(dat);
}

int meni() {
	
		printf("\n===========\n   MENI   \n=======\n\t1)Opcija 1\n\t2)Opcija 2\n\t3)Opcija 3\n\t0)Kraj rada.\n\n\t\tVas izbor je: \n");
		int izbor;
		scanf("%d", &izbor);
		return izbor;
}

void studentiAzurirani(char s[],char t[]) {

	FILE *a, *b;
	if ((a = fopen(s, "r")) == NULL) {
		puts("greska 'a'.");
		return;
	}
	if ((b = fopen(t, "w")) == NULL) {
		puts("greska 'b'.");
		return;
	}
	char ime[20], prezime[20], ime1[50][20], prezime1[50][20];
	int dan, mesec, godina;
	int dan1[50], mesec1[50], godina1[50];
	int j = 0;
	while (fscanf(a, "%s", prezime1[j]) != EOF) {
		fscanf(a, "%s %d %d %d", ime1[j], &dan1[j], &mesec1[j], &godina1[j]);

		for (int i = 0; i < j; i++)
		{
			if (godina1[j] < godina1[i]
				|| (godina1[j] == godina1[i] && mesec1[j] < mesec1[i])
				|| (godina1[j] == godina1[i] && mesec1[j] == mesec1[i] && dan1[j] < dan1[i])
				|| (godina1[j] == godina1[i] && mesec1[j] == mesec1[i] && dan1[j] == dan1[i] && strcmp(prezime1[j], prezime1[i]) < 0)
				|| (godina1[j] == godina1[i] && mesec1[j] == mesec1[i] && dan1[j] == dan1[i] && strcmp(prezime1[j], prezime1[i]) == 0) && strcmp(ime1[j], ime1[i]) < 0) {

				strcpy(prezime, prezime1[j]);
				strcpy(ime, ime1[j]);
				dan = dan1[j];
				mesec = mesec1[j];
				godina = godina1[j];
				
				strcpy(prezime1[j], prezime1[i]);
				strcpy(ime1[j], ime1[i]);
				dan1[j] = dan1[i];
				mesec1[j] = mesec1[i];
				godina1[j] = godina1[i];

				strcpy(prezime1[i], prezime);
				strcpy(ime1[i], ime);
				dan1[i] = dan;
				mesec1[i] = mesec;
				godina1[i] = godina;
			}
			j++;
		}
	}
	for (int i = 0; i < j; i++)
	{
		fprintf(b, "%s %s %d %d %d\n",prezime1[i],ime1[i],dan1[i],mesec1[i],godina1[i]);
	}
	fclose(a);
	fclose(b);
}

void prebaciUAzurirane(char s[], char t[], char a[]) {

	FILE *q, *b, *c;
	
	if ((q = fopen(s, "r")) == NULL) {
		puts("Greska kod a fajla.");
		return;
	}
	if ((b = fopen(t, "r")) == NULL) {
		puts("Greska kod b fajla");
		return;
	}
	if ((c = fopen(a, "w")) == NULL) {
		puts("Greska kod c fajla...");
		return;
	}

	char ime[20], prezime[20];
	int dan, mesec, ocena, godina, brojPolozenih;
	double prosek;
	while (fscanf(q, "%s", ime) != EOF) {

		fscanf(q, "%s %d %d %d %d %lf", prezime, &dan, &mesec, &godina, &brojPolozenih, &prosek);
		fscanf(b, "%d", &ocena);

		if ((godina<1965)|| (brojPolozenih<0)||(brojPolozenih>40) || (prosek<6)||(prosek>10) ||(ocena<5) || (ocena>10)) {
			fprintf(c, "%s %s %d %d %d %d %d %5.2lf Proveriti podatke.\n", ime, prezime, dan, mesec, godina, brojPolozenih, ocena, prosek);
		}
		else if (ocena > 5) {
			fprintf(c, "%s %s %d %d %d %d %d %5.2lf\n", ime, prezime, dan, mesec, godina, brojPolozenih, ocena, (prosek*brojPolozenih+ocena)/(brojPolozenih+1));
		}
		else
		{
			fprintf(c, "%s %s %d %d %d %d %d %lf\n", ime, prezime, dan, mesec, godina, brojPolozenih, ocena, prosek);
		}
	}
	fclose(q);
	fclose(b);
	fclose(c);
}



int main(void) {
	
	//alal("Datoteka.txt");
	//minIMaxUFajlu("File.txt");
	//dupliranaVrednost("File.txt", "Duplirani.txt");
	//upisUfajl("Trocifreni.txt");
	//randomBrojeviUFajl("Veci.txt");
	//malaUVelikaSlova("txt.txt", "Sva_velika_slova.txt");
	//slovaAuRecima("Sva_velika_slova.txt");
	//brojKarakteraUReci("NekiTekst.txt", "BoljiTekst.txt");
	//zadatakNeki("NekiTekst.txt", "Resenje.txt");
	//redoviIRec("Tekstualni.txt");
	//studentiAzurirani("Studenti.txt", "Azurirani.txt");
	//MENI:
	/*int izbor;
	do {
	izbor = meni();
		switch (izbor)
		{
		case 1:
			puts("Opcija 1.");
			break;
		case 2:
			puts("Opcija 2.");
			break;
		case 3:
			puts("Opcija 3.");
			break;
		case 0:
			puts("Kraj rada");
			break;
		default:
			puts("Pogresan izbor");
		}
	} while (izbor != 0);*/
	//prebaciUAzurirane("Student.txt", "Ispit.txt", "Azuriran.txt");
	



	system("pause");
	return 0;
}