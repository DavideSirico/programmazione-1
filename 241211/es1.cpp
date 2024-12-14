#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void GeneraParole(char *pwords[], int number_words, char initials[7]);
int ContaParole(char *pwords[]);
int main(int argc, char *argv[]) {
    srand(time(NULL));
    if(argc != 2) {
        cout << "";
        exit(1);
    }

    fstream in;
    in.open(argv[1], ios::in);
    char text[5000];
    char *pwords[5000]{NULL};
    if(in.fail()) {
        cout << "Cannot open the input file \"" << argv[1] << "\"" ;
        exit(1);
    }

    int index = 0;
    int c = 0;
    char buffer;
    bool is_first_letter = true;
    while(in.get(buffer) && index<5000) {
        text[index] = buffer;
        if(is_first_letter) {
            pwords[c] = &text[index];
            c++; 
            is_first_letter = false;
        }
        if(text[index] == ' ' || text[index] == '\n') {
            is_first_letter = true;
        }
        index++;
    }
    text[index] = '\0';;
    
    cout << "Text: ";
    for(int i = 0; i < index; i++) {
        cout << text[i];
    }

    int number_words = ContaParole(pwords);
    char generated_word[7];
    GeneraParole(pwords, number_words, generated_word);
    cout << endl;
    cout << "Number of words: " << number_words << endl;
    cout << "Initials: ";
    for(int i = 0 ; i < c; i++) {
        cout << pwords[i][0];
    }
    cout << endl;
    cout << "Generated word: " << generated_word << endl;
    in.close();
    return 0;
}

void GeneraParole(char *pwords[], int number_words, char initials[7]) {
    for(int i = 0; i < 6; i++) {
        int index = rand()%number_words;
        initials[i] = *pwords[index];

    }
    initials[6] = '\0';
}

int ContaParole(char *pwords[]) {
    int i;
    for(i = 0; pwords[i]!=NULL; i++);
    return i;
}