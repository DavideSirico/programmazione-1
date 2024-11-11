#include <iostream>
#include <fstream>
using namespace std;
/*
Scrivere un programma che, dati in input da linea di comando
i nomi di due file, A e B, copi il contenuto di A all’interno di B.
Implementare anche dei controlli che avvisino l’utente in caso
il numero di argomenti sia sbagliato (manca il file di input)
oppure nel caso in cui il file di input non esista.
*/
const int max_char = 31;

int diff(char str[max_char]);
int main(int argc, char **argv) {
    if(argc<3) {
        cout << "mancano i nomi dei file";
        return -1;
    }
    char *filename1 = argv[1];
    char *filename2 = argv[2];

    ifstream in;
    ofstream out;
    in.open(filename1, ios::in);
    out.open(filename2, ios::out);
    if(in.fail() || out.fail()) {
        cout << "impossibile aprire il file";
        return -2;
    }
    char b;
    while (in.get(b)) {
        out << b;
    }

    in.close();
    out.close();

    return 0;
}
