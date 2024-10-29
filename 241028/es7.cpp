#include <iostream>
#include <stdlib.h>
using namespace std;

/*
Scrivere una funzione C++ che dati come parametri un array di interi e la
sua dimensione n, trovi il massimo dell’array in modo ricorsivo. Si
scriva un programma che testi il corretto funzionamento della funzione.
*/

// int max(int array[], const int size, int index = 0, int v_max = 0);
int max(int array[], int size);
void stampa(int array[], const int size);
void inizializza(int array[], const int size);
int main() {
    srand(time(NULL));
    const int dim = 10;
    int array[dim];
    inizializza(array,dim);
    stampa(array,dim);
    cout << max(array,dim) << endl;
    stampa(array,dim);

    return 0;
}

void inizializza(int array[], const int size) {
    for(int i = 0; i < size; i++) {
        array[i] = (rand()%(10));
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

/*
int max(int array[], const int size, int index, int v_max) {
    if(index == size) {
        return v_max;
    }
    if(array[index]>v_max) {
        return max(array,size,index+1,array[index]);
    }
    return max(array,size,index+1,v_max);    
}*/
int max(int array[], int size) {
    if(size == 1) {
        return array[0];
    }
    int v_max = max(array, size-1);
    
    return array[size-1]>v_max ? array[size-1] : v_max;
}