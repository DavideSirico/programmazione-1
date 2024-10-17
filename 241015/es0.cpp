#include <iostream>
using namespace std;

/*
Scrivere un programma che prenda in input un testo e riporti in
output il numero di vocali e consonanti nel testo.
*/

bool is_vocale(char c) {
    if(c == 'a' || c == 'e' || c == 'u' || c == 'i' || c == 'o') {
        return true;
    } else {
        return false;
    }
}

int main() {
    int vocali = 0;
    int consonanti = 0;
    char stringa[200];
    cin >> stringa;
    for(int i = 0; stringa[i] != '\0' ; i++) {
        if(is_vocale(stringa[i])) {
            vocali++;
        } else {
            consonanti++;
        }
    }
    cout << "Vocali: " << vocali << endl << "Consonanti: " << consonanti;
    return 0;
}