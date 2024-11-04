#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int RIGHE = 3;
const int COLONNE = 3;

void filtro_medio(const int a[RIGHE][COLONNE], double b[RIGHE][COLONNE]);
void inizializza(int m[RIGHE][COLONNE]);
void stampa(const int m[RIGHE][COLONNE]);
void stampa(const double m[RIGHE][COLONNE]);
int main() {
    srand(time(NULL));
    int m[RIGHE][COLONNE] = {{1,0,2},{2,1,0},{1,3,1}};
    double m2[RIGHE][COLONNE];
    // inizializza(m);
    
    stampa(m);
    filtro_medio(m,m2);
    stampa(m2);
    return 0;
}

void filtro_medio(const int a[RIGHE][COLONNE], double b[RIGHE][COLONNE]) {
    for(int i = 0; i < RIGHE; i++) {
        for(int j = 0; j < COLONNE; j++) {
            b[i][j] = 0;
            int c = 0;
            if(i>0) {
                b[i][j] += a[i-1][j];
                c++;
            }
            if(i < RIGHE-1) {
                b[i][j] += a[i+1][j];
                c++;
            }
            if(j > 0) {
                b[i][j] += a[i][j-1];
                c++;
            }
            if(j < COLONNE - 1) {
                b[i][j] += a[i][j+1];
                c++;
            }
            b[i][j] /= c;
        }
    }
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
void stampa(const double m[RIGHE][COLONNE]) {
    for(int i = 0; i < RIGHE; i++) {
        for(int j = 0; j < COLONNE; j++) {
            cout << m[i][j] << " "; 
        }
        cout << endl;
    }
    cout << endl;
}
