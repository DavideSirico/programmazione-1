#include <iostream>
using namespace std;

/*
Scrivere una funzione tail recursive C++ che riceva come parametri due
numeri interi e calcoli il Massimo Comune Divisore (MCD) usando
l’algoritmo di Euclide.
Algoritmo di Euclide
Siano a e b due numeri interi, tali che 0 < b < a:
1) Se b = 0, allora MCD (a,b) = a;
2) Se b ≠ 0, calcolare la divisione di a e b, chiamando q il quoziente e r il resto della divisione;
3) Porre a = b e b =r ;
4) Ripartire dal punto 1
Convertire poi la soluzione ricorsiva in una soluzione iterativa.
*/

double MCD(int a, int b);
int main() {
    int a,b;
    a = 10;
    b = 5;
    cout << MCD(a,b) << endl;

    while(b != 0) {
        int r = a%b;
        a = b;
        b = r;
    }
    cout << a << endl;

    return 0;
}
double MCD(int a, int b) {
    if(b == 0) {
        return a;
    }
    int r = a%b;
    a = b;
    b = r;
    return MCD(a,b);
}
