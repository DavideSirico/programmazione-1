#include <iostream>
#include <fstream>

// Inserire qui sotto la soluzione all'esercizio
/*
Il file inputdati.txt contiene, per ciascuna riga, una somma di numeri interi positivi in
rappresentazione binaria e il risultato della somma stessa secondo il seguente formato:
Il numero di righe di cui si compone il file non è noto al programmatore. Ciascuna riga contiene al più 127 caratteri. I numeri binari sono composti al più da 8 bit. Ogni riga contiene almeno 2 e non più di 13 addendi . Si supponga, inoltre, che i dati siano validi (è cioè garantito che tutte le righe del file seguono il formato specificato, quindi non è necessario controllare che il formato sia corretto). Non è però garantito che i risultati delle somme nel file siano corretti.
Si scarichi il file esercizio1.cpp e al suo interno si sviluppi un programma C++ che operi come segue:
• Apra in lettura il file inputdati.txt e in scrittura il file outputcheck.txt controllando che l’apertura di entrambi i file abbia avuto successo.
• Per ciascuna riga del file inputdati.txt, legga la riga in un’opportuna stringa di caratteri.
• Chiami la funzione somma per calcolare il risultato corretto della somma degli addendi. Tale funzione riceve come parametri un array a di numeri interi e la sua dimensione n e restituisce come valore di ritorno la somma degli elementi contenuti nell’array (un numero intero).
• Verifichi quindi che la somma calcolata corrisponda al risultato contenuto nel file. Se la somma è corretta, la scriva (in rappresentazione decimale) nella corrispondente riga del file outputcheck.txt, altrimenti scriva "Errore".
• Dopo aver elaborato l’intero file inputdati.txt, chiuda entrambi i file. 1
          
Ad esempio, nel caso sopra riportato, il programma individuerà due somme corrette, e una somma errata. Il file outputcheck.txt conterrà le seguenti righe:
marco > a.out
marco > cat outputcheck.txt
30
8
Errore
*/
using namespace std;

/*
Chiami la funzione elaborariga per ottenere gli addendi e il risultato della somma contenuti nella riga del file. La funzione riceve come parametri una stringa str, un array num di 13 numeri interi e, per riferimento, un numero intero ris. La funzione riceve nella stringa str una riga del file inputdati.txt, scorre la stringa e assegna agli elementi dell’array num la rappresentazione decimale dei numeri binari contenuti nella stringa prima del carat- tere ’=’. Se str contiene meno di 13 addendi , gli elementi non utilizzati dell’array num vengono impostati a zero. La funzione assegna infine al parametro ris la rappresentazione decimale del numero binario che si trova dopo il carattere ’=’. La funzione non restituisce alcun valore di ritorno. Per effettuare la conversione in decimale si sviluppi una funzione converti che riceva in ingresso un array di numeri interi b e la sua dimensione n e resti- tuisca come valore di ritorno un numero intero. Gli elementi dell’array b possono valere soltanto 0 oppure 1 e sono i bit della rappresentazione binaria di un numero intero positivo. La funzione calcolerà e restituirà come valore di ritorno la rappresentazione decimale dello stesso numero.
*/
void elaborariga(char str[], int num[], int& ris) {
    char current_char = str[0];  
    while(current_char != '\0') {
        
    }
}

int main() {
    char linea[127];
    fstream fin, fout;

    fin.open("inputdati.txt", ios::in);
    fout.open("outputcheck.txt", ios::out);

    if (fin.fail() || fout.fail()) {
        cout << "Errore nell'apertura dei file";
        return 1;
    }

    fin >> linea;
    while (!fin.eof()) {
         
    }
    fin.close();
    fout.close();

    return 0;
}

