

#include <iostream>
using namespace std;

/*
Scrivere un programma C++ che, dati in input due numeri interi,
a e b, li salvi in due variabili distinte, max e min,
in cui la prima conterrà il numero maggiore tra i due e la seconda il
più piccolo
*/

int main() {
    int a,b;

    cin >> a >> b;

    int min;
    int max;

    max = a * (a > b);
    min = a * (a < b);

    max += b * !(a > b);
    min += b * !(a < b);

    cout << "max: " << max << endl << "min: " << min;

    return 0;
}