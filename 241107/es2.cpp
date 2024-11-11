#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
/*
Scrivere un programma che, dati a linea di comando tre valori,
due numeri e un operatore, ritorni a video il risultato
dell’operazione matematica definita dall’operatore.
./calcolatrice 1 3 +
Il risultato è 4
*/
const int max_char = 31;

int diff(char str[max_char]);
int main(int argc, char **argv) {
    if(argc<3) {
        return -1;
    }
    int n1 = strtol(argv[1], NULL, 10);
    char operatore = argv[2][0];
    int n2 = strtol(argv[3], NULL, 10);

    switch(operatore) {
        case '+':
            cout << n1+n2;
            break;
        case '-':
            cout << n1-n2;
            break;
        case '*':
            cout << n1*n2;
            break;
        case '/':
            cout << n1/n2;
            break;
    }

    return 0;
}

int diff(char str[max_char]) {
    int c=0;
    int i = 0;
    if(!(str[i] >= 'A' && str[i] <='Z') && !(str[i] >= 'a' && str[i] <='z'))
            return -1;
    if(str[i] >= 'A' && str[i] <='Z')
        str[i] += 'a'-'A';
    for(i = 1; str[i] !='\0'; i++) {
        if(str[i] >= 'A' && str[i] <='Z') {
            str[i] += 'a'-'A';
        } 
        if(!(str[i] >= 'A' && str[i] <='Z') && !(str[i] >= 'a' && str[i] <='z'))
            return -1;
        int delta = str[i-1]-str[i];
        if(delta<0) {
            c-=delta;
        } else {
            c+=delta;
        }
    }
    return c;
}