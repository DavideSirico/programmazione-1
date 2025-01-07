// Allowed include 
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>

// Add your code hereafter
using namespace std;
int Contaparole(char * testo[]) {
    int n = 0;
    for (int i = 0; i < 5000 && testo[i] != nullptr; i++,n++) {}
    return n;
}

void Generaraparole(char * testo[], int n, char word[]) {
  int i = 0;
  for (i = 0; i < 6; i++) {
    word[i] = *(testo[max(0,(rand() % n)-1)]);
  }
  word[i] = '\0';
}


int main(int argc, char *argv[]) {
    srand(time(NULL));
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }
    char text[5000];
    char *pwords[5000];
    for(int i = 0; i < 5000; i++) {
        pwords[i] = NULL;
    }
    fstream in;
    in.open(argv[1], ios::in);

    if(in.fail()) {
        exit(1);
    }

    char c;
    int i = 0;
    char previous_c = ' ';
    int n_word = 0;
    while(in.get(c) && i < 5000 && !in.eof()) {
        text[i] = c;
        if (previous_c == ' ' && ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
            pwords[n_word++] = &text[i];
        }
        previous_c = c;
        i++;
    }
    int n = Contaparole(pwords);
    char generated_word[7] = {0};
    Generaraparole(pwords, n, generated_word);
    cout << "Text: " << text << endl;
    cout << "Number of words: " << n << endl;
    cout << "Initials: ";
    for (int k = 0; k < n_word; k++) {
        cout << *(pwords[k]);
    }
    cout << endl;
    cout << "Generated word: " << generated_word << endl;
    in.close();
    return 0;
}