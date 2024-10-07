#include <iostream>
using namespace std;
/*
Scrivere un programma che utilizza un doppio ciclo
annidato per stampare una matrice identità di dimensione
n x n. L'utente inserisce il valore di n.
*/

int main() {
    cout << "Inserire n: ";
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i==j)
                cout << "1";
            else 
                cout << "0";
            
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}
