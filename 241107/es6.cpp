#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
/*
Scrivere un programma che, dati in input due file A e B da
riga di comando, generi un terzo file C che contenga tutte le
parole presenti in entrambi i file A e B.
E’ consentito l’uso delle funzioni strcmp(), strcpy() della
libreria <cstring>. Assumete inoltre che i file contengano al
massimo 1000 parole e che la lunghezza massima delle singole
parole sia 100. E’ consentito aprire al massimo un unico
stream per file.
*/
const int max_char = 100;
const int max_word = 1000;

int diff(char str[max_char]);
int main(int argc, char **argv) {
    if(argc<3) {
        cout << "mancano gli argomenti";
        return -1;
    }
    char *filename1 = argv[1];
    char *filename2 = argv[2];

    ifstream in;
    ofstream out;
    in.open(filename1, ios::in);
    if(in.fail()) {
        cout << "impossibile aprire il file";
        return -2;
    }
    char parole1[max_word][max_char];
    int index1 = 0;
    while (!in.eof()) {
        in >> parole1[index1];
        index1++;
    }
    in.close();
    
    char parole2[max_word][max_char];
    in.open(filename2, ios::in);
    if(in.fail()) {
        cout << "impossibile aprire il file";
        return -2;
    }
    int index2 = 0;
    while (!in.eof()) {
        in >> parole2[index2];
        index2++;
    }
    in.close();

    /* for(int i = 0; i < index1; i++) {
        cout << '-' << parole1[i] << '-' << endl;
    }
    for(int i = 0; i < index2; i++) {
        cout << '-' << parole2[i] << '-' << endl;
    } */

    out.open("output.txt", ios::out);
    for(int i = 0; i < index1; i++) {
        for(int j = 0; j < index2; j++) {
            // cout <<  parole1[i] << " " << parole2[j] << "=" << strcmp(parole1[i],parole2[j]) << endl;
            if(strcmp(parole1[i],parole2[j]) == 0){
                out << parole1[i] << endl;
                cout << parole1[i] << endl;
            }
        }
    }
    out.close();
    /*
    */



    return 0;
}
