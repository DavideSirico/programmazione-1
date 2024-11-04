#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int RIGHE = 4;
const int COLONNE = 4;

void inizializza(int *m);
void stampa(int *m);
int main() {
    srand(time(NULL));
    int m[RIGHE][COLONNE];
    int* p = &m[0][0];
    inizializza(p);
    stampa(p);
    return 0;
}

void inizializza(int *m) {
    for(int i = 0; i < RIGHE; i++) {
        for(int j = 0; j < COLONNE; j++) {
            *(m+(i*COLONNE)+j) = rand()%101;
        }
    }
}

void stampa(int *m) {
    for(int i = 0; i < RIGHE; i++) {
        for(int j = 0; j < COLONNE; j++) {
            cout << *(m+(i*COLONNE)+j) << " "; 
        }
        cout << endl;
    }
    cout << endl;
}
