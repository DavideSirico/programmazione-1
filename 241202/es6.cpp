
#include <iostream>
#include <cstdlib>
using namespace std;
/* Scrivere un programma che, dato un vettore v di dimensione 5
contenente caratteri maiuscoli definiti a tempo di compilazione, chieda
in input un intero positivo j e stampi un nuovo vettore ottenuto dalla
rotazione a sinistra di j posizioni del contenuto del vettore v
Opzionale: la funzione di ruota array deve avere una complessità O(n)
(niente cicli annidati) */

void visualizza(char *array, int dim);

void inizializza(char *array, int dim);

void left_shift(char v[], int length, int offset);
int main() {
    srand(time(NULL));
    int j,n;
    cout << "j: ";
    cin >> j;
    cout << "n: ";
    cin >> n;
    char *v = new char[n];

    inizializza(v,n);
    visualizza(v,n);
    cout << endl;
    left_shift(v,n,j);
    visualizza(v,n);

    delete[] v;
    return 0;
}

void left_shift(char v[], int length, int offset) {
    char *temp = new char[offset];
    for(int i = 0; i < offset; i++) {
        temp[i] = v[i];
    }
    
    for(int i = 0; i < length - offset; i++) {
        v[i] = v[i+offset];
    }

    for(int i = 0; i < offset; i++) {
        v[length-offset+i] = temp[i];
    }
    delete[] temp;
}


void inizializza(char *array, int dim) {
    for(int i = 0; i < dim; i++) {
        array[i] = 'a' + rand()%25;
    }
}

void visualizza(char *array, int dim) {
    for(int i = 0; i < dim; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}