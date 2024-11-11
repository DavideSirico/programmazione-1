#include <iostream>
#include <cassert>
using namespace std;
/*
Si scriva una funzione che riceva come parametro una stringa di caratteri str e
restituisca come valore di ritorno un numero intero. Dopo avere verificato che
la stringa sia composta da caratteri alfabetici (escluso il carattere nullo), la
funzione converte eventuali caratteri alfabetici maiuscoli in minuscoli; quindi
calcola e restituisce un punteggio per la stringa str dato dalla somma delle
differenze assolute tra ciascuna coppia di caratteri consecutivi. Ad esempio,
data la stringa str = “aa”, la funzione restituisce 0; data la stringa str = “abf”, la
funzione restituisce 5. Se la stringa non contiene solo caratteri alfabetici, la
funzione restituisce -1. Si scriva quindi un main che, finché l’utente lo
desidera, gli chieda di immettere da tastiera una stringa contenente al
massimo 31 caratteri, chiami la funzione di cui sopra e, in caso di dato valido,
ne stampi a video il valore di ritorno.
*/
const int max_char = 31;

int diff(char str[max_char]);
int main() {
    char test[max_char];
    cout << "Inserire una stringa (max 31 char): ";
    cin >> test;
    cout << diff(test);

    /*
    char test1[max_char] = "aa";

    char test2[max_char] = "abf";

    char test3[max_char] = "123";
    cout << "test1: " << endl;
    assert(diff(test1) == 0);

    cout << "test2: " << endl;
    assert(diff(test2) == 5);

    cout << "test3: " << endl;
    assert(diff(test3) == -1);
    */

    return 0;
}

int diff(char str[max_char]) {
    int c=0;
    int i = 0;
    if(!(str[i] >= 'A' && str[i] <='Z') && !(str[i] >= 'a' && str[i] <='z'))
            return -1;
    if(str[i] >= 'A' && str[i] <='Z')
        str[i] += 'a'-'A';
    for(i = 1; str[i] !='\0'; i++) {
        if(str[i] >= 'A' && str[i] <='Z') {
            str[i] += 'a'-'A';
        } 
        if(!(str[i] >= 'A' && str[i] <='Z') && !(str[i] >= 'a' && str[i] <='z'))
            return -1;
        int delta = str[i-1]-str[i];
        if(delta<0) {
            c-=delta;
        } else {
            c+=delta;
        }
    }
    return c;
}