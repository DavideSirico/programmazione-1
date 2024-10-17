#include <iostream>
using namespace std;

/*
Scrivere un programma che calcoli il fattoriale di un intero
positivo tramite funzione ricorsiva.
*/
int recursive_fact(int n);
int recursive_fact(int n, int i, int res);
int fattoriale(int n);
int main() {
    int n = 5;
    cout << "Fattoriale di " << n << " e' " << fattoriale(n);
    return 0;
}

int fattoriale(int n) {
    return recursive_fact(n);
}

int recursive_fact(int n, int i, int res) {
    if((i-1) == n) {
        return res;
    } else {
        res = res * i;
        return recursive_fact(n,i+1,res);
    }
}
int recursive_fact(int n) {
    if(n <= 1) {
        return 1;
    } else {
        return n*recursive_fact(n-1);
    }
}