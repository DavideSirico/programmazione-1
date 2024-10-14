#include <iostream>
using namespace std;

/*
Dati in input due reali (double) in due variabili, scrivere un
programma che usi una procedura per scambiare i valori
delle due variabili usando il passaggio di parametri per
puntatore.
*/

void swap(double *a, double *b);

int main() {
    double a = 10;
    double b = 20;
    swap(&a,&b);
    return 0;
}
void swap(double *a, double *b) {
    double temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
