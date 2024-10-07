#include <iostream>
#include <cmath>
using namespace std;

/*
reimplementare l'esempio della serie sum 1/(2^i) implementando
    esplicitamente la funzione double pow2(int) che calcola 2^i
    (2*2*2*2.....*2)
*/

double pow2(int);

int main() {
    int n;
    cin >> n;
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += 1.0/(pow2(i));
    }
    cout << res;

    return 0;
}

double pow2(int n) {
    double res = 1;
    for(int i = 0; i < n; i++) {
        res *= 2;
    }
    return res;
}