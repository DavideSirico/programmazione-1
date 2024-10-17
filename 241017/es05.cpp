#include <iostream>
#include <cmath>
using namespace std;

/*
Scrivere una funzione ricorsiva che, dato in input un
numero intero, ritorni la somma delle cifre che
compongono il numero intero.
*/
int somma_cifre(int n);
int main() {
    int n = 12;
    cout << "La somma delle cifre di " << n << " e' " << somma_cifre(n);
    return 0;
}

int somma_cifre(int n) {
    if (n == 0) {
        return 0;
    }
    int cifra = n%10;
    return somma_cifre(n/10)+cifra;
}