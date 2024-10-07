#include <iostream>
using namespace std;

/*
Si scriva un programma in linguaggio C++ che chieda all’utente di immettere
da tastiera le dimensioni di una tabella espresse come numero di righe e
numero di colonne (due numeri interi) e stampi a video 0 se la tabella ha una
sola riga oppure una sola colonna oppure un solo elemento.
Attenzione: si usino solo gli operatori di confronto
*/

int main() {
    int righe, colonne;
    cout << "righe colonne: ";
    cin >> righe >> colonne;

    cout <<  !((righe == 1) || (colonne == 1));

    return 0;
}