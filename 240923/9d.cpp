#include <iostream>
using namespace std;

/*Scrivere un programma che determina se un numero è un multiplo di un altro
usando solo operatori aritmetici e logici (senza cicli o condizioni).*/

int main() {

    int numero;
    cout << "inserire un numero: ";
    cin >> numero;

    int multiplo;
    cout << "multiplo: ";
    cin >> multiplo;

    cout << (numero % multiplo == 0) * 1;


    
    
    
    return 0;
}