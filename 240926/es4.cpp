#include <iostream>
using namespace std;

/*
Scrivere un programma C++ che, dati in input due numeri interi,
a e b, controlli se i due numeri sono uguali. Il programma deve
stampare a video il risultato del confronto tramite una variabile
booleana
(senza utilizzare funzioni di libreria o istruzioni if-else oppure “==”)
*/

int main() {
    int a, b;

    cin >> a >> b;

    bool uguali;
    uguali = a & b;
    cout << "uguali: " << uguali;

    return 0;
}