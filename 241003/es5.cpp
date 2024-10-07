#include <iostream>
using namespace std;

/*
Scrivere un programma C++ che dato in input un numero binario,
stampi a video il suo corrispondente valore decimale.
Input: 10010 => 18

Scrivere un programma C++ che, dato in input un numero binario,
stampi a video il suo corrispondente valore decimale.
*/

int pow(int base, int esponente) {
    int res = 1;
    for(int i = 0; i < esponente; i++) {
        res = res*base;
    }
    return res;
}


int bin_2_dec(int n) {
    int res = 0;
    for(int i = 0; n != 0; i++) {
        res += (n % 2) * pow(2,i);
        n = n/10;
    }
    return res;
}

int main() {
    int n;
    cout << "Inserire un numero binario: ";
    cin >> n;
    n = bin_2_dec(n);
    cout << n << endl;

    return 0;
}