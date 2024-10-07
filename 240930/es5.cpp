#include <iostream>
using namespace std;
/*Dato in input due numeri interi, a ed n (dove n >= 1), scrivere
un programma che stampi a video la successione di potenze
di a da 1 ad n.
a = 2, n = 6
Output: 2, 4, 8, 16, 32, 64*/

int main () {
    
    int a, n;
    cin >> a >> n;
    int i = 1;
    int potenza = a;
    while (i<=n) {
        cout << a << "^" << i << " = " << potenza << endl;
        potenza *= a;
        i++;
    }
    

    return 0;
}