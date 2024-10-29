#include <iostream>
#include <stdlib.h>
using namespace std;

/*
Scrivere un programma C++, che sfruttando le funzioni scritte negli esercizi
precedenti, dichiari e poi inizializzi (con valori random) un array di 10 numeri
interi. Il programma chiamerà poi una funzione che prende in input un nuovo
elemento x e un indice i, e aggiunge l'elemento x in posizione i nell’array,
traslando gli elementi successivi. Il programma controlli che l’indice i inserito
sia nel range opportuno, e, se non lo fosse, visualizzi un messaggio di errore e
richieda un nuovo inserimento. Infine, si stampi l’array modificato.
*/

void shift(int array[], const int size);
void stampa(int array[], const int size);
void inizializza(int array[], const int size);
int main() {
    srand(time(NULL));
    const int dim = 10;
    int array[dim];
    inizializza(array,dim);
    stampa(array,dim);
    shift(array,dim);
    stampa(array,dim);

    return 0;
}

void inizializza(int array[], const int size) {
    for(int i = 0; i < size; i++) {
        array[i] = rand()%(10);
    }
}
void stampa(int array[], int size) {
    cout << "array[";
    for(int i = 0; i < size-1; i++) {
        cout <<  array[i] << ", ";
    }
    cout << array[size-1];
    cout << "]";
    cout << endl;
}

void shift(int array[], const int size) {
    int element, index;
    cout << "Nuovo elemento: ";
    cin >> element;
    cout << "Posizione: ";
    cin >> index;
    while(index >= size || index < 0) {
        cout << "errore indice fuori dall'array";
        cout << "Posizione: ";
        cin >> index; 
    }
    
    for(int i = size-1; i > index; i--) {
        array[i] = array[i-1];
    }
    array[index] = element;
}