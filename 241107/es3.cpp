#include <iostream>
#include <fstream>
using namespace std;
/*
Scrivere un programma che, dato in input da linea di
comando il nome di un file, ritorni a video il contenuto del
suddetto file. Implementare anche dei controlli che avvisino
l’utente in caso il numero di argomenti sia sbagliato (manca il
file di input) oppure nel caso in cui il file di input non esista.
*/
const int max_char = 31;

int diff(char str[max_char]);
int main(int argc, char **argv) {
    if(argc<2) {
        cout << "manca il nome del file";
        return -1;
    }
    char *filename = argv[1];
    ifstream in;
    in.open(filename, ios::in);
    if(in.fail()) {
        cout << "impossibile aprire il file";
        return -2;
    }
    while(!in.eof()) {
        char b;
        in.get(b);
        cout << b;
    }

    in.close();

    return 0;
}
