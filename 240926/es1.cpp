#include <iostream>
using namespace std;

/*
Scrivere un programma C++ che, dati in input due numeri interi,
a e b, calcoli il risultato, in valore assoluto,
dell’operazione (a-b).
(senza utilizzare funzioni di libreria o istruzioni if-else o l’operatore
ternario)
*/

int main() {
    int a,b;

    cin >> a >> b;

    int ris;
    int maggiore = a > b;
    ris = (a-b) * maggiore;
    ris += (b-a) * !maggiore;

    cout << "valore assoluto di " << a << "-" << b << ": " << ris;

    return 0;
}