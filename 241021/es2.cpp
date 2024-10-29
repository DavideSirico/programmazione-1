#include <iostream>
using namespace std;

/*
Si scriva in C++ una nuova funzione ricorsiva (NON tail recursive!) che estenda il
comportamento della funzione dell’esercizio precedente cosi da permettere di ricevere
un esponente negativo. In tal caso, la funzione restituirà il valore M(-N) = 1 / MN.
Si scriva quindi un programma C++ per verificare il corretto funzionamento della
funzione.
Il programma chiederà all’utente di inserire da tastiera due numeri interi, chiamerà la
funzione e stamperà a video il suo valore di ritorno. Le operazioni si ripeteranno finché
l’utente lo desidera.
*/

double potenza(double n, double m);
int main() {
    cout << potenza(2,-5) << endl;
    return 0;
}
double potenza(double n, double m) {
    if(m == 0) {
        return 1;
    }
    if(m < 0) {
        return 1/(potenza(n,-m));
    }
    return n*potenza(n,m-1);
    
}
