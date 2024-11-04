#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int RIGHE = 3;
const int COLONNE = 3;

int somma_triangolo_sup(int m[RIGHE][COLONNE]);
void inizializza(int m[RIGHE][COLONNE]);
void stampa(int m[RIGHE][COLONNE]);
int main() {
    srand(time(NULL));
    int m[RIGHE][COLONNE];
    inizializza(m);
    stampa(m);
    cout << somma_triangolo_sup(m);
    
    return 0;
}

int somma_triangolo_sup(int m[RIGHE][COLONNE]) {
    int somma = 0;
    for(int i = 0; i < RIGHE; i++) {
        for(int j = 0; j < COLONNE; j++) {
            if(j >= i) {
                somma += m[i][j];
            }
        }
    }
    return somma;
}

void inizializza(int m[RIGHE][COLONNE]) {
    for(int i = 0; i < RIGHE; i++) {
        for(int j = 0; j < COLONNE; j++) {
            m[i][j] = rand()%10;
        }
    }
}

void stampa(int m[RIGHE][COLONNE]) {
    for(int i = 0; i < RIGHE; i++) {
        for(int j = 0; j < COLONNE; j++) {
            cout << m[i][j] << " "; 
        }
        cout << endl;
    }
    cout << endl;
}
