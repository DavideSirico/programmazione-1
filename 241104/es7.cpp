#include <iostream>
using namespace std;

const int RIGHE = 3;
const int COLONNE = 3;

void inizializza(int m[RIGHE][COLONNE]);
void stampa(const int m[RIGHE][COLONNE]);
int det(const int m[RIGHE][COLONNE], int shift, bool verso);
int sarrus(const int m[RIGHE][COLONNE]);
int main() {
    srand(time(NULL));
    int m[RIGHE][COLONNE];
    inizializza(m);
    stampa(m);
    cout << sarrus(m);
    return 0;
}

int sarrus(const int m[RIGHE][COLONNE]) {
    int somme = 0;
    for(int i = 0; i < RIGHE; i++) {
        somme += det(m,i,true);
    }
    cout << endl;
    for(int i = 0; i < RIGHE; i++) {
        somme -= det(m,i,false);
    }
    return somme;
}

int det(const int m[RIGHE][COLONNE], int shift, bool verso) {
    int temp = 1;
    if(verso) {
        // int colonna = (colonnaDiPartenza + riga) % COLONNE;

        int j = (COLONNE+shift)%COLONNE;
        for(int i = 0; i < RIGHE; i++) {
            temp *= m[i][j];
            cout << m[i][j] << " "; 
            j = (j + 1) % COLONNE;
        }
    } else {
        // int colonna = -(colonnaDiPartenza - riga) % COLONNE;

        int j = (COLONNE-shift-1)%COLONNE;
        for(int i = 0; i < RIGHE; i++) {
            temp *= m[i][j];
            cout << m[i][j] << " "; 
            j--;
            if(j < 0) {
                j = COLONNE - 1;
            }
        }
    }
    
    cout << endl;
    return temp;
}

void inizializza(int m[RIGHE][COLONNE]) {
    for(int i = 0; i < RIGHE; i++) {
        for(int j = 0; j < COLONNE; j++) {
            m[i][j] = rand()%10;
        }
    }
}

void stampa(const int m[RIGHE][COLONNE]) {
    for(int i = 0; i < RIGHE; i++) {
        for(int j = 0; j < COLONNE; j++) {
            cout << m[i][j] << " "; 
        }
        cout << endl;
    }
    cout << endl;
}