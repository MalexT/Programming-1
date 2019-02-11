#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void unosSaTastature() {

	char niz[100];
	char c;
	int i = 0;
	puts("Unesite karaktere:");
	while (1)
	{
		scanf("%c", &c);
		if (c == '-') {
			break;
		}
		else if (isdigit(c)) {
			niz[i++] = c;
		}
	}
	
	char a;
	int b;
	int Brojevi[100];
	int k = 0;

	for (int j = 0; j < i; j++)
	{
		a = niz[j];
		b = a - '0';
		Brojevi[k++] = b;

	}

	int najduzi[100];
	int zapamti[100];
	int brZapamti = 0;
	int brNajduzi = 0;


	for (int q = 0; q < k; q++)
	{
		if (Brojevi[q] % 2 == 0) {
			zapamti[brZapamti++] = Brojevi[q];
		}
		else {
			if (brNajduzi < brZapamti) {
				for (int w = 0; w < brZapamti; w++)
				{
					najduzi[w] = zapamti[w];
					brNajduzi = brZapamti;
				}
			}
			brZapamti = 0;
		}
	}
	
	for (int l = 0; l < brNajduzi; l++)
	{
		printf("%d  ", najduzi[l]);
	}
	printf("\n");

}

//typedef struct polaganje
//{
//	int ocena;
//	char sifraPredmata[10];
//
//}POLAGANJE;
//
//typedef struct cvorp* PCVORP;
//
//typedef struct cvorp
//{
//	POLAGANJE podatak;
//	PCVORP sledeci;
//}CVORP;
//
//
//typedef struct student
//{
//	char imePrezime[51];
//	char indeks[10];
//	PCVORP listaPP;
//
//}STUDENT;
//
//typedef struct cvors* PCVORS;
//
//typedef struct cvors
//{
//	STUDENT podatak;
//	PCVORS sledeci;
//
//}CVORS;
//
//void ubaciStudenta(PCVORS *pglavas, STUDENT s) {
//	PCVORS novi = malloc(sizeof(CVORS));
//	novi->podatak = s;
//	novi->sledeci = *pglavas;
//	*pglavas = novi;
//}
//
//void ubaciPolaganje(PCVORP* pglavap, POLAGANJE p) {
//	PCVORP novi = malloc(sizeof(CVORP));
//	novi->podatak = p;
//	novi->sledeci = *pglavap;
//	*pglavap = novi;
//}
//
//void prikaziPolaganja(PCVORP glava) {
//	while (glava != NULL)
//	{
//		printf("%s: %d\t", glava->podatak.sifraPredmata, glava->podatak.ocena);
//		glava = glava->sledeci;
//	}
//
//}
//
//
//void prikaziStudente(PCVORS lista) {
//	while (lista != NULL)
//	{
//		printf("\n%s\t%s\nPolaganja: ", lista->podatak.imePrezime, lista->podatak.indeks);
//		prikaziPolaganja(lista->podatak.listaPP);
//		printf("\n");
//		lista = lista->sledeci;
//	}
//}
//
//
//
//void ucitajStudente(PCVORS * pglavas) {
//
//	FILE *fajl = fopen("Studenti.txt", "r");
//	if (fajl == NULL) {
//		puts("Greska u otvaranju fajla.");
//		return;
//	}
//	char linija[100];
//
//	while (fgets(linija, 100, fajl) != NULL) {
//		STUDENT s;
//		s.listaPP = NULL;
//		char *token;
//		token = strtok(linija, ";");
//		strcpy(s.imePrezime, token);
//		token = strtok(NULL, ";");
//		strcpy(s.indeks, token);
//		while ((token=strtok(NULL,";\n")) != NULL) {
//			POLAGANJE p;
//			char a;
//			int ocena1;
//			strcpy(p.sifraPredmata, token);
//			token = strtok(NULL, ";");
//			p.ocena = atoi(token);
//			ubaciPolaganje(&s.listaPP, p);
//		}
//		ubaciStudenta(pglavas, s);
//	}
//	fclose(fajl);
//}

typedef struct polaganje
{
	int ocena;
	char sifraPredmeta[11];
}POLAGANJE;

typedef struct pnode* PPOK;
typedef struct pnode
{
	POLAGANJE podatak;
	PPOK sledeci;
}PNODE;

typedef struct snode* SPOK;
typedef struct student
{
	char indeks[9];
	char imePrezime[51];
	double prosecnaOcena;
	PPOK listaPP;
}STUDENT;

typedef struct snode
{
	STUDENT podatak;
	SPOK sledeci;
}SNODE;

void dodajStudenta(SPOK *glava, STUDENT s) {
	SPOK novi = malloc(sizeof(SNODE));
	novi->podatak = s;
	novi->sledeci = *glava;
	*glava = novi;
}

void dodajPolaganje(PPOK *glava, POLAGANJE p) {
	PPOK novi = malloc(sizeof(PNODE));
	novi->podatak = p;
	novi->sledeci = *glava;
	*glava = novi;
}


void ucitajIzFajla(SPOK *glava) {

	FILE *fajl = fopen("Studenti.txt", "r");
	if (fajl == NULL) {
		printf("Greska pri otvaranju.\n");
		return;
	}
	char red[100];
	while (fgets(red, 100, fajl) != NULL) {
		STUDENT s;
		s.listaPP = NULL;
		char *token;
		token = strtok(red, ";");
		strcpy(s.imePrezime, token);
		token = strtok(NULL, ";");
		strcpy(s.indeks, token);
		while ((token = strtok(NULL, ";\n"))!=NULL)
		{
			POLAGANJE p;
			strcpy(p.sifraPredmeta, token);
			token = strtok(NULL, ";");
			p.ocena = atoi(token);
			dodajPolaganje(&s.listaPP, p);
		}
		dodajStudenta(glava, s);
		printf("%s\n", s.imePrezime);
	}
	
	fclose(fajl);
}

void prikazPolaganja(PPOK glava) {
	while (glava!=NULL)
	{
		printf("%s\t%d\t", glava->podatak.sifraPredmeta, glava->podatak.ocena);
		glava = glava->sledeci;
		
	}
}

void prikazListe(SPOK glava) {

	while (glava!=NULL)
	{
		printf("\n%s ==== %s Prosek: %.2lf\n", glava->podatak.imePrezime, glava->podatak.indeks,glava->podatak.prosecnaOcena);
		prikazPolaganja(glava->podatak.listaPP);
		glava = glava->sledeci;
		printf("\n");
	}
}

void prosecnaOcena(SPOK glava) {
	SPOK pom = glava;
	while (pom!=NULL)
	{
		int ocene = 0;
		int brPr = 0;
		PPOK pom1 = pom->podatak.listaPP;
		while (pom1 != NULL) {
			int ocena = pom1->podatak.ocena;
			ocene += ocena;
			brPr++;
			ocena = 0;
			pom1 = pom1->sledeci;
		}
		pom->podatak.prosecnaOcena = (double)ocene / brPr;
		pom = pom->sledeci;
	}
}


void sortiratiOpadajuce(SPOK *glava) {




}



int main(void) {
	//unosSaTastature();
	/*PCVORS lista = NULL;
	PCVORP polaganja = NULL;*/
	//ucitajStudente(&lista);
	//prikaziStudente(lista);
	SPOK glava = NULL;
	ucitajIzFajla(&glava);
	prosecnaOcena(glava);
	prikazListe(glava);
	system("pause");
	return 0;
}