#include <iostream>
#include <cstdlib>
using namespace std;
/*
Scrivere un programma che lanci 10 dadi a 6 facce utilizzando la funzione
presentata sotto. Chiedere poi all’utente di indovinare quanti dadi sono
risultati essere 1.
Variante: chiamare “n” il numero dei dadi (1<=n<=10) e considerare un’altra variabile “m” (0<=m<n) entrambi da leggere
in input come prima azione. Effettuare poi un lancio di “n” dadi mostrandone “m” a video e chiedendo poi di indovinare
quanti in totale sono pari a “1”. Valutare empiricamente se si ritiene che la probabilità di successo vari al variare di “m”.
#include <cstdlib>
srand(time(NULL));
int random_number = rand() % 6 + 1
*/

int main() {
    srand(time(NULL));
    int dadi_uguali_1 = 0;
    for(int i = 0; i < 10; i++) {
        if((rand() % 6 + 1) == 1) {
            dadi_uguali_1++;
        }
    }
    int ris;
    do {
        cout << "Dadi uguali a 1? ";
        cin >> ris;
    } while(ris!=dadi_uguali_1);
    cout << "Risposta esatta!";
    return 0;
}


int n_cifre(int n) {
    int cifre = 1;
    while(n>9) {
        n = n/10;
        cifre++;
    }
    return cifre;
} 

int pow(int base, int esponente) {
    int res = 1;
    for(int i = 0; i < esponente; i++) {
        res = res*base;
    }
    return res;
}

void ribalta(int n) {
    int ribaltato = 0;
    int cifre = n_cifre(n)-1;
    while(n>0) {
        ribaltato += (n%10)*pow(10,cifre);
        n = n/10;
        cifre--;
    }
    cout << ribaltato;
}