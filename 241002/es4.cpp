#include <iostream>
using namespace std;
/*
scrivere una procedura che ruoti tre elementi a,b,c
   e si scriva un main di prova.
es:
  a=1;
  b=2;
  c=3;
  ruota(a,b,c); // a=2;b=3;c=1;
*/

void ruota(int* a, int* b, int* c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;

    return;
}

int main() {
    int a,b,c;
    a = 1;
    b = 2;
    c = 3;
    cout << a << " " << b << " " << c << endl;
    ruota(&a,&b,&c);
    cout << a << " " << b << " " << c << endl;

    return 0;
}

