#include <iostream>
#include <stdlib.h>
using namespace std;

/*
Scrivere una funzione C++ che inizializzi un array di 10 numeri interi
i cui elementi abbiano valori randomici compresi tra 0 e 9 inclusi.
Scrivere un’altra funzione C++ che stampi a video tutti gli elementi
di un array di numeri interi. Scrivere un programma C++ che testi il
buon funzionamento delle funzioni suddette.
*/

void inizializza(int array[], int size);
void stampa(int array[], int size);
int main() {
    srand(time(NULL));
    int array[10];
    inizializza(array, 10);
    stampa(array, 10);
    return 0;
}

void inizializza(int array[], int size) {
    for(int i = 0; i < size; i++) {
        array[i] = rand()%10;
    }
}
void stampa(int array[], int size) {
    for(int i = 0; i < size; i++) {
        cout << "array[" << i << "]" << ": " << array[i] << endl;
    }
}