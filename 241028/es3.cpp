#include <iostream>
#include <stdlib.h>
using namespace std;

/*
Scrivere un programma C++ che, sfruttando le funzioni scritte per
l’esercizio 01, dichiari e poi inizializzi (con valori random tra 0 e 9)
un array di 10 numeri interi e lo stampi a video. Il programma
chiami poi una funzione che calcoli la media dei valori degli
elementi dell’array, il valore massimo e il valore minimo.
*/

void med_max_min(int array[], const int size, double res[]);
void stampa(int array[], const int size);
void inizializza(int array[], const int size);
int main() {
    srand(time(NULL));
    const int dim = 10;
    int array[dim];
    inizializza(array,dim);
    
    stampa(array,dim);
    double res[3];
    med_max_min(array,dim,res);
    cout << "max: " << res[1] << endl;
    cout << "min: " << res[2] << endl;
    cout << "media: " << res[0] << endl;

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
void med_max_min(int array[], const int size, double res[]) {
    int min = array[0];
    int max = array[0];
    int som = array[0];

    for(int i = 1; i < size; i++) {
        som+=array[i];
        if(min > array[i]) {
            min = array[i];
        }
        if(max < array[i]) {
            max = array[i];
        }
    }
    res[0] = som/size;
    res[1] = max;
    res[2] = min;
}