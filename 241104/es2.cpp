#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int RIGHE = 4;
const int COLONNE = 4;

void trasposta(int m[RIGHE][COLONNE]);
void inizializza(int m[RIGHE][COLONNE]);
void stampa(int m[RIGHE][COLONNE]);
int main() {
    srand(time(NULL));
    int m[RIGHE][COLONNE];
    inizializza(m);
    stampa(m);
    trasposta(m);
    stampa(m);
    return 0;
}

void trasposta(int m[RIGHE][COLONNE]) {
    int trasp[RIGHE][COLONNE];
    for(int i = 0; i < RIGHE; i++) {
        for(int j = 0; j < COLONNE; j++) {
            trasp[i][j] = m[j][i];
        }
    }
    for(int i = 0; i < RIGHE; i++) {
        for(int j = 0; j < COLONNE; j++) {
            m[i][j] = trasp[i][j];
        }
    }
}

void inizializza(int m[RIGHE][COLONNE]) {
    for(int i = 0; i < RIGHE; i++) {
        for(int j = 0; j < COLONNE; j++) {
            m[i][j] = rand()%101;
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
