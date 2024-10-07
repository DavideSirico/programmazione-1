#include <iostream>
using namespace std;
/*Scrivere un programma C++ che, ricevuti in input tre numeri interi a,
b, c, di cui b e c siano gli estremi di un intervallo, stampi a video un
numero, seguendo il comportamento della funzione rappresentata
sotto, a seconda della posizione di a nell’intervallo b, c. */

int main() {
    int a,b,c;

    cin >> a >> b >> c;

    if(b<=a && a<=c) {
        cout << "-1";
    } else if(a<b) {
        cout << "1";
    } else {
        cout << "0";
    }

    return 0;
}