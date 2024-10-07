#include <iostream>
using namespace std;
int main() {
 int numeratore = 10;
 int denominatore = 0;
 int risultato = numeratore / denominatore; // ERRORE DIVISIONE PER ZERO
 cout << "Il risultato è: " << risultato << endl;
 return 0;
}