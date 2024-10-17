#include <iostream>
using namespace std;

/*
Scrivere un programma che prenda in input un numero e
ne stampi a video la rappresentazione binaria tramite
procedura ricorsiva.
*/
void stampa_bin(int n);
int main() {
    int n = 10;
    cout << n << " in binario=";
    stampa_bin(n);
    return 0;
}

void stampa_bin(int n) {
    if(n==0) {
        return;
    } else {
        stampa_bin(n/2);
        cout << n%2;
    }
}