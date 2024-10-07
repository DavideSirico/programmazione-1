#include <iostream>
using namespace std;

/*Si scriva un programma in linguaggio C++ che chieda all’utente di immettere
da tastiera un numero intero e stampi a video il numero immediatamente
precedente ed il numero immediatamente successivo.
Attenzione: si utilizzino solo gli operatori di incremento e decremento.
*/

int main() {
    int a;

    cin >> a;

    a--;
    cout << "precedente: " << a++ << endl << "successivo: " << ++a;

    return 0;
}