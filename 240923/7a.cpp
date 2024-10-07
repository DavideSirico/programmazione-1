#include <iostream>
using namespace std;
/*
Date in input due variabili (scegliete voi il loro tipo), a e b,
scrivere un programma che scambi il valore di a al valore
di b e viceversa.
*/

int main() {

    int a,b;
    cout << "inserire a e b: ";
    cin >> a >> b;

    int c = a;
    a = b;
    b = c;

    cout << a << " " << b;

    return 0;
}