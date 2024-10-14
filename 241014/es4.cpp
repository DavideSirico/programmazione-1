#include <iostream>
#include <climits>
using namespace std;

/*
Dati in input da 1 a 5 interi, scrivere una funzione che
ritorni il valore massimo. Usare argomenti di default per il
secondo, terzo, quarto e quinto input. 
*/

int massimo(int n1, int n2, int n3=INT_MIN, int n4=INT_MIN, int n5=INT_MIN);

int main() {
    int array[5];
    int numero_variabili;
    cin >> numero_variabili;
    for(int i = 0; i < numero_variabili; i++) {
        cin >> array[i];
    }
    
    switch (numero_variabili) {
    case 2:
        cout << massimo(array[0], array[1]);
        break;
    
    case 3:
        cout << massimo(array[0], array[1], array[2]);
        break;
    
    case 4:
        cout << massimo(array[0], array[1], array[2], array[3]);
        break;
    case 5:
        cout << massimo(array[0], array[1], array[2], array[3], array[4]);
        break;
        
    default:
        cout << "numero di variabili non valido";
        break;
    }

    
    return 0;
}

int massimo(int n1, int n2, int n3, int n4, int n5) {
    int array[5] = {n1,n2,n3,n4,n5};
    int max = array[0];
    for(int i = 1; i < 5; i++) {
        if(array[i] > max) {
            max = array[i];
        }
    }
    return max;
}