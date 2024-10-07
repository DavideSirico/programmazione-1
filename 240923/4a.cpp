#include <iostream>
using namespace std;

/*
4 - IVA
Dati in input due numeri reali “prezzo” e “iva”,
- il prezzo lordo considerando gli input come prezzo
netto e percentuale d’iva
PrezzoLordo = PrezzoNetto + PrezzoNetto*(PercentualeIVA/100)
*/

int main() {
    float prezzo_netto, iva;

    cout << "prezzo_netto: ";
    cin >> prezzo_netto;

    cout << "iva: ";
    cin >> iva;

    float lordo;

    float lordo = prezzo_netto + prezzo_netto * (iva / 100);

    cout  << lordo;

    return 0;
}