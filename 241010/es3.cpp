#include <iostream>
using namespace std;
/*
Scrivere un programma che prenda in input un numero e
stampi a video il numero invertito usando una procedura.
*/

void ribalta(int n);
int main() {
    cout << "Inserire un numero: ";
    int n;
    cin >> n;
    ribalta(n);
    return 0;
}


int n_cifre(int n) {
    int cifre = 1;
    while(n>9) {
        n = n/10;
        cifre++;
    }
    return cifre;
} 

int pow(int base, int esponente) {
    int res = 1;
    for(int i = 0; i < esponente; i++) {
        res = res*base;
    }
    return res;
}

void ribalta(int n) {
    int ribaltato = 0;
    int cifre = n_cifre(n)-1;
    while(n>0) {
        ribaltato += (n%10)*pow(10,cifre);
        n = n/10;
        cifre--;
    }
    cout << ribaltato;
}