#include <iostream>
using namespace std;

/*
Scrivere un programma C++ che, dato in input un carattere
alfabetico, stampa a video se il carattere è una consonante
o una vocale.
*/

int main() {
    char c;
    cin >> c;

    if (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u') {
        cout << "vocale";
    } else {
        cout << "consonante";
    }

    return 0;
}