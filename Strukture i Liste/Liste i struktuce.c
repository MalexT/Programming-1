#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct element *POKAZIVAC;

typedef struct element {
	char ime[15];
	char pol[3];
	char suprug[15];
	POKAZIVAC sledeci;
}LICE;

typedef struct elementListe *pok;

typedef	struct elementListe
{
	int broj;
	pok sledeci;
}ELEMENT;

typedef struct node *POK;
typedef struct node {
	int br;
	POK sledeci;
}NODE;


void unos() {
	printf("Unesite koliko lica zelite da unesete.\n");
	int brLica;
	LICE osobe[20];
	scanf("%d", &brLica);
	puts("Unesite (Pol, Ime, ime supruga/e): ");
	for (int i = 0; i < brLica; i++)
	{
		scanf("%s %s %s", osobe[i].pol, osobe[i].ime, osobe[i].suprug);
	}
	int brak = 0;
	for (int i = 0; i < brLica-1; i++)
	{
		for (int j = i+1; j < brLica; j++)
		{
			if ((strcmp(osobe[i].pol, osobe[j].pol)) != 0 && 
				(strcmp(osobe[i].ime, osobe[j].suprug) == 0) && 
				(strcmp(osobe[i].suprug, osobe[j].ime) == 0)) {
				brak++;
				break;
			}
		}
	}
	printf("Ima %d brakova od svih osoba.\n", brak);
}

void lista() {
	int n;
	puts("UNesite broj, broj veci od 30 prekida unos.");
	scanf("%d", &n);
	pok novi = malloc(sizeof(ELEMENT));
	pok pom;
	pok a;
	novi->broj = n;
	novi->sledeci = NULL;
	pom = novi;
	while (n<=30) {
		a = malloc(sizeof(ELEMENT));
		if (a == NULL) {
			return;
		}
		scanf("%d", &n);
		a->broj = n;
		a->sledeci = NULL;
		pom->sledeci = a;
		pom = a;
	}
	printf("Lista je: ");
	a = novi;
	while (a != NULL) {
		printf("%d\n", a->broj);
		a = a->sledeci;
	}
	puts("");
}

void palindrom(char s[]) {
	int p = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == s[strlen(s) - 1]) {
			p = 1;
		}
	}
	if (p == 1) {
		printf("Jeste palindrom");
	}
	else
	{
		printf("Nije palindrom");
	}

}

int brojElListe(pok glava) {
	pok novi;
	novi = glava;
	int brojac = 0;
	while (novi != NULL) {
		brojac++;
		novi = novi->sledeci;
	}
	return brojac;
}

// -------------------------------------------OVO ISPOD JE VAZNO--------------------------------------------
void unosNaKrajListe(pok glava, int k) { 

	while (glava->sledeci != NULL) {
		glava = glava->sledeci;
	}
	pok novi = malloc(sizeof(ELEMENT));
	if (novi == NULL) {
		puts("GRESKA.");
		return;
	}
	glava->sledeci = novi;
	novi->broj = k;
	novi->sledeci = NULL;
}

void prikaziElementeListe(pok glava) {
	pok tekuci;
	tekuci = glava;

	while (tekuci != NULL) {
		printf("%d\t", tekuci->broj);
		tekuci = tekuci->sledeci;
	}
	printf("\n");
}

void unosNaPocetakUListu(pok *glava, int k) {
	pok novi = malloc(sizeof(ELEMENT));
	novi->broj = k;
	novi->sledeci = *glava;
	*glava = novi;
}

void izbaciSaKraja(pok *glava) {
	pok prethodni = NULL;
	pok tekuci = *glava;

	while (tekuci->sledeci != NULL) {
		prethodni = tekuci;
		tekuci = tekuci->sledeci;
	}
	if (prethodni == NULL) {
		*glava = NULL;
	}
	else {
		prethodni->sledeci = NULL;
	}
	printf("Element sa kraja liste koji se izbacuje je %d\n\n", tekuci->broj);
	free(tekuci);
}

void sortirana(pok glava) {

	int s1 = 1, s2 = 1;
	while (glava->sledeci != NULL && s1 + s2 > 0 ) {

		if (glava->broj > glava->sledeci->broj)
			s1 = 0;
		if (glava->broj < glava->sledeci->broj)
			s2 = 0;
		glava = glava->sledeci;
	}
	if (s1 == 0 )
		puts("Lista je sortirana opadajuce");
	else if(s2==0)
		puts("Lista je sortirana rastuce");
}

void sortirajListu1(pok glava) {
	pok i;
	pok j;
	int pom;
	
	for ( i = glava; i !=NULL ; i=i->sledeci)
	{
		for ( j = glava; j!=NULL; j=j->sledeci)
		{
			if (i->broj < j->broj) {
				pom = i->broj;
				i->broj = j->broj;
				j->broj = pom;
			}
		}
	}
}

void unosUSortiranuListu(pok *glava, int br) {

	pok novi = malloc(sizeof(ELEMENT));
	pok tek = *glava;
	pok pom = malloc(sizeof(ELEMENT));
	novi->broj = br;
	if (tek->broj > br) {
		novi->sledeci = tek;
		tek = novi;
	}
	else {
		while (tek->sledeci != NULL && tek->sledeci->broj<br) {
			tek = tek->sledeci;
		}
		pom->broj = br;
		pom->sledeci = tek->sledeci;
		tek->sledeci = pom;
	}
}

void izbaciManjeOdZadatogBroja(pok *glava, int br) {
	pok pom = NULL;
	while((*glava)!=NULL && (*glava)->broj < br) {
		pom = *glava;
		(*glava) = (*glava)->sledeci;
		free(pom);
	}
	pok tek = *glava;
	while (tek->sledeci != NULL)
	{
		if (tek->sledeci->broj < br) {
			pom = tek->sledeci;
			tek->sledeci = tek->sledeci->sledeci;
			free(pom);
		}
		else {
			tek = tek->sledeci;
		}
	}
}

void OkreniListu(pok *glava) {

	pok tek = *glava;
	pok preth = NULL;
	pok sled = NULL;

	while (tek != NULL) {
		sled = tek->sledeci;

		tek->sledeci = preth;

		preth = tek;

		tek = sled;
	}
	*glava = preth;
}

void IspisiUnazad(pok glava) {
	if (glava == NULL) {
		return;
	}
	IspisiUnazad(glava->sledeci);
	
	printf("%d ", glava->broj);
}

void sortiratiPriUnosuURastucemPoretku(pok *glava, int broj1) {

	pok tek;
	pok preth;
	pok novi = malloc(sizeof(ELEMENT));
	novi->broj = broj1;
	novi->sledeci = NULL;
		if ((*glava) == NULL) {
			*glava = novi;
		}
		else {
			preth = NULL;
			tek = *glava;
			while (tek != NULL && tek->broj <= broj1) {
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




//-----------------------------------------------------------------------------
void naosnovuPariNeparfoRmirajTrecu(pok glava1, pok *glava2, pok *glava3) {

	pok tek = glava1;
	while (tek != NULL) {
		if (tek->broj % 2 == 0) {
			unosNaPocetakUListu(glava2, tek->broj);
		}
		else {
		unosNaPocetakUListu(glava3, tek->broj);
		}
		tek = tek->sledeci;
	}
}

// ova ne radi...
void odDveNapraviTrecu(pok glava, pok glava1, pok *glavna) {
	
	pok novi = malloc(sizeof(ELEMENT));
	
	while (glava != NULL) {
		while (glava1 != NULL) {
			if (glava->broj < glava1->broj) {
				unosNaPocetakUListu(glavna, glava->broj);
			}
			else {
				unosNaPocetakUListu(glavna, glava1->broj);
			}
			glava1 = glava1->sledeci;
		}
		glava = glava->sledeci;
	}
	
}

void dodajURed(POK glava, int k) {
	
	if (glava == NULL) {
		glava = malloc(sizeof(NODE));
		glava->sledeci = NULL;
		glava->br = k;
	}

	else

	while (glava->sledeci != NULL) {
		glava = glava->sledeci;
	}

	POK novi = malloc(sizeof(NODE));

	if (novi == NULL) {
		puts("Greska");
		return;
	}

	glava->sledeci = novi;
	novi->br = k;
	novi->sledeci = NULL;
}

int jeLiPrazan(POK glava) {
	return (glava == NULL) ? 1 : 0;
}

void obrisiElementIzReda(POK *glava) {

	POK pom = *glava;
	if (*glava == NULL) {
		return;
	}
	glava = (*glava)->sledeci;

	free(pom);
}

void obrisiPOslednjiElListe(POK *glava) {
	if ((*glava) == NULL) {
		puts("Lista je prazna.");
		return;
	}
	if ((*glava)->sledeci == NULL) {
		*glava = NULL;
		puts("Sada je lista prazna.");
		return;
	}
	POK tek = *glava;
	POK preth = NULL;
	while (tek->sledeci != NULL) {
		preth = tek;
		tek = tek->sledeci;
	}
	free(tek);
	preth->sledeci = NULL;
}


int main(void) {
//	unos();
//	lista();
	pok nepar = NULL;
	pok par = NULL;
	pok glava = NULL;
	pok rastucaGlava = NULL;
	pok glava1 = NULL;
	POK red = NULL;
	//{
		unosNaPocetakUListu(&glava, 1);
	//	unosNaPocetakUListu(&glava, 5);
	//	unosNaPocetakUListu(&glava, 50);
	//	unosNaPocetakUListu(&glava, 2);
	//	unosNaPocetakUListu(&glava, 3);
	//	unosNaPocetakUListu(&glava, 12);
	//	unosNaPocetakUListu(&glava, 5);
	//	unosNaPocetakUListu(&glava, 15);
	//	unosNaPocetakUListu(&glava, 75);
	//	unosNaKrajListe(glava, 6);
	//}
	//prikaziElementeListe(glava);
	//izbaciSaKraja(&glava);
	//prikaziElementeListe(glava);
	//sortirajListu1(glava);
	//prikaziElementeListe(glava);
	//sortirana(glava);
	//unosUSortiranuListu(&glava, 40);
	//prikaziElementeListe(glava);
	//izbaciManjeOdZadatogBroja(&glava, 20);
	//prikaziElementeListe(glava);
	///*OkreniListu(&glava);*/
	//IspisiUnazad(glava);
	//printf("\n");
	/*naosnovuPariNeparfoRmirajTrecu(glava, &par, &nepar);
	prikaziElementeListe(glava);
	prikaziElementeListe(par);
	prikaziElementeListe(nepar);*/



	//dodajURed(red, 9);
	//dodajURed(red, 92);
	//dodajURed(red, 94);
	//dodajURed(red, 79);
	//if (jeLiPrazan(red)) {
	//	puts("Prazan.");
	//}
	//else 
	//	obrisiElementIzReda(&glava);
	//	obrisiElementIzReda(&glava);
	//	if (jeLiPrazan(red)) 
	//		puts("Prazan.");
	//	else 
	//		obrisiElementIzReda(&glava);
	//		obrisiElementIzReda(&glava);
	//		if (jeLiPrazan(red)) {
	//			puts("Prazan.");
	//		}
	//		else {
	//			puts("Nije prazan.");
	//		}
		
		POK glavaa = NULL;
		unosNaPocetakUListu(&glavaa, 1);
		unosNaPocetakUListu(&glavaa, 1);
		unosNaPocetakUListu(&glavaa, 1);
		obrisiPOslednjiElListe(&glavaa);
		prikaziElementeListe(glavaa);
	system("pause");
	return 0;
}


