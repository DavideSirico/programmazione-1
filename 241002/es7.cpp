#include <iostream>
using namespace std;

/*
scrivere un programmino che simuli un attacco 3 contro 3 a RISIKO
Ovvero: ogni giocatore lancia 3 dadi e vince chi dei due ha
ottenuto dalla somma dei dadi un valore piu' alto.
*/

int main() {
    srand(time(NULL));
    int somma1 = 0;
    int somma2 = 0;

    cout << "Giocatore 1: " << endl;

    for(int i = 0; i < 3; i++) {
        int lancio = rand()%6;
        cout << lancio << " ";
        somma1 += lancio;
    }
    cout << endl << "Giocatore 2: " << endl;

    for(int i = 0; i < 3; i++) {
        int lancio = rand()%6;
        cout << lancio << " ";
        somma2 += lancio;
    }
    cout << endl;

    if (somma1 > somma2) {
        cout << "Giocatore 1 vince";
    } else if (somma1 < somma2) {
        cout << "Giocatore 2 vince";
    } else {
        cout << "Pareggio";
    }
    return 0;
}