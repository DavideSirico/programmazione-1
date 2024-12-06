#include <iostream>
#include "pila.h"


using namespace std;


/**
 * Ricordare che il file "pila.h" contiene la definizione della struct "cella" (qui sotto riportata)
 * 
 * struct cella {
 *   int indiceRiga;
 *   int indiceColonna;
 * };
 */
void risolviLabirinto(int [][5], int, int);


int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale  

    // E' possibile modificare la matrice per effettuare dei test   
    int labirinto[5][5] = {
        { 1, 0, 1, 1, 0 },
        { 1, 1, 1, 0, 1 },
        { 0, 1, 0, 1, 1 },
        { 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1 }
    };

    // E' possibile modificare la cella di arrivo per effettuare dei test (la cella di partenza invece è sempre [0,0])   
    cout<<"Percorso: ";
    risolviLabirinto(labirinto, 0, 3);
   
    return 0;
}

void print_stack() {
    if(vuota()) {
        cout << endl;
    } else {
        cella temp;
        top(temp);
        pop();
        print_stack();
        cout << "[" << temp.indiceRiga << "," << temp.indiceColonna << "], ";
    }
}

void risolviLabirinto(int lab[][5], int x, int y) {

    init();
    bool visitata[5][5] = {
        {true, false, false, false, false},
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, false, false, false, false},
    };
    cella p = {0,0};
    push(p);
    while (!vuota()) {
        cella t;
        top(t);
        int i = t.indiceRiga;
        int j = t.indiceColonna;

        // se arrivo a destinazione
        if (i == x && j == y) {
            print_stack();
        } else {
            // cella sotto 
            if (i - 1 >= 0 && !visitata[i-1][j] && lab[i - 1][j] == 1) {
                cella nuovaCella = {i-1,j};
                push(nuovaCella);
                visitata[i-1][j] = true;
            // cella sopra
            } else if (i + 1 < 5 && !visitata[i+1][j] && lab[i + 1][j] == 1) {
                cella nuovaCella = {i+1,j};
                push(nuovaCella);
                visitata[i+1][j] = true;
            // cella sinistra
            } else if (j - 1 >= 0 && !visitata[i][j-1] && lab[i][j-1] == 1) {
                cella nuovaCella = {i,j-1};
                push(nuovaCella);
                visitata[i][j-1] = true;
            // cella destra
            } else if (j + 1 < 5 && !visitata[i][j+1] && lab[i][j+1] == 1) {
                cella nuovaCella = {i,j+1};
                push(nuovaCella);
                visitata[i][j+1] = true;
            } 
            else {
                pop();
            }
        }
    }
}