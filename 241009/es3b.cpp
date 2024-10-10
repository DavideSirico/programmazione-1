#include <iostream>
#include <cmath>
using namespace std;

/*
scrivere una procedura che normalizzi un vettore, cioe' che
sostituisca un vettore con quello risultante dalla divisione di
tutti i suoi elementi per la nua norma.
*/
void normalizza(double a[], int length, int counter);
double norma(double n);
double prodotto_scalare(double a[], double b[], int length, int counter);
int main() {
    const int length = 6;
    double a[length] = {1,2,3,4,5,6};
    normalizza(a,length,0);
    cout << a[0];
    return 0;
}
void normalizza(double a[], int length, int counter) {
    if (counter == length) {
        return;
    }
    double n = norma(prodotto_scalare(a,a,length,0));
    a[counter] = a[counter]/n;
    return normalizza(a,length,counter+1);

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