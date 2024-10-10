#include <iostream>
#include <cmath>
using namespace std;

/*
scrivere una procedura che calcoli la norma di un vettore di double
(la radice quadrata del prodotto scalare con se' stesso).
*/

double norma(double n);
double prodotto_scalare(double a[], double b[], int length);
int main() {
    const int length = 2;
    double a[length] = {35,60};
    
    cout << norma(prodotto_scalare(a,a, length));


    return 0;
}

double norma(double n) {
    return sqrt(n);
}
double prodotto_scalare(double a[], double b[], int length) {
    double c = 0;
    for(int i = 0; i < length; i++) {
        c += a[i]*b[i];
    }
    return c;
}



