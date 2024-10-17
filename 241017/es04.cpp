#include <iostream>
using namespace std;

/*
Scrivere un programma che, preso in input un numero
intero, controlli se il numero è un palindromo.
Scrivere una funzione ricorsiva che faccia il controllo.
*/
bool palindromo(int n);
bool palindromo_rec(int n, int rev, int i, int cifre);
int pow(int base, int esponente);
int n_cifre(int n);
int main() {
    int n = 11;
    cout << n << (palindromo(n) ? " e' " : " non e'") << " palindromo";
    return 0;
}


bool palindromo(int n) {
    return palindromo_rec(n,0,1,n_cifre(n));
}
bool palindromo_rec(int n, int rev, int i, int cifre) {
    if((i-1) == cifre) {
        // cout << "Last " << rev << endl;
        return n==rev;
    } else {
        int cifra = (n/(pow(10,i-1)))%10;
        rev += cifra * pow(10,cifre-i);
        return palindromo_rec(n,rev,i+1,cifre);
    }
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
