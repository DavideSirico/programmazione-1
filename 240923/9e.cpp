#include <iostream>
using namespace std;
/*Scrivere un programma che scambia il valore di due variabili intere utilizzando solo
l'operatore XOR e senza usare variabili temporanee.*/

int main() {
    int a,b;
    cout << "inserire a e b: ";
    cin >> a >> b;

    a = a^b;
    b = a^b;
    a = a^b;

    cout << a << " " << b;
    return 0;
}