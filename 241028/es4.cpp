#include <iostream>
#include <stdlib.h>
using namespace std;

/*
Scrivere un programma C++ che, sfruttando le funzioni scritte per
l’esercizio 01, dichiari e poi inizializzi (con valori random tra 0 e 9) un
array di 10 numeri interi e lo stampi a video. Il programma chiami una
terza funzione che inverta l’array. Tale array inverito venga poi stampato
dal programma.
*/

void inverso(int array[], const int size);
void stampa(int array[], const int size);
void inizializza(int array[], const int size);
int main() {
    srand(time(NULL));
    const int dim = 10;
    int array[dim];
    inizializza(array,dim);
    
    stampa(array,dim);
    inverso(array,dim);
    stampa(array,dim);

    return 0;
}

void inizializza(int array[], const int size) {
    for(int i = 0; i < size; i++) {
        array[i] = rand()%(10);
    }
}
void stampa(int array[], int size) {
    for(int i = 0; i < size; i++) {
        cout << "array[" << i << "]" << ": " << array[i] << endl;
    }
    cout << endl;
}
void inverso(int array[], const int size) {
    for(int i = 0; i < size/2; i++) {
        int temp = array[i];
        array[i] = array[(size-i)-1];
        array[(size-i)-1] = temp;
    }
}