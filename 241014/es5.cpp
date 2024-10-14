#include <iostream>
#include <climits>
using namespace std;

/*
Dati in input tre interi positivi in tre variabili (n1, n2, n3),
scrivere un programma che con una procedura “ri-ordini” i
numeri in ordine crescente usando il passaggio di
parametri per riferimento.
*/
void swap(int &a, int &b);
void ordinamento(int &n1, int &n2, int &n3);

int main() {
    int n1,n2,n3;
    cin >> n1 >> n2 >> n3;
    ordinamento(n1,n2,n3);
    cout << n1 << n2 << n3;
    return 0;
}

void ordinamento(int &n1, int &n2, int &n3) {
    if(n1 > n2) {
        swap(n1,n2);
    }
    if(n2 > n3) {
        swap(n2,n3);
    }
    if(n1 > n2) {
        swap(n1,n2);
    }
}
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}