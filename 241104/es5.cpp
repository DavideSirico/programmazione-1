#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// TODO
const int RIGHE = 5;
const int COLONNE = 6;

int next(int m[RIGHE][COLONNE], int row, int col);
void stampa(const int m[RIGHE][COLONNE]);
void stampa(const char m[RIGHE][COLONNE]);
bool sabbie_mobili(int m[][COLONNE], int passi[], char terra_terma[RIGHE][COLONNE]);
bool check_rows(int m[RIGHE][COLONNE], int start_row, int passi[COLONNE]);
int main() {
    srand(time(NULL));
    int m[RIGHE][COLONNE] = {
        {1,1,0,1,0,0},
        {1,0,0,0,0,0},
        {0,1,0,0,0,1},
        {0,0,1,1,1,0},
        {0,1,0,0,0,0},
    };
    int passi[COLONNE];
    char terra_ferma[RIGHE][COLONNE];
    stampa(m);
    sabbie_mobili(m,passi,terra_ferma);
    stampa(terra_ferma);
    for(int i = 0; i < COLONNE; i++) {
        cout << passi[i] << " ";
    }
    cout << endl;
    return 0;
}
bool sabbie_mobili(int m[][COLONNE], int passi[], char terra_ferma[RIGHE][COLONNE]) {
    int i = 0;
    bool trovato = false;
    // parto da ogni riga per checkare se esiste un percorso valido
    while (!trovato && i < RIGHE) {
        trovato = check_rows(m, i, passi);
        i++;
    }
    for(int i = 0; i < RIGHE; i++) {
        for(int j = 0; j < COLONNE; j++) {
            if(passi[j] == i) {
                terra_ferma[i][j] = '*';
            } else {
                terra_ferma[i][j] = '-';
            }
        }
    }
    // se non esiste piango
    return trovato;
}
bool check_rows(int m[RIGHE][COLONNE], int start_row, int passi[COLONNE]) {
    bool trovato = true;
    int row = start_row;
    int col = 0;
    // controllo lo start
    if (m[row][col] == 1) {
        // se ci siamo passiamo alla colonna dopo
        passi[col] = row;
        col++;

        while (trovato && (col < COLONNE)) {
            int prossimo = next(m,row,col);
            if(prossimo == -2) {
                trovato = false;
            } else {
                row = row + prossimo;
                passi[col] = row;
                col++;
            }
        }
    } else {
        trovato = false;
    }

    return trovato;
}

int next(int m[RIGHE][COLONNE], int row, int col) {
    if(row > 0 && m[row-1][col] == 1) {
        return -1;
    }
    if(m[row][col] == 1) {
        return 0;
    }
    if(row < RIGHE-1 && m[row+1][col] == 1) {
        return 1;
    }
    return -2;
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
void stampa(const char m[RIGHE][COLONNE]) {
    for(int i = 0; i < RIGHE; i++) {
        for(int j = 0; j < COLONNE; j++) {
            cout << m[i][j] << " "; 
        }
        cout << endl;
    }
    cout << endl;
}
