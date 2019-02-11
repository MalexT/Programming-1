#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//najmanji parniEL

void najmanjiParni(int niz[], int dim) {
	int el=100;

	for (int i = 0; i < dim; i++)
	{
		if (niz[i] % 2 == 0 && niz[i] < el) {
			el = niz[i];
		}
	}
	printf("Najmanji p.el. niza je: %d\n", el);
}

int brojElSaVrednoscuVecomOdSrednjeVrNiza(int niz[], int brEl) {
	int brojac = 0;
	int suma = 0;
	for (int i = 0; i < brEl; i++)
	{
		suma += niz[i];
	}
	double srednjaVr = (double)suma / brEl;
	for (int j = 0; j < brEl; j++)
	{
		if (niz[j] > srednjaVr)
			brojac++;
	}
	return brojac;
}

void pomeriUDesno(int niz[], int dim) {

	int pom;
	for (int i = dim; i >0; i--)
	{
		pom = niz[0];
		niz[0] = niz[dim - i];
		niz[dim - i] = pom;
	}
}

void pomeriULevo(int niz[], int dim) {

	int pom = niz[0];
	for (int i = dim; i > 0; i--)
	{
		niz[dim - i] = niz[dim - i + 1];
	}
		niz[dim-1] = pom;
}

void prikazNiza(int niz[], int dim) {
	for (int i = 0; i < dim; i++)
	{
		printf("[%d] %d\n",i, niz[i]);
	}
	puts("");
}

void pomeriZaNMestaULevo(int niz[], int dim, int mesta) {

	for (int i = 0; i < mesta; i++)
	{
		pomeriULevo(niz, dim);
	}
}

void dodajNaPocetak(int niz[], int *dim, int x) {

	for (int i = (*dim) - 1; i >= 0; i--)
	{
		niz[i+1] = niz[i];
	}
	niz[0] = x;
	(*dim)++;
}

void izbaciSaPocetka(int niz[], int *dim) {
	for (int i = 0; i<(*dim)-1; i++)
	{
		niz[i] = niz[i + 1];
	}
	(*dim)--;
}

void noviNizParnih(int niz[], int dim) {
	int niz1[50];
	int j = 0;
	for (int i = 0; i < dim; i++)
	{
		if (niz[i] % 2 == 0)
			niz1[j++] = niz[i];
	}
	prikazNiza(niz1, j);
}

//zatvoreni interval

void zatvorenInterval() {
	int a, b;
	puts("Unesite gornju i donju granicu intervala.");
	scanf("%d %d", &a, &b);
	while (a > b) {
		printf("Granica nije uneta kako treba, pokusajte ponovo");
		puts("Unesite gornju i donju granicu intervala.");
		scanf("%d %d", &a, &b);
	}
	int suma = 0;
	for (int i = a; i <=b; i++)
	{
		if (i % 2 == 0) {
			suma += i;
		}
	}
	printf("Suma parnih brojeva je %d\n", suma);
}

void zatvorenInterval1() {
	int a, b;
	puts("Unesite gornju i donju granicu intervala.");
	scanf("%d %d", &a, &b);
	while (a > b ||
		a==0) {
		printf("Granica nije uneta kako treba, pokusajte ponovo");
		puts("Unesite gornju i donju granicu intervala.");
		scanf("%d %d", &a, &b);
	}
	int suma = 0;
	int niz[100];
	int j = 0;
	for (int i = a; i <= b; i++)
	{
		if (i % 3 == 0) {
			niz[j++] = i;
		}
	}

	for (int k = 0; k < j; k++)
	{
		suma += niz[k];
		printf("%d ", niz[k]);
	}
	printf("Brojeva koji su deljivi sa 3 ima %d\n", j);
	printf("Srednja vrednost brojeva deljivih sa tri je %5.2lf\n", ((double)suma/j));
}

void zatvorenInterval2(int x) {
	int a, b;
	puts("Unesite gornju i donju granicu intervala.");
	scanf("%d %d", &a, &b);
	while (a > b ||
		a == 0) {
		printf("Granica nije uneta kako treba, pokusajte ponovo");
		puts("Unesite gornju i donju granicu intervala.");
		scanf("%d %d", &a, &b);
	}
	int j = 0;
	for (int i = a; i <= b; i++)
	{
		if (i % x == 0) {
			j++;
		}
	}
	printf("Brojeva deljivih sa %d ima %d\n", x, j);
}

int prostBroj(int x) {
	if (x == 1)
		return 0;

	for (int i = 2; i < x; i++)
	{
		if (x % i == 0)
			return 0;
	}
	return 1;
}

void zatvorenInterval3() {
	int a, b, j = 0;
	puts("Unesite gornju i donju granicu intervala.");
	scanf("%d %d", &a, &b);
	while (a > b ||
		a == 0) {
		printf("Granica nije uneta kako treba, pokusajte ponovo");
		puts("Unesite gornju i donju granicu intervala.");
		scanf("%d %d", &a, &b);
	}
	for (int i = a; i <= b; i++)
	{
		if (prostBroj(i) == 1)
			j++;
	}

	printf("U datom intervalu ima %d prostih brojeva.\n", j);
}

int cifraJedinice9(int x) {
	if (x == 9)
		return 1;

	while (x > 10) {
		x %= 10;
	}
	if (x == 9)
		return 1;
	else
		return 0;
}

void zatvorenInterval4() {
	int a, b;
	puts("Unesite gornju i donju granicu intervala.");
	scanf("%d %d", &a, &b);
	while (a > b ||
		a == 0) {
		printf("Granica nije uneta kako treba, pokusajte ponovo");
		puts("Unesite gornju i donju granicu intervala.");
		scanf("%d %d", &a, &b);
	}
	int suma = 0;
	for (int i = a; i <= b; i++)
	{
		if (cifraJedinice9(i)) {
			suma += i;
		}
	}
	printf("Suma brojeva cija je cifra jedinice jednaka 9 je %d \n",suma);
}

void piramida(int x) {

	int k = 2 * x - 2;

	for (int i = 0; i <x; i++)
	{
		for (int j = 0; j < k; j++)
		{
			printf(" ");
		}
		k = k - 1;
		for (int j = 0; j <=i; j++)
		{
			printf("* ");
		}
		printf("\n");
	}

}

int uzastopni(int s, int d, int j) {

	if ((s == (d + -1) && (d == j + -1)) || (s == (d + -2) && d == (j + 1)) || (s == (d + 1) && (d == j + 1)) || (s == (d + 2) && d == (j - 1)) || (j==(d-2) && (d==s+1)))
		return 1;
	return 0;
}

void cifreDSJUzastopni() {

	for (int i = 100; i < 1000; i++)
	{
			int stotine = i / 100;
			int jedinice = (i % 100)%10;
			int desetice = (i/10)%10;
			if (uzastopni(stotine, desetice, jedinice)) {
				printf("%d\n", i);
			}

	}



}

//Razliciti elementi niza

int nePostojiUNizu(int niz[], int dim, int el) {
	for (int i = 0; i < dim; i++)
	{
		if (niz[i] == el)
			return 0;
	}
	return 1;
}

void unosRazlicitihElemNiza(int niz[], int dim, int niz1[], int *dim1) {

	for (int i = 0; i < dim; i++)
	{
		if (nePostojiUNizu(niz1, *dim1, niz[i]))
			niz1[(*dim1)++] = niz[i];
	}

}

int najveciParanBroj(int niz[], int dim) {
	int paranBroj = 0;

	for (int i = 0; i < dim; i++)
	{
		if (niz[i] % 2 == 0) {
			paranBroj = niz[i];
			break;
		}
	}
	for (int i = 0; i < dim; i++)
	{
		if (niz[i] % 2 == 0 && i > paranBroj) {
			paranBroj = niz[i];
		}
	}
	
	if (paranBroj != 0) {
	return paranBroj;
	}
	return NULL;
}

void nizUnazadNapisan(int niz[], int dim) {
	for (int i = dim-1; i >=0; i--)
	{
		printf("%d\t", niz[i]);
	}
	printf("\n");
}

void naParnimMestima(int niz[], int dim) {

	for (int i = 0; i <=dim; i++)
	{
		if (i == 0)
			continue;
		if (i % 2 == 0)
			printf("%d   ", niz[i]);
	}
	printf("\n");
}

void viseParnihIliNeparnih(int niz[], int dim) {
	int parni = 0;
	int neparni = 0;
	for (int i = 0; i < dim; i++)
	{
		if (niz[i] % 2 == 0)
			parni++;
		else
			neparni++;
	}
	if (parni > neparni) {
		puts("Vise ima parnih.");
	}
	else if (neparni < parni) {
		puts("Ima vise neparnih.");
	}
	else if(neparni==parni){
		puts("Ima podjednak broj parnih i neparnih elemenata niza.");
	}
}

int rastuci(int niz[], int dim) {

	for (int i = 0; i < dim-1; i++)
	{
		for (int j = i+1; j < dim; j++)
		{
			if (niz[i] >= niz[j])
				return 0;
		}
	}	
	return 1;
}

void najduziPodnizParnihBrojeva(int niz[], int dim) {
	int nizP[100];
	int dimP = 0;
	int pomP[100];
	int dimPp = 0;

	for (int i = 0; i < dim; i++)
	{
		if (niz[i] % 2 == 0) {
			pomP[dimPp++] = niz[i];
		}
		else {
			if (dimP < dimPp) {
				for (int j = 0; j < dimPp; j++)
				{
					nizP[j] = pomP[j];
					dimP = dimPp;
				}
			}
			dimPp = 0;
		}

		if (niz[dim] % 2 == 0) {
			if (dimP < dimPp) {
				for (int j = 0; j < dimPp; j++)
				{
					nizP[j] = pomP[j];
					dimP = dimPp;
				}
			}
		}
	}
	prikazNiza(nizP, dimP);
}

int duplikati(int niz[], int dim) {
	for (int i = 0; i < dim-1; i++)
	{
		for (int j = i+1; j < dim; j++)
		{
			if (niz[i] == niz[j]) {
				return 1;
			}
		}
	}
	return 0;
}

void parne2neparne1(int niz[], int dim) {
	for (int i = 0; i < dim; i++)
	{
		if (i % 2 == 0) {
			niz[i] += 2;
		}
		else if (i % 2 == 1) {
			niz[i] += 1;
		}
	}
	prikazNiza(niz, dim);
}

int palindrom(int niz[], int dim) {
	for (int i = 0; i < dim/2; i++)
	{
		if (niz[i] != niz[dim - 1 - i])
			return 0;
	}
	return 1;
}

void jedinstvenaRazlikaNizova(int niz[], int niz1[], int niz2[], int dim, int dim1, int *dim2) {
	int j = 0;
	for (int i = 0; i < dim; i++)
	{
		if (nePostojiUNizu(niz1, dim1, niz[i]) && nePostojiUNizu(niz2, (*dim2), niz[i])) {
			niz2[(*dim2)++] = niz[i];
		}
	}
}

//Matrice

void najmanjiElMatrice(int mat[][5], int n, int m) {
	int min = mat[0][0];
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mat[i][j] < min)
				min = mat[i][j];
		}
	}
	printf("Najmanji element je: %d \n", min);
}

void najmanjiElKolone(int mat[][5], int n, int m, int kol) {

	int min = 100;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j == kol - 1) {
				if (mat[i][j] < min)
					min = mat[i][j];
			}
		}
	}
	printf("Najmanji element matrice %d kolone je %d\n", kol, min);

}

void unosUMatricu(int mat[][10], int *n) {
	printf("Unesite dimenziju matrice nxn: \t");
	scanf("%d", n);
	for (int i = 0; i < *n; i++)
	{
		for (int j = 0; j < *n; j++)
		{
			printf("Unosite [%d][%d] el. matrice: ", i+1, j+1);
			scanf("%d", &mat[i][j]);
		}
	}
}

void sumaPoRedovima(int mat[][5], int n, int m) {
	
	int sumaReda = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d\t", mat[i][j]);
			sumaReda += mat[i][j];
		}
		printf("%d\n", sumaReda);
		sumaReda = 0;
	}
}

// String

int stringPalindrom(char s[]) {	

	for (int i = 0; i < (strlen(s)/2); i++){
		if (s[i] != s[strlen(s) - i - 1])
			return 0;
	}
	return 1;
}

void stringSamoSaCiframa(char s[]) {
	char s1[100];
	int j = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (isdigit(s[i]))
			s1[j++] = s[i];
	}
	puts("");
	for (int i = 0; i < j; i++)
	{
		printf("%c", s1[i]);
	}
}

int cifreUStringu(char s[]) {

	for (int i = 0; i < strlen(s); i++)
	{
		if (isdigit(s[i]))
			return 1;
	}

	return 0;
}

int samoglasnik(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return 1;
	}
	return 0;
}

void najduzipodnizsamoglasnika(char s[]) { //Uradi 

	char samoglasnici[100];
	char j = 0;
	int poc;
	int kraj;
	int jeste = 0;
	char maxsamoglasnici[50];
	int najduziSamoglasnici = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (samoglasnik(s[i])) {
			samoglasnici[j++] = s[i];
		}
		else {
			if (najduziSamoglasnici < j) {
				for (int k = 0; k < j; k++)
				{
					maxsamoglasnici[k] = samoglasnici[k];
				}
				najduziSamoglasnici = j;
			}
			j = 0;
		}

	}

	if (samoglasnik(s[strlen(s)-1])) {
		if (najduziSamoglasnici < j) {
			for (int k = 0; k < j; k++)
			{
				maxsamoglasnici[k] = samoglasnici[k];
			}
			najduziSamoglasnici = j;
		}
		j = 0;
	}
	
	
	for (int i = 0; i < najduziSamoglasnici; i++)
	{
		printf("%c", maxsamoglasnici[i]);
	}
	puts("");

}

// strukture

typedef struct proizvod
{
	int sifra;
	double cena;
	char naziv[21];
}PROIZVOD;

int nePostoji(PROIZVOD niz[],int dim ,int sifra) {
	for (int i = 0; i < dim; i++)
	{
		if (niz[i].sifra == sifra) {
			return 0;
		}
	}
	return 1;
}

void unosProizvodaUNiz(PROIZVOD niz[], int *dim) {

	PROIZVOD p;
	puts("Unesite sifru naziv i cenu proizvoda.\n");
	scanf("%d ", &p.sifra);
	gets(p.naziv);
	scanf("%lf", &p.cena);
		if (nePostoji(niz,*dim,p.sifra)) {
			niz[(*dim)++] = p;
		}
}

void prikazNizaProizvoda(PROIZVOD niz[], int dim) {

	for (int i = 0; i < dim; i++)
	{
		printf("Artikl:%d  %s  %5.2lf\n--------------------------\n", niz[i].sifra, niz[i].naziv, niz[i].cena);
	}

}

void sortirajPoNazivu(PROIZVOD niz[], int dim) {

	PROIZVOD pom;


	for (int i = 0; i < dim-1; i++)
	{
		for (int j = i+1; j < dim; j++)
		{
			if (strcmp(niz[i].naziv, niz[j].naziv) > 0) {

				pom.cena = niz[i].cena;
				pom.sifra = niz[i].sifra;
				strcpy(pom.naziv, niz[i].naziv);

				niz[i].cena = niz[j].cena;
				niz[i].sifra = niz[j].sifra;
				strcpy(niz[i].naziv, niz[j].naziv);

				niz[j].cena = pom.cena;
				niz[j].sifra = pom.sifra;
				strcpy(niz[j].naziv, pom.naziv);
			}
		}
	}

}

void obrisiElementNiza(PROIZVOD niz[], int *dim, char x[]) {
	int pos = 0;
	int jeste = 0;
	int puta = 0;
	for (int i = 0; i < *dim; i++)
	{
		if (strcmp(niz[i].naziv, x) == 0) {
			jeste = 1;
			puta++;
		}
	}
	if (jeste == 1) {
		for (int j = pos; j < (*dim)-1; j++)
		{
			niz[j] = niz[j + 1];
		}
	}

}

//Liste
typedef struct element *POK;
typedef struct element
{
	int x;
	POK sledeci;
}ELEMENT;

void unosUListu(POK *glava, int x) {

	POK noviEl = malloc(sizeof(ELEMENT));
	noviEl->x = x;
	noviEl->sledeci = *glava;
	*glava = noviEl;
}

int postojiUListi(POK glava, int broj) {
	
	while (glava != NULL) {
		if (glava->x == broj) {
			return 1;
		}
		glava = glava->sledeci;
	}
	return 0;
}

void prikazListe(POK glava) {
	while (glava!=NULL)
	{
		printf("%d   ", glava->x);
		glava = glava->sledeci;
	}
	printf("\n");
}

void kolikoElListe(POK glava) {
	POK tek = glava;
	int brojac = 0;
	int suma = 0;
	int x = 0;
	while (tek != NULL) {
		x = 0;
		x = tek->x;
		suma += x;
		brojac++;
		tek = tek->sledeci;
	}
	tek = glava;
	double srvr = (double)suma / brojac;
	brojac = 0;
	while (tek != NULL) {
		if (tek->x > srvr) {
			brojac++;
		}
		tek = tek->sledeci;
	}
	printf("U listi ima %d brojeva cija je vrednost veca od aritmeticke sredine liste %.2lf.\n", brojac,srvr);
}

void izbaciElementListe(POK *glava) {
	if (glava == NULL) {
		return;
	}
	if ((*glava)->sledeci == NULL) {
		*glava = NULL;
		return;
	}
	POK tek = *glava;
	POK prethodni = NULL;
	while (tek->sledeci!=NULL)
	{
		prethodni = tek;
		tek = tek->sledeci;
	}
	free(tek);
	prethodni->sledeci = NULL;
}

void pocetakListe(POK *glava) {

	POK pom = *glava;
	pom = pom->sledeci;
	free((*glava));
	*glava = pom;
}

void ispisUnazad(POK glava) {
	if (glava == NULL) {
		return;
	}
	ispisUnazad(glava->sledeci);
	printf("%d  ", glava->x);
}

int pojavljivanjeBrojaUListi(POK glava, int br) {
	int brojac = 0;
	while (glava!=NULL)
	{
		if (glava->x == br) {
			brojac++;
		}
		glava = glava->sledeci;
	}
	return brojac;
}

void frekvencijaSvakogElementaListe(POK glava) {

	int frekv[100];
	int broj;
	int k = 0;
	int l = 0;
	POK tek = glava;
	while (tek != NULL) {
		k++;
		tek = tek->sledeci;
	}
	for (int i = 0; i < k; i++)
	{
		frekv[i] = -1;
	}
	tek = glava;
	while (tek!=NULL)
	{
			if (pojavljivanjeBrojaUListi(glava, tek->x) != 0) {
				if (frekv[l] != 0) {
					frekv[l] = pojavljivanjeBrojaUListi(glava, tek->x);
					l++;
				}
		}
		tek = tek->sledeci;
	}
	tek = glava;
	int m = 0;
	while (tek!=NULL)
	{
		printf("%d element liste se javlja %d puta\n", tek->x, frekv[m]);
		tek = tek->sledeci;
		m++;
	}

}

void parniIspodSporedneDijagonale(int mat[][4], POK *glava) {


	for (int i = 0; i <4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i + j >= 4 && mat[i][j]%2==0) {
				unosUListu(glava, mat[i][j]);
			}
		}
	}
}

int main(void) {
	//puts("Unesite dimenzije niza: ");
	//int dim;
	//scanf("%d", &dim);
	//int niz[100];
	//for (int i = 0; i < dim; i++)
	//{
	//	scanf("%d", &niz[i]);
	//}
	//puts("Unesite dimenzije niza: ");
	//int dim1;
	//scanf("%d", &dim1);
	//int niz1[100];
	//for (int i = 0; i < dim1; i++)
	//{
	//	scanf("%d", &niz1[i]);
	//}
	//int niz2[100];
	//int dim2 = 0;
	
	int mat[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int mat1[10][10];

	POK glava = NULL;
	/*unosUListu(&glava, 1);
	unosUListu(&glava, 52);
	unosUListu(&glava, 10);
	unosUListu(&glava, 41);
	unosUListu(&glava, 14);
	unosUListu(&glava, 52);
	unosUListu(&glava, 41); 
	unosUListu(&glava, 21);
	unosUListu(&glava, 12);
	unosUListu(&glava, 11);
	unosUListu(&glava, 52);
	unosUListu(&glava, 41);*/
	int niz[100];
	int dim=0;
	parniIspodSporedneDijagonale(mat,&glava);
	for (int i = 0; i < 4; i++)
	{
		for (int  j = 0; j < 4; j++)
		{
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}

	prikazListe(glava);

	//frekvencijaSvakogElementaListe(glava);

	system("pause");
	return;
}