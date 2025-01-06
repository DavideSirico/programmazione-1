// Inserire qui il codice
#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char * argv[]) {
    if(argc != 3) {
        cout << "./esercizio1 <input> <output>";
        exit(1);
    }

    fstream in;
    fstream out;
    in.open(argv[1], ios::in);
    out.open(argv[2], ios::out);

    if(in.fail() || out.fail()) {
        cout << "Errore nell'apertura del file";
        exit(1);
    }
    char buffer[256];
    char longest_line[256];
    int max = 0;
    while(in.getline(buffer,256)) {
        int i;
        for(i = 0; buffer[i] != '\0'; i++);
        if(i > max) {
            max = i;
            for(int j = 0; buffer[j] != '\0'; j++) {
                longest_line[j] = buffer[j];
            }
        }
        cout << i << endl;
    }
    cout << longest_line << max;
    in.close();
    out.close();
    return 0;
}