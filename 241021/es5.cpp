#include <iostream>
#include <math.h>
using namespace std;

/*
Si scriva in C++ una funzione ricorsiva che, ricevuto come parametro un numero reale x, calcoli
il valore di sin(x) utilizzando lo sviluppo di Taylor fino al termine n-esimo.
Si scriva quindi un programma per verificare il corretto funzionamento della funzione.
Il programma chiederà all’utente di inserire i valori di x (un numero reale) e di n (un numero intero),
chiamerà la funzione e stamperà a video il suo valore di ritorno. Tali operazioni potranno essere
ripetute finché l’utente lo desidera.
Nota: anche il fattoriale può essere implementato mediante una funzione ricorsiva.
Per fare di più: quale è il valore di n oltre il quale la funzione inizia a restituire valori non validi?
Per quale ragione questo accade?
*/

double sin(double x, double n);
int main() {
    cout << sin(M_PI/2,15) <<  endl;
    cout << sin(M_PI/2); // math.h
    return 0;
}

// Funzione ricorsiva per calcolare il fattoriale
int fattoriale(int n) {
    if (n <= 1) return 1;
    return n * fattoriale(n - 1);
}

double sin(double x, double n) {
    if(n == 0) {
        return x;
    }
    double r = pow(-1,n)*((pow(x,(2*n)+1)/fattoriale((2*n)+1)));
    return r + sin(x,n-1);
}