#include <iostream>
#include <cmath>
using namespace std;

/*
scrivere una procedura che prenda un vettore v e la sua dimensione
d, un elemento x, ed elimina tutte le occorrenze di x (diminuemdo la
dimensione d del vettore)
*/

void rimuovi_occorrenze(int v[], int length, int elemento);
void left_shift(int v[], int length, int start);
int main() {
    const int length = 7;
    int v[length] = {1,2,3,4,5,6,0};
    rimuovi_occorrenze(v,length,3);

    for( int i = 0; i < length; i++) {
        cout << v[i] << " "; 
    }

    return 0;
}

void left_shift(int v[], int length, int start) {
    for(int i = start; i < length-1; i++) {
        v[i] = v[i+1];
    }
}

void rimuovi_occorrenze(int v[], int length, int elemento) {
    for(int i = 0; i < length; i++) {
        if(v[i] == elemento) {
            left_shift(v,length,i);
        }
    }
}