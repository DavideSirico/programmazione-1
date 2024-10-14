#include <iostream>
using namespace std;

/*
Dati in input due interi, scrivere un programma che faccia la divisione
tramite una funzione; la funzione restituisce tramite valore di ritorno il
quoziente e tramite parametro per riferimento il resto.
In questo programma non si può usare il simbolo ‘/’ per la divisione
*/

int divisione(int dividendo, int divisore, int *resto);

int main() {
    int a,b;
    cin >> a >> b;
    int resto;
    cout << divisione(a,b,&resto) << " " << resto;
    
    return 0;
}

int divisione(int dividendo, int divisore, int *resto) {
    int ris = -1;
    while(dividendo >= 0) {
        *resto = dividendo;
        dividendo = dividendo - divisore;
        ris++;
    }
    return ris;
}
