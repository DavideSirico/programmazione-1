#include <iostream>
using namespace std;

const int MAX_RIGHE = 5;
const int MAX_COLONNE = 5;

// Funzione ricorsiva per trovare un percorso attraverso la palude
bool trovaPercorso(int palude[MAX_RIGHE][MAX_COLONNE], int percorso[MAX_COLONNE], char mappaPercorso[MAX_RIGHE][MAX_COLONNE], int riga, int colonna, int colonne) {
    // Verifica se abbiamo raggiunto l'ultima colonna
    if (colonna == colonne - 1 && palude[riga][colonna] == 1) {
        percorso[colonna] = riga;
        mappaPercorso[riga][colonna] = '*';
        return true;
    }

    // Verifica se la cella corrente è valida e se è terraferma
    if (riga >= 0 && riga < MAX_RIGHE && colonna >= 0 && colonna < colonne && palude[riga][colonna] == 1) {
        // Marca la cella corrente come parte del percorso
        mappaPercorso[riga][colonna] = '*';
        percorso[colonna] = riga;

        // Prova a spostarsi in (riga-1, colonna+1)
        if (trovaPercorso(palude, percorso, mappaPercorso, riga - 1, colonna + 1, colonne))
            return true;

        // Prova a spostarsi in (riga, colonna+1)
        if (trovaPercorso(palude, percorso, mappaPercorso, riga, colonna + 1, colonne))
            return true;

        // Prova a spostarsi in (riga+1, colonna+1)
        if (trovaPercorso(palude, percorso, mappaPercorso, riga + 1, colonna + 1, colonne))
            return true;

        // Se nessuna mossa funziona, rimuovi l'elemento dal percorso e segna la cella come non parte del percorso
        percorso[colonna] = -1;
        mappaPercorso[riga][colonna] = '-';
    }

    return false;
}

void visualizzaMappa(char mappa[MAX_RIGHE][MAX_COLONNE], int righe, int colonne) {
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            cout << mappa[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    // Definizione della mappa della palude
    int palude[MAX_RIGHE][MAX_COLONNE] = {
        {1, 1, 0, 1, 0},
        {1, 1, 1, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0}
    };

    int righe = MAX_RIGHE;
    int colonne = MAX_COLONNE;

    // Inizializzazione della mappa per visualizzare il percorso
    char mappaPercorso[MAX_RIGHE][MAX_COLONNE];
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            mappaPercorso[i][j] = '-';
        }
    }

    // Array per memorizzare il percorso
    int percorso[MAX_COLONNE];
    for (int i = 0; i < colonne; ++i) {
        percorso[i] = -1;
    }

    bool trovato = false;

    // Prova a partire da ogni cella nella prima colonna
    for (int riga = 0; riga < righe; ++riga) {
        if (palude[riga][0] == 1) {
            // Ripristina la mappa del percorso per ogni tentativo
            for (int i = 0; i < righe; ++i) {
                for (int j = 0; j < colonne; ++j) {
                    mappaPercorso[i][j] = '-';
                }
            }

            if (trovaPercorso(palude, percorso, mappaPercorso, riga, 0, colonne)) {
                trovato = true;
                break;
            }
        }
    }

    if (trovato) {
        cout << "Percorso trovato:\n";
        for (int i = 0; i < colonne; ++i) {
            if (percorso[i] != -1) {
                cout << percorso[i] << " ";
            }
        }
        cout << "\n\nMappa della palude con percorso:\n";
        visualizzaMappa(mappaPercorso, righe, colonne);
    } else {
        cout << "Nessun percorso trovato.\n";
    }

    return 0;
}
