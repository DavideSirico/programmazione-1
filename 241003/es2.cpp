#include <iostream>
using namespace std;

/*
Si scriva un programma in linguaggio C++ che chieda all’utente di
immettere da tastiera un numero intero positivo e calcoli e stampi a video
di quante cifre il numero è composto. Se il numero inserito non è positivo,
il programma stamperà un messaggio di errore e chiederà di inserire un
nuovo numero.
*/

int n_cifre(int n) {
    int cifre = 1;
    while(n>9) {
        n = n/10;
        cifre++;
    }
    return cifre;
} 

int main() {
    int n;
    do {
        cout << "Inserire un numero positivo: ";
        cin >> n;
    } while(n < 0);

    cout << "Cifre: " << n_cifre(n);
    return 0;
}