#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void izDatotekeUMatricu(int mat[][10], int *n, int *m, char s[]) {
	FILE *a = fopen(s, "r");
	if (a == NULL) {
		puts("Greska prilikom otvaranja.");
		return;
	}
	fscanf(a, "%d %d", n, m);

	for (int i = 0; i < *n; i++)
	{
		for (int j = 0; j < *m; j++)
		{
			fscanf(a, "%d ", &mat[i][j]);
		}
	}
	fclose(a);
}
void prozivod2Matrice(int mat1[][10], int mat2[][10], int mat3[][10], int red1, int kol2, int kol1, int red2,int *red3, int *kol3) {

	if (kol1 != red2) {
		printf("Matrice nisu odgovarajucih dimenzija\n");
		return;
	}
	int a = 0;
	for (int i = 0; i < red1; i++)
	{
		for (int j = 0; j < kol2; j++)
		{
			for (int p = 0; p < red2; p++)
			{
				a += mat1[i][p] * mat2[p][j];
			}
			mat3[i][j] = a;
			a = 0;
		}
	}
	*red3 = red1;
	*kol3 = kol2;
}
void prikazMatrice(int mat[][10], int n, int m) {
	puts("MATRICA: \n");
	for (int i = 0; i < n; i++)
	{
		for (int  j = 0; j < m; j++)
		{
			printf(" %d  ", mat[i][j]);
		}
		printf("\n");
	}
}
typedef struct radnik
{
	char imeprezime[31];
	double ukupnoBodova;
	double kvalitet[7];
	double vreme;
	double bodoviKvalitet;
	double bodoviZaVreme;
	
}RADNIK;
RADNIK unosZaposlenog() {
	RADNIK r;
	printf("Unesite ime i prezime zaposlenog.\n");
	gets(r.imeprezime);
	printf("Unesite vreme koje mu je trebalo da izradi deo.\n");
	scanf("%lf", &r.vreme);
	printf("Unesite ocene koje je dobio za kvalitet: \n");
	for (int i = 0; i < 7; i++)
	{
		double ocena;
		printf("%d. Strucnjak: ", i + 1);
		scanf("%lf", &ocena);
		if (ocena < 10 || ocena>20) {
			printf("Losa ocena. Ocena je u intervalu od 10-20. \n");
			printf("%d. Strucnjak: ", i + 1);
			scanf("%lf", &ocena);
			if (ocena > 10 && ocena < 20) {
				r.kvalitet[i] = ocena;
			}
			else {
				continue;
			}
		}
		else {
			r.kvalitet[i] = ocena;
		}
		ocena;
	}
	return r;
}
double bodoviZaVreme(double vreme) {
	double bodovi = 120.00;
	if (vreme == 20) {
		return 120.0;
	}
	if (vreme < 20) {
		for (double i = (2*vreme); i <=40; i++)
		{
			bodovi = bodovi + 1.40;
		}
		return bodovi;
	}
	if (vreme > 20) {
		for (double i = 20*2; i<=(vreme*2) ; i++)
		{
			bodovi = bodovi - 1.20;
		}
		return bodovi;
	}
}
double bodoviKvalitet(double niz[]) {
	double min = 21.0;
	double max = 9.0;
	double suma = 0.0;
	for (int i = 0; i < 7; i++)
	{
		if (niz[i] > max) {
			max = niz[i];
		}
		if (niz[i] < min) {
			min = niz[i];
		}
	}
	for (int j = 0; j < 7; j++)
	{
		suma += niz[j];
	}
	return (suma - min - max) / 5.0;
}
void unosUNizRadnika(RADNIK radnici[], int *dim) {
	printf("Unosite radnike, za prekid unosa stisnite 0 kad zavrsite sa jednim radnikom.\n");
	int izbor;
	while (1)
	{
		double ukupniBodovi = 0;
		RADNIK r = unosZaposlenog();
		r.bodoviZaVreme = bodoviZaVreme(r.vreme);
		r.bodoviKvalitet = bodoviKvalitet(r.kvalitet);
		ukupniBodovi = r.bodoviKvalitet + r.bodoviZaVreme;
		r.ukupnoBodova = ukupniBodovi;
		radnici[(*dim)++] = r;
		printf("Jos radnika? [0-ne]\n");
		scanf("%d", &izbor);
		getchar();
		if (izbor == 0) {
			break;
		}
	}
}
void prikazRadnika(RADNIK r[], int dim) {
	FILE *a = fopen("radnici.txt", "w");
	if (a == NULL) {
		printf("Greska");
		return;
	}
	fprintf(a,"Toyota JAPAN:\n");
	for (int  i = 0; i < dim; i++)
	{
		fprintf(a, "Zaposleni:%s\n\n\tVREME IZRADE:%.2lf\tBodovi za vreme: %.2lf\nOcene za kvalitet: { ", r[i].imeprezime, r[i].vreme, r[i].bodoviZaVreme);
		for (int j = 0; j < 7; j++)
		{
			fprintf(a,"%.2lf ", r[i].kvalitet[j]);
		}
		fprintf(a,"} Prosecno bodova: %.2lf\nUkupno bodova: %.2lf\n",r[i].bodoviKvalitet, r[i].ukupnoBodova);
	fprintf(a,"\n-----------------------------------------------------------------------------\n");
	}
	fclose(a);
}

int main(void) {

	int mat1[10][10];
	int mat2[10][10];
	int mat3[10][10];
	int n1, m1, n2, m2, n3, m3;
	//izDatotekeUMatricu(mat1, &n1, &m1,"matrica1.txt");
	//izDatotekeUMatricu(mat2, &n2, &m2,"matrica2.txt");
	//prozivod2Matrice(mat1, mat2, mat3, n1, m2, m1, n2,&n3,&m3);
	//prikazMatrice(mat1, n1, m1);
	//prikazMatrice(mat2, n2, m2);
	//prikazMatrice(mat3, n3, m3);
	RADNIK radnici[100];
	int dim = 0;
	unosUNizRadnika(radnici, &dim);
	prikazRadnika(radnici, dim);

	system("pause");
	return 0;
}