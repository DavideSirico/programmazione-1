#include <iostream>
#include <fstream>
using namespace std;
/*
Scrivere un programma che, dato in input il nome di un file
F e una lettera L, stampi a video il contenuto di quel file,
sostituendo ogni occorrenza della lettera L con il simbolo
“?”
"Che magnifica giornata", a
=
"Che m?gnific? giorn?t?"
*/
const int max_char = 31;

int diff(char str[max_char]);
int main(int argc, char **argv) {
    if(argc<3) {
        cout << "mancano gli argomenti";
        return -1;
    }
    char *filename = argv[1];
    char lettera = argv[2][0];

    ifstream in;
    ofstream out;
    in.open(filename, ios::in);
    if(in.fail()) {
        cout << "impossibile aprire il file";
        return -2;
    }
    char b;
    while (in.get(b)) {
        if(b==lettera) {
            cout << "?";
        } else {
            cout << b;
        }
    }

    in.close();

    return 0;
}
