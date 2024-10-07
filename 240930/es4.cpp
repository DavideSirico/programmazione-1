#include <iostream>
using namespace std;

/*
Scrivere un programma in C++ che chieda all’utente di immettere da tastiera
le coordinate (x, y) di un punto e le coordinate (a, b) e (c, d) dei vertici
rispettivamente in alto a sinistra e in basso a destra di un rettangolo e
stampi a video un messaggio per indicare all’utente se il punto si trova
all’interno del rettangolo.
*/

int main() {
    int x,y,a,b,c,d;
    cout << "(x, y): ";
    cin >> x >> y;
    cout << "(a, b): ";
    cin >> a >> b;
    cout << "(c, d): ";
    cin >> c >> d;

    if ((x>a && x<c) && (y>b && y<d)) {
        cout << "Interno";
    } else {
        cout << "Esterno";
    }
    return 0;
}