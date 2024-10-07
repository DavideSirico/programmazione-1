#include <iostream>
using namespace std;
/*
Prendere gli esempi di funzioni ricorsive in questa directory
(tranne "espressione.cc") e farne una versione iterativa.
*/


void doppio(void *array, int lenght) {
    for(int i = 0; i < lenght; i++) {
        *(((int*)array)+i) *= 2;
    }
    return;
}

int main() {
    int array[10] = {1,2,3,4,5,6,7,8,9,10};

    doppio(array, 10);

    for(int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    return 0;
}
