#include <iostream>
using namespace std;

/*
scrivere una funzione (int) che calcoli sia l'area del cerchio sia
il suo perimetro e che la restituisca tramite la lista dei
parametri, e che restituisca un valore booleano 1 se ha potuto
calcolarlo (raggio >=0), 0 altrimenti.
*/

int funzione(double* raggio, double* area, double* perimetro);

int main() {
    double raggio{1};
    double perimetro{};
    double area{};

    funzione(&raggio,&area,&perimetro);
    cout << "Area: " << area << " Perimetro: " << perimetro;
    return 0;
}

int funzione(double* raggio, double* area, double* perimetro) {
    if (*raggio >= 0) {
        *perimetro = 2 * 3.14 * (*raggio);
        *area = (*raggio) * (*raggio) * 3.14;
        return 1;
    }
    return 0;
}