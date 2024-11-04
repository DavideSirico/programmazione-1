#include <iostream>
#include <stdlib.h>
using namespace std;

void inizializza_array(int v[], int size);
void stampa_array(int v[], int size);
int max_array(int v[], int size);
void counting_sort(int v[], int size);
int main() {
    srand(time(NULL));
    int size = 10;
    int a[size];
    inizializza_array(a, size);
    stampa_array(a,size);
    counting_sort(a,size);
    stampa_array(a,size);

    return 0;
}
void counting_sort(int v[], int size) {
    int max = max_array(v,size);
    int *count = new int[max+1];
    int occorrenze = 0;
    count[0] = occorrenze;
    for(int i = 0; i <= max; i++) {
        for(int j = 0; j < size; j++) {
            if(v[j] == i) {
                occorrenze++;
            }
        }
        count[i] = occorrenze;

    }
    int out[size];
    for(int i = 0; i < size; i++) {
        int index = --count[v[i]];
        out[index] = v[i];
    }
    for(int i = 0; i < size; i++) {
        v[i] = out[i];
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

int max_array(int v[], int size) {
    int max = v[0];
    for(int i = 1; i < size; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}
