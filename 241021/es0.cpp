#include <iostream>
using namespace std;

int test(int n) {
    if (n <= 0)
        return 0;
    else if (n%2 == 0)
        return n + test(n - 1);
    else
        return test(n - 1) - n;
}
int main() {
    // 0-1+2-3+4-5 = -3
    int r = test(5);
    cout << r << endl;
    return 0;
}