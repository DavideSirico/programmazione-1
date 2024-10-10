#include <iostream>
#include <cmath>
using namespace std;

/*
scrivere una procedura che calcoli la norma di un vettore di double
(la radice quadrata del prodotto scalare con se' stesso).
*/

double norma(double n);
double prodotto_scalare(double a[], double b[], int length, int counter);
int main() {
    const int length = 2;
    double a[length] = {35,60};
    
    cout << norma(prodotto_scalare(a,a,length,0));


    return 0;
}

double norma(double n) {
    return sqrt(n);
}
double prodotto_scalare(double a[], double b[], int length, int counter) {
    if (length == counter) {
        return 0;
    }
    return a[counter] * b[counter] + prodotto_scalare(a,b,length, counter+1);
}