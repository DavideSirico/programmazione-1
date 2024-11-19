#include <iostream>
#include <fstream>

#include "cesare.h"
using namespace std;


int main() {
    char filename_input[255];
    char filename_output[255];
    int chiave;
    char scelta;
    cout << "Nome file input: ";
    cin >> filename_input;
    ifstream in;
    in.open(filename_input, ios::in);
    if(in.fail()) {
        cout << "Errore apertura file";
        return 0;
    }
    cout << "Nome file output: ";
    cin >> filename_output;
    ofstream out;
    out.open(filename_output, ios::out);
    if(out.fail()) {
        cout << "Errore apertura file";
        return 0;
    }
    cout << "Chiave: ";
    cin >> chiave;

    cout << "Cifra o Decifra (1/2): ";
    cin >> scelta;
    if(scelta != '1' && scelta != '2') {
        cout << "Scelta non valida";
        return 0;
    }
    char parola[255];
    in.getline(parola, 255);
    if(scelta == '1') {
        crypt(parola, chiave);
    } else if(scelta == '2') {
        decrypt(parola, chiave);
    }
    int lenght;
    for(lenght=0; parola[lenght] != '\0'; lenght++);
    out.write(parola,lenght);
    in.close();
    out.close();

    return 0;
}

