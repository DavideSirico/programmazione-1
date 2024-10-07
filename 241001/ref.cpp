#include <iostream>
using namespace std;


int main() {
    int x = 10;
    double y = 12.0;

    cout << x << " " << y;

    int &ref = x;
    double &ref2 = y;
    cout << endl << ref << " " << sizeof(ref);
    cout << endl << ref2 << " " << sizeof(ref2);


    int& ref3 = x;
    cout << endl << ref3 << " " << sizeof(ref3);


    return 0;
}