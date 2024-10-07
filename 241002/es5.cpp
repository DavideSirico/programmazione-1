#include <iostream>
using namespace std;

/*
scrivere una PROCEDURA (void) che calcoli l'area del cerchio dato
   il raggio.
*/

void procedura(double* raggio, double* area);

int main() {
    double raggio = 1;
    double area;
    procedura(&raggio,&area);
    cout << "area: " << area;
    return 0;
}

void procedura(double* raggio, double *area) {
    *area = (*raggio) * (*raggio) * 3.14;
    
}