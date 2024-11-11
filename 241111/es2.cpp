#include <iostream>
#include <cstdlib>
using namespace std;

/* Scrivere un programma che, dati in input dall’utente da riga di
comando due numeri interi R e C, crei dinamicamente una
matrice con R righe ed C colonne. Popolate poi questa matrice
con dei numeri random.
Infine, stampate questa matrice a video. */

void free_matrix(int** matrix, int R);
void print_matrix(int** matrix, int r, int c);
int ** generate_matrix(int R, int C);
int main(int argc, char *argv[]) {
    srand(time(NULL));
    if(argc==3) {
        int r = atoi(argv[1]);
        int c = atoi(argv[2]);
        int **matrix = generate_matrix(r,c);
        print_matrix(matrix, r, c);
        free_matrix(matrix, r);
    }

    return 0;
}

void free_matrix(int** matrix, int R) {
    for (int i = 0; i < R; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void print_matrix(int** matrix, int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int ** generate_matrix(int R, int C) {
    int **matrix = new int*[R];
    for(int i = 0; i < R; i++) {
        matrix[i] = new int[C];
        for(int j = 0; j < C; j++) {
            matrix[i][j] = rand()%100;
        }
    }
    return matrix;
}