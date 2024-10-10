#include <iostream>
using namespace std;

/*
scrivere una funzione che prenda come parametri 2 array di double
della stessa dimensione e ne calcoli il prodotto scalare.
a[0]*b[0] + ... + a[i]*b[i] + ... + a[dim-1]*b[dim-1]
*/

double prodotto_scalare(double a[], double b[], int length, int counter);

int main() {
    const int length = 6;
    double a[length] = {1,2,3,4,5,6};
    double b[length] = {1,2,3,4,5,6};

    cout << prodotto_scalare(a,b,length,0);
    return 0;
}

double prodotto_scalare(double a[], double b[], int length, int counter) {
    if (counter == length) {
        return 0;
    }
    return a[counter] * b[counter] + prodotto_scalare(a, b, length, counter + 1);
}
