#include <iostream>
using namespace std;

/*
Scrivere un programma che prenda in input un testo e generi lo
stesso testo dove ogni separatore (\t,\n, sequenza di piu' blank)
sia convertito in un unico blank.
*/

int main() {
    char stringa[200];
    char stringa2[200];

    cin.getline(stringa,200);
    int j = 0;
    bool last_space = false;
    for(int i = 0; stringa[i] != '\0'; i++) {
        if(last_space && (stringa[i] == ' ' || stringa[i] == '\t' || stringa[i] == '\n')) {
            i++;
        }
        last_space = (stringa[i] == ' ' || stringa[i] == '\t' || stringa[i] == '\n');
        stringa2[j] = stringa[i];
        j++;
    }

    cout << stringa2 << endl;
    return 0;
}