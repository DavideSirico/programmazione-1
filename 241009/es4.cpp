#include <iostream>
#include <cmath>
using namespace std;

/*
scrivere una funzione che dica se due vettori della stessa
dimensione sono ortogonali (due vettori sono ortogonali se il loro
prodotto scalare e' nullo).
*/
bool ortogonali(double a[], double b[], int length);
double prodotto_scalare(double a[], double b[], int length);
int main() {
    const int length = 6;
    double a[length] = {1,2,3,4,5,6};
    double b[length] = {1,2,3,4,5,6};
    ortogonali(a,b,length);
    cout << a[0];


    return 0;
}

bool ortogonali(double a[], double b[], int length) {
    if(prodotto_scalare(a,b,length) == 0) {
        return true;
    } else {
        return false;
    }
}

double prodotto_scalare(double a[], double b[], int length) {
    double c = 0;
    for(int i = 0; i < length; i++) {
        c += a[i]*b[i];
    }
    return c;
}