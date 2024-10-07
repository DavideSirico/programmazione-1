#include <iostream>
using namespace std;

/*
Scrivere un programma che generi un numero compreso tra 1 e 10
utilizzando la funzione presentata sotto. Chiedere poi all’utente
ripetutamente di inserire un numero e terminare il programma
quando si sarà indovinato.
#include <cstdlib>
srand(time(NULL));
int random_number = rand() % 10 + 1
*/
int main() {
    srand(time(NULL));
    int numero_da_indovinare = rand() % 10 + 1; 
    int n{};
    cout << "Inserire un numero: ";
    do {
        cin >> n;
    } while(n != numero_da_indovinare);
    cout << "Hai vinto!";
    return 0;
}