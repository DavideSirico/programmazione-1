#include <iostream>
#include <fstream>
using namespace std;



/*
 Verifichi quindi che la somma calcolata corrisponda al risultato contenuto nel file. Se la somma
è corretta, la scriva (in rappresentazione decimale) nella corrispondente riga del file
outputcheck.txt, altrimenti scriva "Errore".
*/
int somma(int a[], int n);
void elaborariga(char *str, int num[13], int &ris);
int converti(int b[], int n);
int main() {


    fstream in;
    fstream out;
    in.open("../inputdati.txt", ios::in);
    out.open("../outputcheck.txt", ios::out);

    if(in.fail() || out.fail()) {
        cout << "Errore nell'apertura del file";
        return 0;
    }
    char row[128];
    while(in >> row) {
        int ris = 0;
        int numbers[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
        elaborariga(row, numbers, ris);
        if(ris == somma(numbers,13)) {
            out << ris;
        } else {
            out << "Errore";
        }
        out << endl;
        
    }

    out.close();
    in.close();


    return 0;
}

/*
Chiami la funzione elaborariga per ottenere gli addendi e il risultato della somma contenuti nella
riga del file. La funzione riceve come parametri una stringa str, un array num di 13 numeri interi
e, per riferimento, un numero intero ris. La funzione riceve nella stringa str una riga del file
inputdati.txt, scorre la stringa e assegna agli elementi dell’array num la rappresentazione decimale
dei numeri binari contenuti nella stringa prima del carattere ’=’. Se str contiene meno di 13
addendi, gli elementi non utilizzati dell’array num vengono impostati a zero. La funzione assegna
infine al parametro ris la rappresentazione decimale del numero binario che si trova dopo il
carattere ’=’. La funzione non restituisce alcun valore di ritorno.
*/

void elaborariga(char *str, int num[13], int &ris) {
    int i = 0;
    int dim_riga = 0;
    while(str[i]!='=') {
        char current_char = str[i];
        if(current_char == '+') {
            i++;
            continue;
        }
        int dim = 0;
        int numero_binario[8] = {0,0,0,0,0,0,0,0};
        int j = i;
        while(str[j]!='=' && str[j]!='+') {
            if(str[j] == '1') {
                numero_binario[dim] = 1;
            } else {
                numero_binario[dim] = 0;
            }
            dim++;
            j++;
        }

        num[dim_riga] = converti(numero_binario, dim);
        dim_riga++;
        i = j;
    }
    int dim = 0;
    int numero_binario[8] = {0,0,0,0,0,0,0,0};
    while(str[i]!=';') {
        if(str[i] == '1') {
            numero_binario[dim] = 1;
        } else {
            numero_binario[dim] = 0;
        }
        dim++;
        i++;
    }
    ris = converti(numero_binario, dim);
}
/*
Per effettuare la conversione in decimale si sviluppi una funzione converti che riceva in ingresso un array di numeri interi b e la
sua dimensione n e restituisca come valore di ritorno un numero intero. Gli elementi di b possono
valere soltanto 0 oppure 1 e sono i bit della rappresentazione binaria di un numero intero positivo.
La funzione calcolerà e ritornerà la rappresentazione decimale dello stesso numero.
*/
int converti(int b[], int n) {
    int pow = 1;
    int ris = 0;
    for(int i = n-1; i >= 0; i--) {
        ris += b[i]*pow;
        pow = pow * 2;
    }
    return ris;
}

/*
Chiami la funzione somma per calcolare il risultato corretto della somma degli addendi. Tale
funzione riceve come parametri un array a di numeri interi e la sua dimensione n e restituisce
come valore di ritorno la somma degli elementi contenuti nell’array (un numero intero).*/
int somma(int a[], int n) {
    int somma = 0;
    for(int i = 0; i < n; i++) { 
        somma += a[i];
    }
    return somma;
}