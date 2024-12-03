#include <iostream>
#include <fstream>

using namespace std;

char to_uppercase(char letter);
int main(int argc, char *argv[]) {
    if(argc != 3) {
        cout << "es8.cpp <filename1> <filename2>";
        return 0;
    }
    char *filename1 = argv[1];
    char *filename2 = argv[2];

    ifstream in;
    ofstream out;
    in.open(filename1, ios::in);
    out.open(filename2, ios::out);
    if(in.fail() || out.fail()) {
        cout << "Errore nell'apertura del file";
        return -1;
    }
    bool next_upper = true;
    in >> noskipws;
    char buffer;
    while(in>>buffer) {
        if(buffer == '!' || buffer == '.' || buffer == '?') {
            next_upper = true;
         } else if(next_upper && buffer != '\n') {
            buffer = to_uppercase(buffer);
            next_upper = false;
        }
        out << buffer;

    }
    in.close();
    out.close();

    return 0;
}

char to_uppercase(char letter) {
    if(letter>='a' && letter<='z') {
        letter = letter - ('a'-'A');
    }
    return letter;
} 