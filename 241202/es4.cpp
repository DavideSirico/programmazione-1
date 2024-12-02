#include <iostream>
#include <cstdlib>
using namespace std;


void visualizza(char *array, int dim);
void visualizza_ric(char *array, int dim, int index);

void inizializza(char *array, int dim);
void inizializza_ric(char *array, int dim, int index);

void left_shift_ric(char v[], int length, int start);
void left_shift(char v[], int length, int j);
int main() {
    srand(time(NULL));
    int j,n;
    cout << "j: ";
    cin >> j;
    cout << "n: ";
    cin >> n;
    char *v = new char[n];

    inizializza(v,n);
    visualizza(v,n);
    cout << endl;
    left_shift(v,n,j);
    visualizza(v,n);

    delete v;
    return 0;
}

void left_shift(char v[], int length, int j) {
    for(int i = 0; i < j; i++) {
        left_shift_ric(v,length, 0);
    }
}
void left_shift_ric(char v[], int length, int start) {
    if(start < length-1) {
        char temp = v[start];
        v[start] = v[start+1];
        left_shift_ric(v,length, start+1);
        v[length-1] = temp;
    }
}


void inizializza(char *array, int dim) {
    inizializza_ric(array, dim, 0);
}
void inizializza_ric(char *array, int dim, int index) {
    if(index<dim) {
        array[index] = 'a' + rand()%25;
        inizializza_ric(array, dim, ++index);
    }
}


void visualizza(char *array, int dim) {
    visualizza_ric(array,dim,0);
}
void visualizza_ric(char *array, int dim, int index) {
    if(index<dim) {
        cout << array[index] << " ";
        visualizza_ric(array,dim,index+1);
    }
}