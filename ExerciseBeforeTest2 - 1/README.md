# Esercitazione su Strutture Lineari Semplici – Ufficio Postale
Progettare ed implementare in ANSI C un programma che permetta di gestire 4 code di attesa in
uno studio medico.
Ogni singola coda gestisce i pazienti in attesa di uno dei medici, i medici sono
identificati dai numeri 0, 1, 2, 3.
Ogni paziente è identificato dai seguenti attributi
- Codice Fiscale
- Cognome (senza spazi bianchi)
- Nome (senza spazi bianchi)
- Urgenza (valore booleano implementato con gli interi)
0) Progettare la struttura dati adatta a mantenere in memoria centrale le informazioni utilizzando
strutture e puntatori per la coda;
1) Scrivere un opportuno main in cui sia previsto un menù di scelta delle operazioni richieste. Tutti
i valori necessari al funzionamento devono essere passati utilizzando parametri, non è permesso
l’uso di variabili globali;
2) Realizzare una funzione che legga da file i dati dei pazienti e li inserisca nelle code appropriate;
3) Scrivere una funzione che, dato il medico tramite il suo codice numerico (0, 1, 2, 3) estrae il
primo paziente in attesa e lo restituisce al main all’interno del quale viene stampato (nota che
questo implica che la funzione non deve eseguire alcuna operazione di i/o al suo interno)
4) Scrivere una funzione che restituisca in una coda (diversa da quelle presenti) tutti i pazienti
presenti nella lista di attesa di un medico in cui il valore di urgenza sia vero (nota che non è
richiesta la cancellazione dalla struttura dati principale)
5) Scrivere una funzione che restituisca in un vettore il numero di pazienti presenti in ogni lista
(l’elemento di indice 0 contiene il numero di pazienti nella coda del medico 0, l’elemento di
indice 1 contiene il numero di pazienti nella coda del medico 1, ecc.)
<h4>UniCT ExamTest</h4>
<p align="right"> 
lucadev23
</p>
