#include <iostream>
#include "coda.h"
#include "pila.h"

using namespace std;

/*
Scrivere un programma che inverta gli elementi di una pila usando una
coda.
*/

int main() { 
    pila_init();
    pila_push(1);
    pila_push(2);
    pila_push(3);
    pila_push(4);
    pila_push(5);
    pila_push(6);
    pila_push(7);
    pila_push(8);
    pila_push(9);

    coda_init();
    int t;
    pila_print();
    while(pila_top(t)) {
        pila_pop();
        coda_enqueue(t);
    }
    while(coda_first(t)) {
        coda_dequeue();
        pila_push(t);
    }
    pila_print();
    return 0;
}