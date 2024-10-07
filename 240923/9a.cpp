#include <iostream>
using namespace std;

/*
Scrivere un programma che chiede all'utente di inserire un numero intero e
determina se il numero è pari o dispari
*/

int main() {

    int numero;
    cout << "inserire un numero: ";
    cin >> numero;

    bool is_pari = numero % 2;
    cout << is_pari;

    return 0;
}