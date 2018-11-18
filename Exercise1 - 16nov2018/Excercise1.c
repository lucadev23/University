#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#define N 10

int init(int *);
void stampaVettore(int *,int);
int maxValore(int *,int);
float mediaValoriPari(int *, int);
void stampaValoriPositivi(int*, int);


int main(void) {
	int v[N] = { 0 },count=0,max=0,c=0; //count corrisponde al numero di valori inseriti nel vettore, se inserisco 4 valori, i restanti 6 non mi interessano
	float med = 0.0;
	count=init(v);
	if (count == 0) {
		system("CLS");
		printf("NESSUN VALORE PRESENTE NEL VETTORE!\n");
		system("PAUSE");
		return 0;
	}
	while (1) {
		system("CLS");
		printf("Menu\n");
		printf("\t1 - Stampa contenuto vettore\n");
		printf("\t2 - Cerca valore massimo\n");
		printf("\t3 - Calcola media valori pari\n");
		printf("\t4 - Stampa tutti gli elementi positivi nel vettore\n");
		printf("\t5 - Esci\n");
		printf("Digita un valore: ");
		fflush(stdin);
		scanf("%d", &c);
		if(c>=1 && c<=5) {
			switch (c) {
				case 1:
					stampaVettore(v, count);
					system("PAUSE");
					break;
				case 2:
					max = maxValore(v, count);
					system("CLS");
					printf("Valore massimo: %d\n", max);
					system("PAUSE");
					break;
				case 3:
					med = mediaValoriPari(v, count);
					system("CLS");
					printf("Media dei valori pari: %f\n", med);
					system("PAUSE");
					break;
				case 4:
					stampaValoriPositivi(v, count);
					system("PAUSE");
					break;
				case 5:
					return 0;
			}
		}
		else{
			printf("\nInserisci un valore compreso tra 1 e 5 !\n");
			system("PAUSE");
		}
	}
}

int init(int v[]) {
	int i = 0, count = 0, c = 1; //c=1 così il ciclo può iniziare
	printf("Inserimento di %d valori interi non nulli! L'inserimento del valore 0 causa la terminazione del caricamento dei valori\n", N);
	while (c != 0 && i < N) {
		printf("Inserisci l'elemento %d: ", (i + 1));
		scanf("%d", &c);
		if (c != 0) {
			v[count] = c;
			count++;
		}
		i++;
	}
	return count;
}

void stampaVettore(int v[],int count) {
	int i;
	system("CLS");
	printf("Contenuto del vettore:\n");
	for (i = 0; i < count; i++) {
		printf("Valore %d: %d\n", (i + 1), v[i]);
	}
}

int maxValore(int v[], int count) {
	int i,max=v[0];
	for (i = 0; i < count; i++) {
		if (max < v[i]) {
			max = v[i];
		}
	}
	return max;
}

float mediaValoriPari(int v[], int count) {
	int i,j=0;
	float somma = 0;
	for (i = 0; i < count; i++) {
		if (v[i] % 2 == 0) {
			somma += v[i];
			j++;
		}
	}
	if (j != 0) {
		return (float)(somma / j);
	}
	else {
		return (float)(0); //se non è presente nessun valore pari
	}
	 
}

void stampaValoriPositivi(int v[], int count) {
	int i;
	system("CLS");
	printf("Stampo valori positivi\n");
	for (i = 0; i < count; i++) {
		if (v[i] % 2 == 0) {
			printf("%d elemento del vettore: %d\n", (i + 1), v[i]);
		}
	}
}