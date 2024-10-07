#include <iostream>
using namespace std;
/*
Scrivere un programma che genera e stampa il Triangolo di Tartaglia fino a
n righe, dove n è fornito dall'utente. È possibile utilizzare solo variabili e
cicli, anche annidati.
*/
/*
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
*/

int main() {
    cout << "Inserire n: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int c = 1;
        for(int j = 0; j < (n-i); j++) {
            cout << " ";
        }
        for (int j = 0; j <= i; j++) {
            cout << c << " ";
            c = c * (i - j) / (j + 1);
        }
        cout << endl;
    }

    return 0;
}
