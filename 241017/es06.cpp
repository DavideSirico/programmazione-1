#include <iostream>
#include <cmath>
using namespace std;

/*
Scrivere un programma che prenda in input due caratteri e
stampi a video tutti i caratteri compresi tramite procedura
ricorsiva.
*/
void stampa_char(char start, char end);
int main() {
    char start = 'a';
    char end = 'c';
    stampa_char(start,end);
    return 0;
}

void stampa_char(char start, char end) {
    if (start == end) {
        cout << start;
        return;
    } else {
        cout << start << ",";
        stampa_char(start+1, end);
    }
}