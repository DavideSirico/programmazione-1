#include <iostream>
#include <string.h> // definisce la funzione "int strlen (const char * array);"
#include <math.h>   // definisce la funzione "int pow (base, esponente);"
#include "pila.h"   // fare riferimento al file "pila.h" per le funzioni esposte

using namespace std;

int decodificaNumero(char numeroCodificato []);

int main() { 
    int dimensioneMassima = 9;
    char numeroCodificato [dimensioneMassima];
    cout << "Inserisci l'array: ";
    cin >> numeroCodificato;
    int decodifica = decodificaNumero(numeroCodificato);
    cout << "Decodifica: " << decodifica << endl;
}

int decodificaNumero(char numeroCodificato []) {
    int ris = 0;
    int lenCodifica = strlen(numeroCodificato);
    int esponente = lenCodifica;
    init();
    
    for (int i = 0; i <= lenCodifica; i++) {
        // inserisco i+1 nella pila
        push(i+1);
        // se il carattere corrente rappresenta un maggiore
        // oppure ho raggiunto l’ultimo carattere
        if(numeroCodificato[i]=='I' || lenCodifica == i) {
            while(!vuota()) {
                int numero;
                top(numero);
                ris+=pow(10,esponente)*numero;
                esponente--;
                cout << numero << endl;
                pop();
            }
        }
        // calcolo la cifra corrente svuotando lo stack,
        // aggiornando le variabili esponente e numero
    }
    deinit();
    return ris;
}
