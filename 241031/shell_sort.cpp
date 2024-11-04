#include <iostream>
#include <stdlib.h>
using namespace std;

void swap(int *a, int *b);
void inizializza_array(int v[], int size);
void stampa_array(int v[], int size);
void shell_sort(int v[], int size);
int main() {
    srand(time(NULL));
    int size = 8;
    int a[size];
    inizializza_array(a, size);
    stampa_array(a,size);

    shell_sort(a,size);

    stampa_array(a,size);

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shell_sort(int v[], int size) {
    for(int dist = size/2; dist > 0; dist=dist/2) {
        for(int i = 0; i < size-dist; i++) {
            if(v[i] > v[i+dist]) {
                swap(v[i],v[i+dist]);
            }
        }
    }
}

void inizializza_array(int v[], int size) {
    for(int i = 0; i < size; i++) {
        v[i] = rand()%101;
    }
}

void stampa_array(int v[], int size) {
    for(int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
