#include <iostream>
#include <stdlib.h>
using namespace std;

/*
Scrivere una funzione C++ che inizializzi (con valori random, il cui
massimo sia inserito dall’utente) un array di numeri interi. Scrivere poi
una funzione C++ che stampi a video tutti gli elementi di un array di
numeri interi. Scrivere una terza funzione C++ che permetta di contare
quanti numeri interi uguali sono allo stesso indice in due array di
interi. Si scriva un programma che testi le funzioni suddette.
*/
int ugualianze(int array1[], int array2[], const int size);
void stampa(int array[], int size);
void inizializza(int array[], const int size, int max);
int main() {
    srand(time(NULL));
    int max;
    cout << "Random massimo: ";
    cin >> max;
    const int dim = 10;
    int array1[dim];
    int array2[dim];
    inizializza(array1,dim,max);
    inizializza(array2,dim,max);
    
    stampa(array1,dim);
    stampa(array2,dim);

    cout << ugualianze(array1,array2,dim);
    return 0;
}

void inizializza(int array[], const int size, int max) {
    for(int i = 0; i < size; i++) {
        array[i] = rand()%(max+1);
    }
}
void stampa(int array[], int size) {
    for(int i = 0; i < size; i++) {
        cout << "array[" << i << "]" << ": " << array[i] << endl;
    }
    cout << endl;
}

int ugualianze(int array1[], int array2[], const int size) {
    int counter{0};
    for(int i = 0; i < size; i++) {
        if(array1[i] == array2[i]) {
            counter++;
        }
    }
    return counter;
}