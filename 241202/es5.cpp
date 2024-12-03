#include <iostream>
#include <cstdlib>
using namespace std;
/* Scrivere un programma che, dati due interi in input (righe e colonne), crei
dinamicamente una matrice e la riempia con valori interi random (è concesso
l’uso della funzione rand() nella libreria <cstdlib>). In seguito, chiedere
all’utente le dimensioni della sottomatrice da stampare. Le dimensioni sono
fornite tramite quattro numeri, corrispondenti alle coordinate del primo
elemento (2 numeri) e alle dimensioni della sottomatrice (numero di righe e
colonne). Se le dimensioni fornite dall’utente eccedono quelle della matrice,
stampare la sottomatrice massima disponibile. Deallocare infine la matrice. */
void visualizza_matrice(int **matr, int n, int m);
int main() {
    srand(time(NULL));

    int righe,colonne;
    cin >> righe >> colonne;
    int **matrice = new int*[righe];

    int x_numero, y_numero;
    int sotto_righe, sotto_colonne;
    cin >> x_numero >> y_numero >> sotto_righe >> sotto_colonne;

    for(int i = 0; i < righe; i++) {
        int *riga = new int[colonne];
        matrice[i] = riga;
        for(int j = 0; j < colonne; j++) {
            matrice[i][j] = rand()%10;
        }
    }
    visualizza_matrice(matrice,righe,colonne);
    cout << endl;
    if(sotto_colonne > colonne) {
        sotto_colonne = colonne;
    }
    if(sotto_righe > righe) {
        sotto_righe = righe;
    }
    for(int i = x_numero; i < sotto_righe; i++) {
        for(int j = y_numero; j < sotto_colonne; j++) {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for(int i = 0; i < righe; i++) {
        delete matrice[i];
    }
    delete[] matrice;

    return 0;
}


void visualizza_matrice(int **matr, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << matr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}