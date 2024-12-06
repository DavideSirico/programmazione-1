#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;


// è possibile definire funzioni di supporto

char to_lower(char lettera) {
    if(lettera>='A' && lettera<='Z') {
        lettera = lettera + 'a' - 'A'; 
    }
    return lettera;
}

int main(int argc, char * argv []) {

    // inserire qui il codice
    
    if(argc != 2) {
        cout << "./esercizio1.out input.txt";
        return -1;
    }
    char *filename = argv[1];
    fstream in;
    in.open(filename, ios::in);
    if(in.fail()) {
        cout << "Errore nell'apertura del file";
        return -1;
    }
    char sequenza[255];

    cout << "Inserire una sequenza di char: ";
    cin.getline(sequenza, 255);

    char buffer;
    while(in.get(buffer)) {
        bool to_print = false;
        for(int i = 0; sequenza[i] != '\0'; i++) {
            if(to_lower(sequenza[i]) == to_lower(buffer)) {
                to_print = true;
            }
        }
        if(to_print) {
            cout << buffer;
        }
    }

    in.close();

    return 0;

}
