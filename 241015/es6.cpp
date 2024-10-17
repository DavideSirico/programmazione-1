#include <iostream>
#include <fstream>
using namespace std;
/*
scrivere un programma che prenda due file
- uno di testo
- l'altro con una mappa iniettiva tra caratteri
  e riscriva su un nuovo file il testo criptato secondo la mappa di caratteri. 

*/

int main() {
    fstream in;
    fstream out;
    in.open("../input.txt", ios::in);
    out.open("../output.txt", ios::out);
    char string[200];
    in >> string;
    out << string;
    in.close();
    out.close();
    return 0;
}