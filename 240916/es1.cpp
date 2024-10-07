#include <iostream>
using namespace std;

// Scrivere un programma che, dato in input il raggio, calcoli l’area e la circonferenza di un cerchio.

int main() {
    float PI = 3.14;
    float raggio;
    cout << "Inserire il raggio: ";
    cin >> raggio;
    float area = PI * raggio * raggio;
    float circonferenza = 2 * PI * raggio;

    cout << "Area: " << area << endl << "Circonferenza: " << circonferenza;
    return 0;
}