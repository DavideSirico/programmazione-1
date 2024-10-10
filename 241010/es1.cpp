#include <iostream>
using namespace std;
/*
Dato in input un carattere, scrivere un programma che
controlli con una funzione se il carattere fornito in input sia
una lettera dell’alfabeto minuscola. In caso affermativo, il
programma deve stampare a video il carattere in
maiuscolo, usando una funzione per la conversione.
*/


bool minuscola(const char c);
char to_upper(const char c);
int main() {
    cout << "Inserire una lettera: ";
    char c;
    cin >> c;
    if (minuscola(c)) {
        cout << to_upper(c);
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

char to_upper(const char c) {
    if(minuscola(c)) {
        return c^32;
    } else {
        return c;
    }
}