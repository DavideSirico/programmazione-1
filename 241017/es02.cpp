#include <iostream>
using namespace std;

/*
Scrivere un programma che calcoli la divisione di un intero
tramite funzione ricorsiva.
*/
int divisione (int dividendo, int divisore);
int main() {
    int a = 10;
    int b = 5;
    cout << a <<"/" << b << "=" << divisione(a,b);
    return 0;
}

int divisione(int a, int b) {
    if(a < b) {
        return 0;
    } else {
        return 1+divisione(a-b,b);
    }
}