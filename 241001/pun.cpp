#include <iostream>
using namespace std;

template <typename T>
void stampa(T& x) {
    cout << "L-value: " << &x << endl;
    cout << "R-value: " << x << endl;
    cout << "sizeof(x): " << sizeof(x) << endl;
}

int main () {
    int x = 10;
    int y = 12;
    int &ref_x = x; // uguali 
    int &ref_y = y; // uguali 
    stampa(x);
    stampa(ref_x);
    stampa(y);
    stampa(ref_y);

    int* point_x = &x;
    cout << "point x: " << *point_x;
    point_x = &y;
    cout << "point y: " << *point_x;

    stampa(point_x);
    // stampa(point_y);

    return 0;
}