#include <iostream>
using namespace std;

int main () {

    int b = 1; int z = 2;
    while (z >= 0) {
        z--; b++;
    }
    b -= z;

    cout << b;
    cout << endl << z;
    return 0;
}
