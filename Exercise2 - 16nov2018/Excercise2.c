#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#define M 5

struct struttura {
	int primo;
	int secondo;
}typedef coppia;

void init(coppia *);
void stampaStruttura(coppia *);
void creaStampaVettore(coppia *, int *);
void coppiaValoreMaggiore(coppia *);
void mediaTotale(coppia *);

int main(void) {
	coppia vet[M];
	int w[M],scel;
	init(vet);
	while (1) {
		system("CLS");
		printf("Menu\n");
		printf("\t0 - Stampa struttura intera\n");
		printf("\t1 - Crea e Stampa un vettore w con i valori maggiori di ogni coppia\n");
		printf("\t2 - Stampare coppia con valore medio maggiore\n");
		printf("\t3 - Stampare la media di tutti i valori\n");
		printf("\t4- Esci\n");
		printf("\nScegli: ");
		fflush(stdin);
		scanf("%d", &scel);
		if (scel < 0 || scel > 4) {
			printf("Digita un valore tra 1 e 4 !");
			continue;
		}
		else {
			switch (scel) {
				case 0:
					system("CLS");
					stampaStruttura(vet);
					break;
				case 1:
					system("CLS");
					creaStampaVettore(vet, w);
					break;
				case 2:
					system("CLS");
					coppiaValoreMaggiore(vet);
					break;
				case 3:
					system("CLS");
					mediaTotale(vet);
					break;
				case 4:
					return 0;
			}
		}
	}
}

void init(coppia vet[]) {
	int i;
	printf("Riempire le strutture con dei valori numerici\n");
	for (i = 0; i < M; i++) {
		printf("\nValore 1 dell'elemento %d: ", (i + 1));
		scanf("%d", &vet[i].primo);
		printf("Valore 2 dell'elemento %d: ", (i + 1));
		scanf("%d", &vet[i].secondo);
	}
}

void stampaStruttura(coppia vet[]) {
	int i;
	printf("Stampa Struttura\n");
	for (i = 0; i < M; i++) {
		printf("\nValore 1 dell'elemento %d: %d\n", (i + 1), vet[i].primo);
		printf("Valore 2 dell'elemento %d: %d\n", (i + 1), vet[i].secondo);
	}
	system("PAUSE");
}

void creaStampaVettore(coppia vet[], int w[]) {
	int i, j = 0;
	printf("Creazione e stampa del vettore w\n\n");
	for (i = 0; i < M; i++) {
		if (vet[i].primo >= vet[i].secondo) {
			w[j] = vet[i].primo;
		}
		else {
			w[j] = vet[i].secondo;
		}
		printf("%d Elemento del vettore w: %d\n", (j + 1), w[j]);
		j++;
	}
	system("PAUSE");
}

void coppiaValoreMaggiore(coppia vet[]) {
	int i, j=0;
	float v[M], maxValue=0;
	for (i = 0; i < M; i++) {
		v[i] = ((float)(vet[i].primo + vet[i].secondo)) / 2;
		if (maxValue < v[i]) {
			maxValue = v[i];
			j = i;
		}
	}
	printf("Coppia con valor medio maggiore e la sua posizione\n\n");
	printf("Posizione: %d\n",(j+1));
	printf("Valore 1: %d\n", vet[j].primo);
	printf("Valore 2: %d\n", vet[j].secondo);
	system("PAUSE");
}

void mediaTotale(coppia vet[]) {
	int i,sum=0;
	for (i = 0; i < M; i++) {
		sum += vet[i].primo;
		sum += vet[i].secondo;
	}
	printf("Media di tutti i valori: %f\n", (float)(sum / (M * 2)));
	system("PAUSE");
}