#pragma once
#ifndef __CODA_H_

#define __CODA_H_

// strutture dati
typedef struct d_paziente {
	char nome[20];
	char cognome[20];
	char cod[17];
	int urgenza;
}paziente;

typedef struct d_coda {
	paziente p;
	struct d_coda* succ;
}nodo;

typedef nodo* p_nodo;

typedef struct cd {
	p_nodo primo;
	p_nodo ultimo;
}coda;

typedef coda* p_coda;

// firme funzioni
int menu(void);
void caricaCode(p_coda vCode[]);
void aggiungiElementoCoda(paziente p, p_coda* v);
void inizializzaCode(p_coda vCode[]);
void stampaCoda(p_coda c);
void stampaPaziente(paziente p);
void estraiUrgenti(p_coda vCode[], p_coda* p);
void creaCodaUrgenti(p_coda* coda, p_coda* p);
void numeroPazientiTot(int v[], p_coda vCode[]);
int estraiPazienteDaMedico(int medico, paziente* p, p_coda vCode[]);

#endif // !__CODA_H_
