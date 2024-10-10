#include <iostream>
using namespace std;

/*
implementare la linear search in modo ricorsivo
*/
bool linear_search(int v[], int size, int element, int index);
int main() {
    int v[] = {1,2,3,4,5,6,7};
    cout << (linear_search(v,7,4,0) ? "True" : "False");
    return 0;
}

bool linear_search(int v[], int size, int element, int index) {
    if (element == v[index]) {
        return true;
    }
    if (index >= size) {
        return false;
    }
    return linear_search(v,size,element,index+1);
}