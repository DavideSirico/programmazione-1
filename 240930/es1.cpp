#include <iostream>
using namespace std;

/*Dati in input tre numeri interi, scrivere un programma C++
che ritorni a video il minimo tra questi tre numeri.*/

int main() {
    int a,b,c;
    cout << "Inserire 3 numeri: ";
    cin >> a >> b >> c;

    if (a<b) {
        if(a<c) {
            cout << "A e' il minimo: " << a;
        } else {
            cout << "C e' il minimo: " << c;
        }
    } else {
        if (b<c) {
            cout << "B e' il minimo: " << b;
        } else {
            cout << "C e' il minimo: " << c;
        }
    }

    return 0;
}