#include <iostream>
using namespace std;

/*
Scrivere un programma C++ che calcoli il risultato della seguente serie
che approssima il valore (pi greco^2 / 6). Si ricavi il valore
approssimato di pi greco. Il limite superiore di questa serie (il valore N)
viene dato dall’utente in input.
*/

int main() {
    int n{};
    cout << "Limite superiore: ";
    cin >> n;
    double res{0};
    for (int i = 1; i <= n; i++) {
        res += 1.0/(i*i);
    }
    cout << res;
    return 0;
}