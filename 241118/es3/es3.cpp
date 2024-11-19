#include <iostream>
#include <fstream>
#include "email.h"
using namespace std;


int main() {
    char filename_input[255];
    cout << "Nome file input: ";
    cin >> filename_input;
    ifstream in;
    in.open(filename_input, ios::in);
    if(in.fail()) {
        cout << "Errore apertura file";
        return 0;
    }
    char parola[255];
    while(!in.eof()) {
        in >> parola;
        if(is_email(parola)) {
            cout << parola << endl;
        }
    }
    

    in.close();
   
    return 0;
}
