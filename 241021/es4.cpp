#include <iostream>
using namespace std;

/*
Modificare il codice della funzione potenza dell’esercizio 1 cosi che la
funzione diventi tail recursive. 
*/

int potenza(int n, int m, int c = 1);
int main() {
    cout << potenza(2,5);
    return 0;
}

int potenza(int n, int m, int c) {
    if(m == 0) {
        return c;
    }
    return potenza(n,m-1,c*n);
    
}