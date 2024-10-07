#include <iostream>
#include <cmath>
using namespace std;

/* Dati in input tre numeri reali, a, b e c, scrivere
un programma che calcoli le soluzioni dell’equazione di
secondo grado (assumete che il delta sia positivo).
*/
int main() {
    
    float a,b,c;

    cin >> a >> b >> c;

    float result1 = (-b + sqrt((b*b)-(4*a*c))) / (2*a);
    float result2 = (-b - sqrt((b*b)-(4*a*c))) / (2*a);


    cout << result1 << endl << result2;

    return 0;
}