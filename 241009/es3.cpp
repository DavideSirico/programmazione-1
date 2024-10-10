#include <iostream>
#include <cmath>
using namespace std;

/*
scrivere una procedura che normalizzi un vettore, cioe' che
sostituisca un vettore con quello risultante dalla divisione di
tutti i suoi elementi per la nua norma.
*/
void normalizza(double a[], int length);
double norma(double n);
double prodotto_scalare(double a[], double b[], int length);
int main() {
    const int length = 6;
    double a[length] = {1,2,3,4,5,6};
    normalizza(a,length);
    cout << a[0];


    return 0;
}
void normalizza(double a[], int length) {
    double n = norma(prodotto_scalare(a,a,length));
    for (int i = 0; i < length; i++) {
        a[i] = a[i] / n;
    }
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



