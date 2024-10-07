#include <iostream>
using namespace std;

/*
Scrivere un programma C++ che disegni sul terminale un triangolo le
cui righe devono essere composte da un numero dispari di asterischi.
L’altezza di questo triangolo viene data in input dall’utente.
A = 4
   *
  ***
 *****
*******
*/

void piramide(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i-1; j++) {
            cout << " ";
        }
        for(int j = 0; j < i*2+1; j++) {
            cout  << "*";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Altezza: ";
    cin >> n;
    piramide(n);
    return 0;
}