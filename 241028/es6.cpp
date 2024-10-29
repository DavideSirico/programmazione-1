#include <iostream>
#include <stdlib.h>
using namespace std;

/*
Si scriva una funzione in C++ che riceva come parametro un array a di
numeri reali, la sua dimensione n e due ulteriori numeri reali x e y. Dopo
avere verificato che sia x < y, la funzione assegnerà 0 a tutti gli elementi
dell’array a che non appartengano all’intervallo [x, y]. Inoltre la funzione
restituirà come valore di ritorno il numero di assegnamenti effettuati
(cioè il numero di elementi non appartenenti all’intervallo
[x, y]). Se la condizione x < y non è verificata, la funzione restituirà -1.
Si scriva quindi un programma per verificare il corretto funzionamento
della funzione
*/

int intervallo(double a[], const int n, const double x, const double y);
void stampa(double array[], const int size);
void inizializza(double array[], const int size);
int main() {
    srand(time(NULL));
    const int dim = 10;
    double array[dim];
    inizializza(array,dim);
    stampa(array,dim);
    cout << intervallo(array,dim,3,7) << endl;
    stampa(array,dim);

    return 0;
}

void inizializza(double array[], const int size) {
    for(int i = 0; i < size; i++) {
        array[i] = (double)(rand()%(10));
    }
}
void stampa(double array[], int size) {
    cout << "array[";
    for(int i = 0; i < size-1; i++) {
        cout <<  array[i] << ", ";
    }
    cout << array[size-1];
    cout << "]";
    cout << endl;
}

int intervallo(double a[], const int n, const double x, const double y) {
    if (x >= y) {
        return -1;
    }
    int c = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] >= x && a[i] <= y) {
            a[i] = 0;
            c++;
        }
    }
    return c;
}