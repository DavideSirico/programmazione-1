#include <iostream>
using namespace std;

/*Si scriva un programma in linguaggio C++ che chieda all’utente di immettere
da tastiera i coefficienti a, b e c (tre numeri reali) di una equazione di secondo
grado nella forma ax2 + bx + c = 0 e ne calcoli le soluzioni x1 e x2. Prima di
effettuare il calcolo, il programma verificherà che l’equazione non sia
degenere e che abbia soluzioni reali. In tal caso, il programma stamperà a
video le soluzioni calcolate, altrimenti stamperà a video opportuni messaggi
per l’utente.
Attenzione! Dovete gestire TUTTI i casi possibili*/

int main() {
    double a,b,c;
    double x1,x2;
    cout << "Inserire i coefficient a,b,c: ";
    cin >> a >> b >> c;
    double delta = (b*b) - (4*a*c);
    if (delta<0) {
        cout << "Non ci sono soluzioni reali";
    } else if (delta>0) {
        x1 = -b-delta;
        x2 = -b+delta;
        cout << "Ci sono 2 soluzioni: " << x1 << " - " << x2;
    } else {
        x1 = -b-delta; 
        x2 = -b+delta;
        cout << "Ci sono 2 soluzioni coincidenti: " << x1 << " - " << x2;
    }
    return 0;
}