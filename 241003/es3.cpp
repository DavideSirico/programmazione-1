#include <iostream>
using namespace std;

/*
Scrivere un programma C++ che, dato in input un numero
intero (compreso tra 0 e 1000), ritorni a video se il numero
inserito è primo.
Nota: un numero viene definito primo quando è divisibile solo
per se stesso e per il numero 1.
*/

bool primo(int n) {
    for(int i = 2; i <= n/2; i++) {
        if(n%i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Inserire un numero intero: ";
    cin >> n;
    cout << primo(n);
    return 0;
}