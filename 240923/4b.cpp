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
    float iva, prezzo;

    int modalita;
    
    cout << "modalita (0: netto -> lordo, 1: lordo -> netto): ";
    cin >> modalita;

    cout << "prezzo: ";
    cin >> prezzo;

    cout << "iva: ";
    cin >> iva;

    float sconto = prezzo * (iva / 100.0F);
    float prezzo_finale = modalita*(prezzo - sconto) + !(modalita)*(prezzo + sconto);

    cout << prezzo_finale;

    return 0;
}