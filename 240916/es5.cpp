#include <iostream>
using namespace std;

int main() {

    cout << "0 AND 0: " << bool(false&&false) << endl;
    cout << "0 AND 1: " << bool(false&&true) << endl;
    cout << "1 AND 0: " << bool(true&&false) << endl;
    cout << "1 AND 1: " << bool(true&&true) << endl;
    cout << endl;
    cout << "0 OR 0: " << bool(false||false) << endl;
    cout << "0 OR 1: " << bool(false||true) << endl;
    cout << "1 OR 0: " << bool(true||false) << endl;
    cout << "1 OR 1: " << bool(true||true) << endl;

    return 0;
}