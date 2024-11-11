#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

/*
Scrivere un programma che, dato in input da riga di comando il
nome di un file F, ritorni a video il conteggio di tutte le lettere
presenti all’interno del file. Il conteggio è case insensitive (quindi
non c’è differenza tra maiuscole e minuscole)
*/


int main(int argc, char *argv[]) {
    if(argc<2) {
        cout << "numero di parametri insufficiente";
        return 0;
    }
    char *filename = argv[1];
    ifstream in;
    in.open(filename, ios::in);

    if(in.fail()) {
        cout << "Errore nell'apertura del file";
        in.close();
        return 0;
    }

    int conta_lettere[26];
    for(int i = 0; i < 26; i++) {
        conta_lettere[i] = 0;
    }
    while(!in.eof()) {
        char lettera;
        in.get(lettera);
        if(lettera>='A' && lettera <='Z') {
            lettera = lettera-('a'-'A');
        }
        if(lettera>='a' && lettera <='z') {
            int pos_lettera = lettera-'a';
            // cout << lettera << " " << pos_lettera << endl; 
            conta_lettere[pos_lettera]++;
        }
        
    }
    for(int i = 0; i < 26; i++) {
        if(conta_lettere[i] != 0)
            cout << (char)(i+'a') << " " << conta_lettere[i] << endl;
    }
    return 0;
}
