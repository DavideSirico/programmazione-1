#include <iostream>
using namespace std;
int main() {
    int n = 1;
    int* p = &n;
    int &r = *p;
    int m = 2;
    p = &m;
    return 0;
}