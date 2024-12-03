#include <iostream>
#include <fstream>
using namespace std;

/* Sia dato in input un file contenente una sequenza di stringhe formate da
(massimo 10) ripetizioni dell’unico carattere * e separate da uno o più
spazi e ritorni a capo. Le stringhe rappresentano una sequenza di interi
positivi codificati in codice unario. Scrivere un programma che calcoli la
media dei valori contenuti nel file e la appenda a fine file in codice unario
(arrotondato per difetto). Usare solo le librerie <fstream> e <iostream> */

int my_strlen(char *str);
int main() {

    fstream in;
    in.open("../input.txt", ios::in);
    if(in.fail()) {
        cout << "Errore nell'apertura del file";
        return -1;
    }
    char buffer[21];
    double media = 0;
    int c = 0;
    while(in >> buffer) {
        media += my_strlen(buffer);
        c++;
    }   
    media = media / c;
    cout << media;
    in.close();
    fstream out;
    out.open("../input.txt", ios::app);
    if(out.fail()) {
        cout << "Errore nell'apertura del file";
        return -1;
    }
    out << endl;
    for(int i = 0; i <= media-1; i++) {
        out << "*";
    }
    out.close();
    return 0;
}

int my_strlen(char *str) {
    int i;
    for(i = 0; str[i]!='\0'; i++);
    return i;
}