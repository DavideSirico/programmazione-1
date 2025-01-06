#include <iostream>
using namespace std;

bool palindromo_ric(int *array, int i_s, int i_e);
bool palindromo(int *array, int dim);
int main() {
    int dim;
    do{
        cout << "Dimensione: ";
        cin >> dim;
    }while(dim>100);

    int *array = new int[dim];
    for(int i = 0; i < dim; i++) {
        cout << "Elemento: ";
        cin >> array[i];
    }
    if(palindromo(array, dim)) {
        cout << "Sequenza palindroma";
    } else {
        cout << "Sequenza non palindroma";
    }
    delete[] array;
    return 0;
}

bool palindromo(int *array, int dim) {
    return palindromo_ric(array, 0, dim-1);
}

bool palindromo_ric(int *array, int i_s, int i_e) {
    bool ris = array[i_s] == array[i_e];
    if(i_e == i_s) {
        ris = array[--i_s] == array[++i_e];
        return ris;
    }
    if(i_s>i_e) {
        return ris;
    }
    
    return palindromo_ric(array,++i_s,--i_e);
}
