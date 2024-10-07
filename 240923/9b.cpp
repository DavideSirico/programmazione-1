#include <iostream>
using namespace std;

/*Scrivere un programma che prende un numero intero a tre cifre e calcola la somma
delle sue cifre senza usare cicli*/

int main() {

    int numero;
    cout << "inserire un numero: ";
    cin >> numero;
    
    int somma = ((numero/10) % 10) + (numero / 100) + (numero % 10);
    cout << somma;

    
    return 0;
}