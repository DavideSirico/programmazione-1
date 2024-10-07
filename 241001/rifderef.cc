#include <iostream>
using namespace std;

template <typename T>
void stampa(T& x) {
    cout << "L-value: " << &x << endl;
    cout << "R-value: " << x << endl;
    // cout << "sizeof(x): " << sizeof(x) << endl;
}

int main() {

  int n = 1;
  int* p = &n;

  int& r = *p;
  cout << "r" << endl;
  stampa(r);
  cout << "p" << endl;
  stampa(p);
  int m = 2;
  p = &m;
  cout << "r" << endl;
  stampa(r);
  cout << "p" << endl;
  stampa(p);


  cout << "r: " << r << endl;
  n++;
  cout << "r: " << r << endl;
  return 0;
}
