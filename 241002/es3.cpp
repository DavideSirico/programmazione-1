#include <iostream>
using namespace std;
/*Scrivere una funzione f:R-->R che restituisca:
-x^3 se x<=0
e^x-1 se x>0
e scrivere un programma main che calcoli la funzione f nei punti
-10,-9,...,-1,0,1,2,...,9,10
*/

double f(double);

int main() {
    for (int i = -10; i <= 10; i++) {
        cout << f(i) << endl;
    }
    return 0;
}

double f(double x){
    double res = 0;
    if(x<=0) {
        res = -(x*x*x);
    } else {
        res = pow(M_E,x-1);
    }
    return res;
}