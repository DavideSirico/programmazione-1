#include <iostream>
using namespace std;

const int RIGHE = 10;
const int COLONNE = 10;

bool is_isola(const int m[RIGHE][COLONNE], int row, int col);
void inizializza(int m[RIGHE][COLONNE]);
void stampa(const int m[RIGHE][COLONNE]);
int isole(const int m[RIGHE][COLONNE]);
int main() {
    srand(time(NULL));
    int m[RIGHE][COLONNE];
    inizializza(m);
    stampa(m);
    cout << isole(m);
    return 0;
}

int isole(const int m[RIGHE][COLONNE]) {
    int isola = 0;
    for(int i = 0; i < RIGHE; i++) {
        for(int j = 0; j < COLONNE; j++) {
            if(m[i][j] == 1 && is_isola(m,i,j)) {
                isola++;
            }
        }
    }
    return isola;
}

bool is_isola(const int m[RIGHE][COLONNE], int row, int col) {
    bool b = true;
    if(row > 0 && col > 0 && m[row-1][col-1] == 1) {
        b = false;
    }
    if(row > 0 && m[row-1][col] == 1) {
        b = false;
    }
    if(row > 0 && col < COLONNE-1 && m[row-1][col+1] == 1) {
        b = false;
    }
    if(col > 0 && m[row][col-1] == 1) {
        b = false;
    }
    if(col < COLONNE-1 && m[row][col+1] == 1) {
        b = false;
    }
    if(row < RIGHE-1 && col > 0 && m[row+1][col-1] == 1) {
        b = false;
    }
    if(row < RIGHE-1 && m[row+1][col] == 1) {
        b = false;
    }
    if(row < RIGHE-1 && col < COLONNE-1 && m[row+1][col+1] == 1) {
        b = false;
    }
    return b;
}

void inizializza(int m[RIGHE][COLONNE]) {
    for(int i = 0; i < RIGHE; i++) {
        for(int j = 0; j < COLONNE; j++) {
            m[i][j] = rand()%2;
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