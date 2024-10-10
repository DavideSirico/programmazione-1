#include <iostream>
using namespace std;
/*
Dato in input un carattere, scrivere un programma che
controlli con una funzione se il carattere fornito in input sia
una lettera dell’alfabeto minuscola. In caso affermativo, il
programma deve stampare a video il carattere in
maiuscolo, usando una funzione per la conversione.
La funzione di conversione non deve ritornare alcun
valore.
*/


bool minuscola(const char c);
void to_upper(char *c);
int main() {
    cout << "Inserire una lettera: ";
    char c;
    cin >> c;
    if (minuscola(c)) {
        to_upper(&c);
        cout << c;
    }
    return 0;
}

bool minuscola(const char c) {
    if (c>='a' && c<='z') {
        return true;
    } else {
        return false;
    }
} 

void to_upper(char *c) {
    if(minuscola(*c)) {
        (*c) = (*c)^32;
    }
}