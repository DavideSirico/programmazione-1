#include <iostream>
#include <fstream>
#include "pila.h"
using namespace std;

/*
scrivere un programma che prenda in ingresso un file con un intero per
riga e lo copi su un altro file con le righe in ordine inverso
*/

void rev(fstream &out);
int main() {
    fstream in;
    in.open("input.txt", ios::in);
    if(in.fail()) {
        cout << "Errore nell'apertura del file";
        exit(0);
    }
    pila_init();
    int n;
    while(in >> n) {
        pila_push(n);
    }
    pila_print();

    fstream out;
    out.open("output.txt", ios::out);
    if(out.fail()) {
        cout << "Errore nella scrittura del file";
        exit(0);
    }
    
    rev(out);
    pila_print();
    pila_deinit();

    out.close();
    in.close();
    return 0;
}

void rev(fstream &out) {
    int n;
    if(pila_top(n)) {
        pila_pop();
        rev(out);
        out << n << endl;
    }
}