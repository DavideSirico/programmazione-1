#include <iostream>
#include <cmath>
using namespace std;

/*
scrivere una procedura che prenda in ingresso un vettore v e la sua
dimensione d, un nuovo elemento x e un indice i, e aggiunga
l'elemento x in posizione i nel vettore, e incrementi d di uno. 
Il vettore passato deve avere almeno d+1 elementi.
*/
void shift(int v[], int length, int elemento, int indice, int counter);
int main() {
    const int length = 6;
    int a[length] = {4,1,3,6,8,0};
    shift(a,length,7,2,-1);
    for( int i = 0; i < length; i++) {
        cout << a[i] << " "; 
    }

    return 0;
}

void shift(int v[], int length, int elemento, int indice, int counter) {
    if (counter == -1) {
        counter = length - 1;
    }
    if (counter <= indice) {
        v[indice] = elemento;
        return;
    }
    v[counter] = v[counter - 1];
    shift(v, length, elemento, indice, counter - 1);
}