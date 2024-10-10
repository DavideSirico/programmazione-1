#include <iostream>
using namespace std;
void swap_ref(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void swap_punt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap_punt2(int * &a, int *&b) {
    int *ptemp = a;
    a = b;
    b = ptemp;
}
void swap_punt3(int **a, int **b) {
    int *temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int a = 10;
    int b = 20;
    int *pa = &a;
    int *pb = &b;
    swap_ref(a,b);
    cout << "a: " << a << "\tb: " << b << endl;
    swap_punt(&a,&b);
    cout << "a: " << a << "\tb: " << b << endl;
    swap_punt2(pa,pb);
    cout << "a: " << a << "\tb: " << b << endl;
    cout << "pa: " << *pa << "\tpb: " << *pb << endl;
    swap_punt3(&pa,&pb);
    cout << "a: " << a << "\tb: " << b << endl;
    cout << "pa: " << *pa << "\tpb: " << *pb << endl;

    return 0;
}