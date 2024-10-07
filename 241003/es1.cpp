#include <iostream>
using namespace std;

/*
Scrivere un programma C++ che, dato in input un valore intero
n, stampi a video la successione di fibonacci fino all’n-esima
cifra
*/

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n;
    cout << "Inserire un numero: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }

    return 0;
}