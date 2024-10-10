#include <iostream>
using namespace std;

/*
implementare una procedura di inserimento di un elemento in un array
ordinato
*/
void right_shift(int v[], int size, int start);
void insert(int v[], int size, int element, int index);
int main() {
    int size  = 9;
    int v[] = {1,3,5,7,9,11,13,15,-1};
    insert(v,size,16,0);
    // right_shift(v,size,1);
    for(int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    return 0;
}

void insert(int v[], int size, int element, int index) {
    if(index < size-1) {
        if(element >= v[index] && element <= v[index+1]) {
            right_shift(v,size,index);
            v[index+1] = element;
            return;
        }
        if(index == 0 && element < v[index]) {
            right_shift(v,size,index);
            v[index] = element;
            return;
        }
        if(index == size-2 && element > v[index]) {
            right_shift(v,size,index);
            v[index+1] = element;
            return;
        }
        insert(v,size,element,index+1);
    }
}

void right_shift(int v[], int size, int start) {
    if (start == size-1) {
        return;
    }
    right_shift(v,size,start+1);
    v[start+1] = v[start];
}