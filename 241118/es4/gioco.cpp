#include <iostream>
using namespace std;
extern const int DIM = 3;
void inizializzaMatrice (char matrice[DIM][DIM]) {
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            matrice[i][j] = ' ';
        }
    }
}
void stampaMatrice(const char matrice[DIM][DIM]) {
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM-1; j++) {
                cout << matrice[i][j] << "|";
        }
        cout << matrice[i][DIM-1];
        cout << endl;
    }
    cout << "-----------------------------------" << endl;
}
bool gioca(char matrice[DIM][DIM], bool turnoUtente, char simboloUtente, char simboloComputer) {
    if(turnoUtente) {
        cout << "Mossa (1-9): ";
        int mossa;
        cin >> mossa;
        if(mossa<1 || mossa>9) {
            cout << "Mossa non valida" << endl;
            return false;
        }
        mossa--;
        if(matrice[mossa/3][mossa%3] == ' ') {
            matrice[mossa/3][mossa%3] = simboloUtente;
        } else {
            cout << "Cella già occupata" << endl;
            return false;
        }
    } else {
        int mossa;
        do {
            mossa = rand()%9+1;
        } while(matrice[mossa/3][mossa%3] != ' ');
        matrice[mossa/3][mossa%3] = simboloComputer;
    }

    return true;
}
bool controllaVincita (const char matrice[DIM][DIM], char simbolo, bool &pareggio) {
    // orizzontali
    for(int i = 0; i < DIM; i++) {
        if(matrice[0][i] == simbolo && matrice[1][i] == simbolo && matrice[2][i] == simbolo) {
            return true;
        }
    }
    // verticali
    for(int i = 0; i < DIM; i++) {
        if(matrice[i][0] == simbolo && matrice[i][1] == simbolo && matrice[i][2] == simbolo) {
            return true;
        }
    }
    // oblique
    if(matrice[0][0] == simbolo && matrice[1][1] == simbolo && matrice[2][2] == simbolo) {
        return true;
    }
    if(matrice[0][2] == simbolo && matrice[1][1] == simbolo && matrice[2][0] == simbolo) {
        return true;
    }
    int c = 0;
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            if(matrice[i][j] != ' ') {
                c++;
            }
        }
    }
    if(c==9) {
        pareggio = true;
    }
    return false;
}
void iniziaGioco() {
    cout << "Simbolo utente (X/O): ";
    char simboloUtente;
    cin >> simboloUtente;
    if(simboloUtente != 'X' && simboloUtente != 'O') {
        cout << "Simbolo non valido";
        return;
    }
    char simboloComputer;
    if(simboloUtente == 'X') {
        simboloComputer = 'O';
    } else {
        simboloComputer = 'X';
    }
    char matrice[DIM][DIM];
    bool pareggio = false;
    inizializzaMatrice(matrice);
    while(true) {
        gioca(matrice, true, simboloUtente, simboloComputer);
        stampaMatrice(matrice);
        if(controllaVincita(matrice, simboloUtente,pareggio)) {
            cout << "Vince l'utente";
            break;
        }
        if(pareggio) {
            cout << "Pareggio";
            break;
        }
        gioca(matrice, false, simboloUtente, simboloComputer);
        stampaMatrice(matrice);
        if(controllaVincita(matrice, simboloComputer,pareggio)) {
            cout << "Vince il computer";
            break;
        }
        if(pareggio) {
            cout << "Pareggio";
            break;
        }

    }

}