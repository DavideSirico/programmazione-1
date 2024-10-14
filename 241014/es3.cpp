#include <iostream>
using namespace std;

/*
Dati in input tre interi in tre variabili (secondi, minuti, ore), scrivere un
programma che con una procedura converta un eventuale eccesso di
secondi in minuti e un eventuale eccesso di minuti in ore. Usare a
scelta passaggio di parametri per riferimento o puntatore.
*/

void orario(int *secondi, int *minuti, int *ore);

int main() {
    int secondi, minuti, ore;
    cin >> secondi >> minuti >> ore;
    orario(&secondi, &minuti, &ore);
    cout << secondi << " " << minuti << " " << ore;
    
    return 0;
}

void orario(int *secondi, int *minuti, int *ore) {
    *minuti += (*secondi) / 60;
    *secondi = (*secondi) % 60;
    
    *ore += (*minuti) / 60;
    *minuti = (*minuti) % 60;

}