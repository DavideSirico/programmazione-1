#include <iostream>
using namespace std;

/*
Si scriva in C++ una funzione ricorsiva (NON tail recursive!) che, dati due numeri
interi m ed n ricevuti come parametri passati per valore, verifichi che n sia
positivo o nullo, calcoli e restituisca come valore di ritorno la potenza mn (un
numero intero).
Si scriva quindi un programma C++ per verificare il corretto funzionamento della
funzione.
Il programma chiederà all’utente di inserire da tastiera due numeri interi, se n è
negativo chiederà all’utente di inserire un numero valido. Il programma poi
chiamerà la funzione e stamperà a video il suo valore di ritorno.
Le operazioni si ripeteranno finché l’utente lo desidera.
*/

int potenza(int n, int m);
int main() {
    cout << potenza(2,5) << endl;
    return 0;
}
int potenza(int n, int m) {
    if(m<=0) {
        return 1;
    }
    return n*potenza(n,m-1);
    
}
