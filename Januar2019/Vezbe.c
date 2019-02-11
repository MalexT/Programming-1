#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>


int prostBroj(int broj) {

	for (int i = 2; i < broj; i++) {
		if (broj % i == 0)
			return 0;
	}
	return 1;
}

double srednjaVrednost(int niz[], int brEl) {
	double suma = 0.0;
	for (int i = 0; i < brEl; i++)
	{
		suma += niz[i];
	}
	return suma / brEl;
}

int zameniSlovo(char s[], char a, char b) {
	int brojac = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == a){
			s[i] = b;
			brojac++;
	}
	}
	return brojac;
}

void obrniString(char string[]) {

	char pom;
	for (int i = 0; i < (strlen(string))/2; i++)
	{
		pom = string[i];
		string[i] = string[strlen(string) - 1 - i];
		string[strlen(string) - 1 - i] = pom;
	}

}

int poredjenje(char s1[], char s2[]) {

	if (strlen(s1) != strlen(s2))
		return 0;


	for (int i = 0; i < strlen(s1); i++)
	{
		if (s1[i] != s2[i])
			return 0;
	}

	return 1;
}

int ukloniKarakter(char s[], char k) {
	int brojac = 0, j = 0;
	
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] != k)
			s[j++] = s[i];
		else
			brojac++;
	}
	s[j] = '\0';
	return brojac;
}

void uzastopni(char s[], int poc, int n) {

	int j = 0;
	for (int i = 0; i < poc; i++)
	{
		s[j++] = s[i];
	}
	for (int k = (poc+n); k < strlen(s); k++)
	{
		s[j++] = s[k];
	}
	s[j] = '\0';
}

int poklapaje(char s[], char t[]) {
	int i = 0;
	while (s[i] == t[i] && s[i] && t[i]) {
		i++;
	}
	return i;
}

int nePojavljuju(char s[], char t[]) {

	int i = 0, j = 0;
	while (s[i] != '\0') {

		j = 0;
		while (t[j] != '\0') {
			if (t[j] == s[i])
				return i;
			j++;
		}
		i++;
	}
	return i;
}

void maksimalniElementMatriceIPozicija(int m[][10], int a) {

	int max = m[0][0];
	int pozI = 0;
	int pozJ = 0;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (m[i][j] > max) {
				max = m[i][j];
				pozI = i;
				pozJ = j;
			}
		}
	}
	printf("Maksimalni element matrice je %d, a njegova pozicija je [%d][%d].\n", max, pozI + 1, pozJ + 1);
}

void parniPaNeparni(int n[], int m) {
	int p;
	for (int i = 0; i < m-1; i++)
	{
		for (int j = i+1; j < m; j++)
		{
			if (n[i] % 2 == 1 && n[j] % 2 == 0) {
				p = n[i];
				n[i] = n[j];
				n[j] = p;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		printf("%d ", n[i]);
	}
	puts("");
}

void spajanje(int prvi[], int drugi[], int treci[], int n, int m) {
	int k = 0, j = 0, i = 0;
	while (k < n + m) {
		if ((i < n && prvi[i] <= drugi[j]) || j >= m) {
			treci[k++] = prvi[i++];
		}
		else {
			treci[k++] = drugi[j++];
		}
	}


}

int main(void) {

	//1
	/*int a, b;
	char operator;
	printf("Unesite brojeve:  \n");
	scanf("%d %d", &a, &b);
	printf("Unesite operator: \n");
	scanf(" %c", &operator);

	switch (operator) {
	case '+':
		printf("%d\n", a + b);
		break;
	case '-':
		printf("%d\n", a - b);
		break;
	case '*':
		printf("%d\n", a * b);
		break;
	case '/':
		if (b != 0) {
			printf("%lf\n", (double)a / b);
			break;
		}
		else {
			printf("Deljenje nulom...");
			break;
		}
	default:
		printf("Uneli ste pogresan operator!");
	}*/
	
	//2
	/*double broj,suma=0, proizvod=1;
	printf("Unesite broj: ");
	scanf("%lf", &broj);
	printf("\n");
	while (broj > 0) {
		suma += broj;
		proizvod *= broj;
		broj--;
	}
	printf("Suma prirodnih brojeva je: %.2lf\n", suma);
	printf("Proizvod prirodnih brojeva je: %.2lf\n", proizvod);*/

	//3 Hamingov broj
	/*int broj;
	printf("Unesite prirodan broj: \n");
	scanf("%d", &broj);
	
	while (broj % 2 == 0)
		broj /= 2;
	while (broj % 3 == 0)
		broj /= 3;
	while (broj % 5 == 0)
		broj /= 5;
	if (broj == 1)
		printf("Broj jeste hamingov.\n");
	else
		printf("broj nije hamingov\n");*/

	//4.
	/*int dim;
	char c;
	printf("Unesite dimenzije i karakter za kvadrat: \n");
	scanf("%d %c", &dim, &c);

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++) {
			if (i == 0 || i == dim - 1 || j == 0 || j == dim - 1)
				printf("%c", c);
			else
				printf(" ");
		}
		printf("\n");
	}*/

	//5.
	/*int broj, zbir=0;
	printf("Unesite prirodni broj:\n");
	scanf("%d", &broj);
	while (broj != 0) {
		zbir += broj % 10;
		broj /= 10;
	}
	printf("Suma cifara zadatog broja je: %d \n", zbir);*/

	//6.
	/*int a, b, c;
	printf("Unesite datum: \n");
	scanf("%d, %d, %d", &a, &b, &c);
	int an, bn, cn;
	int prest = !(c % 4) && (!(c % 400) || c % 100);
	if (a == 31 && b == 12) {
		an = bn = 1;
		cn = c + 1;
	}
	else if (a == 31 || (a == 30 && (b == 4 || b == 6 || b == 9 || b == 11)) || (a == 29 && b == 2) || (a == 28 && b == 2 && !prest)) {
		an = 1;
		bn = b + 1;
		cn = c;
	}
	else {
		an = a + 1;
		bn = b;
		cn = c;
	}
	printf("Sutrasnji datum je: %d.%d.%d.\n",an, bn, cn);*/

	//7.Nizovi
	/*int niz[20];
	printf("Unesite elemente niza\n\n");
	for (int i = 0; i < 20; i++)
	{
		printf("Unesite %d. element niza:\t", i + 1);
		scanf("%d", &niz[i]);
	}
	int max=0, min=niz[0];
	for (int j = 0; j < 20; j++)
	{
		if (niz[j] > max)
			max = niz[j];
		if (niz[j] < min)
			min = niz[j];
	}
	printf("Najveci i najmanji clanovi niza su %d i %d\n", max, min);*/

	//8.
	/*double srednjaVredost;
	int n;
	printf("Unesite dimenziju niza: \n");
	scanf("%d", &n);
	int niz[50];
	int suma = 0;
	printf("Unesite clanove niza:\n");
	for (int i = 0; i < n; i++)
	{
		scanf(" %d", &niz[i]);
	}
	for (int j = 0; j < n; j++)
	{
		suma += niz[j];
	}
	printf("Srednja vrednost je: %.2lf\n", (double)suma / n);*/

	//9.
	/*int niz1[50],niz[50];
	printf("Unesite dimenziju niza:\n");
	int dimenzija;
	int dim1 = 0;
	scanf("%d", &dimenzija);
	for (int i = 0; i < dimenzija; i++)
	{
		scanf("%d", &niz[i]);
	}
	printf("Unesite zeljeni broj.\n");
	int broj;
	scanf("%d", &broj);
	for (int j = 0; j < dimenzija; j++)
	{
		if (niz[j] > broj) {
			niz1[dim1++]=niz[j];
		}
	}
	printf("\n");

	for (int k = 0; k < dim1; k++)
	{
		printf("%d\n",niz1[k]);
	}*/

	//10.Matrice Transponovana	
	/*int mat[10][10];
	printf("Unesite dimenzije matrice\n");
	int m, n;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf(" %d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n+++++++++++++++++++\n");
	for (int k = 0; k < n; k++) {
		for (int l = 0; l < m; l++) {
			printf(" %d ", mat[l][k]);
		}
		printf("\n");
	}*/
	
	//11.
	/*int m[10][10];
	int n[10][10];
	int zbir[10][10];

	int a, b;
	printf("Unesite dimenzije matrica:\n");
	scanf("%d %d", &a, &b);
	printf("Unesite elemente matrice m: \n");
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			scanf("%d", &m[i][j]);
		}
	}

	printf("Unesite elemente matrice n: \n");
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			scanf("%d", &n[i][j]);
		}
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			zbir[i][j] = (m[i][j] + n[i][j]);
		}
	}
	printf("Prva matrica: \n");
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			printf(" %d ", m[i][j]);
		}
		printf("\n");
	}
	printf("Druga matrica:\n");
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			printf(" %d ", n[i][j]);
		}
		printf("\n");
	}
	printf("Zbirna matrica: \n");
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			printf(" %d ", zbir[i][j]);
		}
		printf("\n");
	}*/

	//12. Ovde ima neka zanimljivost
	/*int m[10][10];
	int n[10][10];
	int proizvod[10][10];

	int a, b;
	printf("Unesite dimenzije matrice m :\n");
	scanf("%d %d", &a, &b);
	int c, d;
	printf("Unesite dimenzije matrice n :\n");
	scanf("%d %d", &c, &d);

	if (b != c) {
		printf("Dimenzije matrice nisu korektne!\n");
	}
	else {
		printf("Unesite elemente matrice m: \n");
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				scanf("%d", &m[i][j]);
			}
		}

		printf("Unesite elemente matrice n: \n");
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < d; j++) {
				scanf("%d", &n[i][j]);
			}
		}

		for (int i = 0; i < a; i++) {
			for (int j = 0; j < d; j++) {
				proizvod[i][j] = 0;
				for (int k = 0; k < b; k++) {
					proizvod[i][j] += (m[i][k] * n[k][j]);
				}
			}
		}
		printf("Prva matrica: \n");
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				printf(" %d ", m[i][j]);
			}
			printf("\n");
		}
		printf("Druga matrica:\n");
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < d; j++) {
				printf(" %d ", n[i][j]);
			}
			printf("\n");
		}
		printf("Proizvod matrica: \n");
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < d; j++) {
				printf(" %d ", proizvod[i][j]);
			}
			printf("\n");
		}
	}*/

	//13.
	/*int dimenzijaMat;
	int mat[10][10];
	int izbor;

	printf("Unesite dimenizju matrice: \n");
	scanf("%d", &dimenzijaMat);

	for (int i = 0; i < dimenzijaMat; i++) {
		for (int j = 0; j < dimenzijaMat; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

	printf("\n+++++++++++++++\n");

	for (int i = 0; i < dimenzijaMat; i++) {
		for (int j = 0; j < dimenzijaMat; j++) {
			printf("%d", mat[i][j]);
		}
		printf("\n");
	}


	printf("Dijagonala matrice: \n");
	for (int i = 0; i < dimenzijaMat; i++) {
		for (int j = 0; j < dimenzijaMat; j++) {
			if (i == j) {
				printf("%d\t", mat[i][j]);
			}
		}
	}

	printf("Unesite zeljeni broj : \n");
	scanf("%d", &izbor);
	
	if (izbor == 0) {
		for (int i = 0; i < dimenzijaMat; i++) {
			for (int j = 0; j < dimenzijaMat; j++) {
				if (i == j) {
					printf("%d\t", mat[i][j]);
				}
			}
		}
	}
	else if (izbor == 1) {
		for (int i = 0; i < dimenzijaMat; i++) {
			for (int j = 0; j < dimenzijaMat; j++) {
				if (i==j-1) {
					printf("%d\t", mat[i][j]);
				}
			}
		}
	}
	else {
		for (int i = 0; i < dimenzijaMat; i++) {
			for (int j = 0; j < dimenzijaMat; j++) {
				if (i-1 == j) {
					printf("%d\t", mat[i][j]);
				}
			}
		}
	}*/

	//14.
	/*int niz[50];
	int m[10][10];
	int dim;
	int brEl=0;
	printf("Unesite dimenziju matrice:\n");
	scanf("%d", &dim);
	printf("Unesite elemente matrice: \n");
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			scanf("%d", &m[i][j]);
		}
	}
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			niz[brEl++] = m[j][i];
		}
	}
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			printf(" %d ", m[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < brEl; i++)
	{
		printf("%d  ", niz[i]);
	}
	printf("\n");*/

	//15. Stringovi
	/*char string[50];
	printf("Unesite string: ");
	gets(string);
	puts(string);
	int i = 0;
	while (string[i] != '\0') {
		if (string[i] >= 'a' && string[i] <= 'z') {
			string[i] += 'A' - 'a';
		}
		i++;
	}
	puts(string);*/

	/*16.*/
	//char imena[20][15];
	//double ulog[20];
	//double prosek=0.0;
	//int brLica;
	//printf("Unesite broj lica: \n");
	//scanf("%d", &brLica);
	//for (int i = 0; i < brLica; i++)
	//{
	//	printf("Unesite ime i ulog!\n");
	//	scanf("%s %lf",imena[i], &ulog[i]); // <------------------ kod imena nema "&"...
	//	prosek += ulog[i];
	//}
	//prosek /= brLica;
	//puts("Ulog veci od proseka imaju: \n");
	//for (int i = 0; i < brLica; i++)
	//{
	//	if (ulog[i] > prosek) {
	//		printf("%s\t\t%6.2lf\n", imena[i],ulog[i]);
	//	}
	//}

	//17. Ne saradjuje 160 strana
	/*char reci[50][11];
	int brReci, uslov;
	printf("Koliko reci zelite da unesete.\n");
	scanf("%d", &brReci);
	for (int i = 0; i < brReci; i++)
	{
		scanf("%s", reci[i]);
	}
	int brojac = 0;
	for (int i = 0; i < brReci-1; i++) {
		uslov = 1;
		for (int j = i+1; j < brReci; j++) {
			if (strcmp(reci[i], reci[j]) == 0)
				uslov = 0;
			brojac += uslov;
		}
	}
	printf("Razlicitih reci ima: %d\n", brojac);*/

	//18.
	/*char redovi[50][80], maloSlovo;
	int brojRed = 0, slova[26] = { 0 };
	printf("Unesite redove\n");
	gets(redovi[brojRed]);
	while (strlen(redovi[brojRed]) != 0)
		gets(redovi[++brojRed]);
	for (int  i = 0; i < brojRed; i++)
	{
		int j = 0;
		while (redovi[i][j] != '\0') {
			if (isalpha(redovi[i][j])) {
				maloSlovo = tolower(redovi[i][j]);
				slova[maloSlovo - 'a']++;
			}
			j++;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (slova[i] > 0) {
			printf("Slovo %c ----> %d puta!\n", 'a' + i, slova[i]);
		}
		*/

	//19.
	/*int broj;
	char rim[30], pom1, pom2, pom3;
	int i = 0, del,cif;
	puts("Unesite prirodan broj!");
	scanf("%d", &broj);
	if (broj <= 0) {
		puts("Pogresna vrednost broja.");
		exit(0);
	}
	while (broj>=1000) {
		rim[i++] = 'M';
		broj -= 1000;
	}
	while (broj != 0) {
		if (broj >= 100) {
			pom1 = 'M'; pom2 = 'D'; pom3 = 'C';
			del = 100;
		}
		if (broj < 100 && broj >= 10) {
			pom1 = 'C'; pom2 = 'L'; pom3 = 'X';
			del = 10;
		}
		else
		{
			pom1 = 'X'; pom2 = 'V'; pom3 = 'I';
			del = 1;
		}
		cif = broj / del;
		if (cif == 9) {
			rim[i++] = pom3;
			rim[i++] = pom1;
		}
		else if (cif >= 5) {
			rim[i++] = pom2;
			while (cif > 5) {
				rim[i++] = pom3;
				cif--;
			}
		}
		else if (cif == 4) {
			rim[i++] = pom3;
			rim[i++] = pom2;
		}
		else if (cif >= 1) {
			while (cif > 0) {
				rim[i++] = pom3;
				cif--;
			}
		}
		broj = broj % del;
	}
	rim[i] = '\0';
	printf("Rimski broj je %s\n", rim);*/

	//20. Funkcije
	/*int broj;
	printf("Unesite Broj!\n");
	scanf("%d", &broj);
	
	for (int i = 1; i < broj; i++) {
		if (prostBroj(i) == 1)
			printf("%d\t", i);
	}
	printf("\n");*/

	//21.
	//int n;
	//printf("Unesite koliko brojeva zelite.\n");
	//scanf("%d", &n);
	//int i=1, j = 0;
	//printf("Prosti brojevi su.\n");
	//while (j < n) {
	//	if (prostBroj(i)) {
	//		printf("%d \n", i);
	//		j++;
	//	}
	//		i++;
	//}

	//22.	
	/*	int niz[100];
	int brEl;
	printf("Unesite broj elemenata niza: \n");
	scanf("%d", &brEl);
	for (int i = 0; i < brEl; i++)
	{
		printf("Unesite %d. element niza:  ", i + 1);
		scanf("%d", &niz[i]);
	}
	printf("Srednja vrednost datog niza je: %.2lf\n", srednjaVrednost(niz, brEl));*/

	//23.
	/*char str[] = "Banarama";
	printf("%s\n\n", str);
	printf("String glasi: %s,\n Bilo je %d  izmena.", str, zameniSlovo(str, 'a', 'B'));*/

	//24.
	/*char s[] = "Muzika je lak izum";
	printf("%s\n", s);
	obrniString(s);
	printf("%s, ovako izgleda obrnut string\n", s);*/

	//25.
	//char s[20];
	//char s1[20];
	//puts("Unesite dva stringa:");
	//gets(s);
	//gets(s1);
	//if (poredjenje(s, s1)) {
	//	printf("Isti.\n");
	//}
	//else
	//	printf("Razliciti.\n");
		
	//25.
	/*char str[50];
	char k;
	puts("Unesite string.");
	gets(str);
	puts("Unesite karakter za uklanjanje:");
	scanf("%c", &k);

	printf("Ovako izgleda string bez datog karaktera: %s\npritom je uklonjeno %d karaktera.\n",str,ukloniKarakter(str, k));*/

	//26.
	/*char s[50] = "Ovo jeXYZ neki string i neka se uklone karakteri.";
	puts(s);
	uzastopni(s, 6, 3);
	puts(s);*/

	//27.
	/*char s[50];
	char a[20];
	puts("Unesite dva stringa");
	gets(s);
	gets(a);
	int b=poklapaje(s, a);
	printf("Prvih %d se poklapaju za data dva stringa.\n", b);*/

	//28. 
	/*int m[10][10];
	printf("Unesite dimenziju matrice.\n");
	int a;
	scanf("%d", &a);
	puts("Unesite elemente matrice:");
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			scanf("%d", &m[i][j]);
		}
	}
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	maksimalniElementMatriceIPozicija(m, a);*/

	//29. Sortiranje nizova...
	//int niz[30];
	//puts("Unesite broj clanova niza.");
	//int m;
	//scanf("%d", &m);
	//puts("Unesite clanove niza: ");
	//for (int i = 0; i < m; i++)
	//{
	//	scanf("%d", &niz[i]);
	//}
	//preuredjivanje(niz, m);


	//30.
	//int niz[30];
	//int niz1[30];
	//int niz2[50];
	//puts("Unesite dimenzije nizova.");
	//int m, n;
	//scanf("%d %d", &m, &n);
	//puts("Unesite clanove prvog niza:");
	//for (int i = 0; i < m; i++) {
	//	scanf("%d", &niz[i]);
	//}
	//puts("Unesite clanove drugog niza:");
	//for (int i = 0; i < n; i++) {
	//	scanf("%d", &niz1[i]);
	//}
	//spajanje(niz, niz1, niz2, m, n);
	//puts("Preuredjeni niz izgleda:");
	//for (int i = 0; i < m+n; i++) {
	//	printf("%d ", niz2[i]);
	//}

	


	system("pause");
	return 0;
}