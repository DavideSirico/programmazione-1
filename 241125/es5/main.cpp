#include <iostream>
#include "coda.h"
#include "pila.h"

using namespace std;

/*
Scrivere un programma che, data una parola in input (massimo 100
caratteri), dica se è palindroma oppure no usando una pila e/o una coda.
Nota: non potete sfruttare la conoscenza della lunghezza della parola
(non potete nemmeno calcolarla)
*/

bool is_palindroma(char *parola);
int main() { 
    char parola[256];
    cin >> parola;
    if(is_palindroma(parola)) {
        cout << "La parola e' palindroma";
    } else {
        cout << "La parola non e' palindroma";
    }
    return 0;
}

bool is_palindroma(char *parola) {
    pila_init();
    coda_init();
    for(int i = 0; parola[i] != '\0'; i++) {
        pila_push(parola[i]);
        coda_enqueue(parola[i]);
    }
    int top;
    int bottom;
    while(pila_top(bottom)) {
        pila_pop();
        coda_first(top);
        coda_dequeue();
        if(bottom!=top) {
            return false;
        }
    }
    return true;
}
