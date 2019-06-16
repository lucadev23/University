#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Intestazione.h"

int  main(void) {
	int scel = 0;
	int medico = 0;
	int vet[4] = { 0 };
	paziente p;
	p_coda codaUrgenti = NULL;
	p_coda vCode[4] = { NULL };
	do {
		scel = menu();
		switch (scel) {
			case -1:
				break;
			case 0:
				return 0;
			case 1:
				caricaCode(vCode);
				break;
			case 2:
				medico = scegliMedico();
				if (estraiPazienteDaMedico(medico, &p, vCode) == 1) {
					stampaPaziente(p);
				}
				else {
					printf("Nessun paziente\n");
					system("PAUSE");
				}
				break;
			case 3:
				codaUrgenti = (p_coda)malloc(sizeof(coda));
				codaUrgenti->primo = NULL;
				codaUrgenti->ultimo = NULL;
				estraiUrgenti(vCode,&codaUrgenti);
				free(codaUrgenti);
				break;
			case 4:
				numeroPazientiTot(vet,vCode);
				break;
		}
	} while (scel != 0);
	return 0;
}

int estraiPazienteDaMedico(int medico, paziente* p, p_coda v[]) {
	p_nodo aux;
	if (medico < 0 || medico>4) {
		return 0;
	}
	if (v[medico] == NULL || v[medico]->primo == NULL) {
		return 0;
	}
	aux = v[medico]->primo;
	strcpy((*p).cod, aux->p.cod);
	strcpy((*p).nome, aux->p.nome);
	strcpy((*p).cognome, aux->p.cognome);
	(*p).urgenza = aux->p.urgenza;
	if (v[medico]->primo == v[medico]->ultimo) {
		v[medico]->ultimo = NULL;
	}
	v[medico]->primo = v[medico]->primo->succ;
	free(aux);
	return 1;
}

void stampaVettore(int v[]) {
	int i;
	for (i = 0; i < 4; i++) {
		printf("Medico %d ---> %d pazienti\n", i, v[i]);
	}
	system("PAUSE");
}

void numeroPazientiTot(int v[], p_coda c[]) {
	int i = 0;
	int num = 0;
	p_nodo aux = NULL;
	do {
		if (c[i] == NULL) {
			break;
		}
		aux = c[i]->primo;
		while (aux!=NULL) {
			num++;
			aux = aux->succ;
		}
		v[i] = num;
		num = 0;
		i++;
	} while (i < 4);
	stampaVettore(v);
}

void creaCodaUrgenti(p_coda* coda, p_coda* p) {
	p_nodo nodo = NULL;
	if ((*coda) == NULL) {
		return;
	}
	nodo = (*coda)->primo;
	if (nodo == NULL) {
		(*p) = NULL;
		return;
	}
	while(nodo!=NULL) {
		if (nodo->p.urgenza == 1) {
			aggiungiElementoCoda(nodo->p, p);
		}
		nodo = nodo->succ;
	}
}

void estraiUrgenti(p_coda code[], p_coda* p) {
	int medico = 0;
	medico = scegliMedico();
	switch (medico){
		case -1:
			return;
		case 0:
			if (code[0] == NULL || code[0]->primo==NULL) {
				printf("Coda Medico 0 Vuota\n");
				system("PAUSE");
				return;
			}
			creaCodaUrgenti(&code[0], p);
			break;
		case 1:
			if (code[1] == NULL || code[1]->primo == NULL) {
				printf("Coda Medico 1 Vuota\n");
				system("PAUSE");
				return;
			}
			creaCodaUrgenti(&code[1], p);
			break;
		case 2:
			if (code[2] == NULL || code[2]->primo == NULL) {
				printf("Coda Medico 2 Vuota\n");
				system("PAUSE");
				return;
			}
			creaCodaUrgenti(&code[2], p);
			break;
		case 3:
			if (code[3] == NULL || code[3]->primo == NULL) {
				printf("Coda Medico 3 Vuota\n");
				system("PAUSE");
				return;
			}
			creaCodaUrgenti(&code[3], p);
			break;
		default:
			break;
	}
	stampaCoda(*p);
}

paziente estraiPaziente(p_coda* v) {
	p_nodo pN;
	paziente p;
	if ((*v) == NULL || (*v)->primo == NULL) {
		printf("Nessun paziente\n");
		return;
	}
	pN = (*v)->primo;
	strcpy(p.cod, pN->p.cod);
	strcpy(p.cognome, pN->p.cognome);
	strcpy(p.nome, pN->p.nome);
	p.urgenza = pN->p.urgenza;
	if ((*v)->primo == (*v)->ultimo) {
		(*v)->ultimo = NULL;
	}
	(*v)->primo = (*v)->primo->succ;
	free(pN);
	return p;
}

int scegliMedico(void) {
	int medico = 0;
	do {
		printf("0 - Medico 0\n");
		printf("1 - Medico 1\n");
		printf("2 - Medico 2\n");
		printf("3 - Medico 3\n");
		printf("-1 - Esci\n");
		printf("Scegli: ");
		if (scanf("%d", &medico) != 1) {
			printf("Errore input\n");
			return -1;
		}
	} while (medico < -1 || medico>3);
	return medico;
}

void stampaPaziente(paziente p) {
	printf("Nome: %s\n", p.nome);
	printf("Cognome: %s\n", p.cognome);
	printf("Codice fiscale: %s\n", p.cod);
	printf("Urgenza: %d\n", p.urgenza);
	system("PAUSE");
}

void stampaCoda(p_coda c) {
	p_nodo aux = c->primo;
	int i = 1;
	while (aux != NULL) {
		stampaPaziente(aux->p);
		aux = aux->succ;
	}
}

void aggiungiElementoCoda(paziente p, p_coda* v) {
	p_nodo nodoP = NULL;
	if ((*v) == NULL) {
		return;
	}
	nodoP = (p_nodo)malloc(sizeof(nodo));
	nodoP->p = p;
	nodoP->succ = NULL;
	if ((*v)->primo == NULL) {
		(*v)->primo = nodoP;
		(*v)->ultimo = nodoP;
		return;
	}
	(*v)->ultimo->succ = nodoP;
}

void inizializzaCode(p_coda v[]) {
	int i;
	for (i = 0; i < 4; i++) {
		if ((v[i] = (p_coda)malloc(sizeof(coda))) == NULL) {
			printf("Errore allocazione memoria");
			system("PAUSE");
			return;
		}
		v[i]->primo = NULL;
		v[i]->ultimo = NULL;
	}
}

void caricaCode(p_coda v[]) {
	char buffer[64] = { '\0' };
	int medico = 0;
	FILE* fp = NULL;
	paziente p;
	printf("Inserisci il nome del file: ");
	if (scanf("%s", buffer) != 1) {
		printf("Errore Input\n");
		system("PAUSE");
		return -1;
	}
	if ((fp = fopen(buffer, "r")) == NULL) {
		printf("Errore apertura file\n");
		system("PAUSE");
		return -2;
	}
	inizializzaCode(v);
	while (fscanf(fp, "%s%s%s%d%d", p.cod, p.cognome, p.nome, &p.urgenza, &medico) == 5) {
		switch (medico) {
			case 0:
				aggiungiElementoCoda(p, &v[0]);
				break;
			case 1:
				aggiungiElementoCoda(p, &v[1]);
				break;
			case 2:
				aggiungiElementoCoda(p, &v[2]);
				break;
			case 3:
				aggiungiElementoCoda(p, &v[3]);
				break;
			default:
				break;
		}
	}
	fclose(fp);
}

int menu() {
	int scel = 0;
	do {
		system("CLS");
		printf("1 - Carica File\n");
		printf("2 - Estrai paziente\n");
		printf("3 - Estrai Urgenti\n");
		printf("4 - Numero Pazienti\n");
		printf("0 - Esci\n");
		printf("Scelta: ");
		if(scanf("%d", &scel) != 1){
			printf("Errore Input\n");
			system("PAUSE");
			return -1;
		}
	} while (scel < 0 || scel>4);
	system("CLS");
	return scel;
}
