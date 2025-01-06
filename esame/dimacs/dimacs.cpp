#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

// Funzione per valutare una clausola
bool evalClausola(int* clausola, int numLetterali, bool* assegnazioni) {
    for (int i = 0; i < numLetterali; ++i) {
        int literal = clausola[i];
        int varIndex = abs(literal) - 1; // Converti in indice base 0
        bool valore = assegnazioni[varIndex];
        if (literal < 0) valore = !valore; // Negazione
        if (valore) return true; // Clausola soddisfatta
    }
    return false; // Clausola non soddisfatta
}

// Funzione per verificare se la formula è soddisfacibile
bool verificaFormula(int** formula, int* clausoleLength, int numClausole, int numVariabili, bool* assegnazioni) {
    for (int i = 0; i < numClausole; ++i) {
        if (!evalClausola(formula[i], clausoleLength[i], assegnazioni)) {
            return false; // Una clausola non è soddisfatta
        }
    }
    return true; // Tutte le clausole soddisfatte
}

// Funzione per estrarre numeri dalla riga "p cnf numVariabili numClausole"
void parseProblemLine(const char* line, int& numVariabili, int& numClausole) {
    const char* ptr = line;

    // Salta "p" e "cnf"
    while (*ptr && (*ptr == 'p' || *ptr == ' ')) ++ptr;
    while (*ptr && (*ptr != ' ')) ++ptr;
    while (*ptr && (*ptr == ' ')) ++ptr;

    // Leggi il numero delle variabili
    numVariabili = 0;
    while (*ptr && *ptr >= '0' && *ptr <= '9') {
        numVariabili = numVariabili * 10 + (*ptr - '0');
        ++ptr;
    }

    // Salta gli spazi
    while (*ptr && (*ptr == ' ')) ++ptr;

    // Leggi il numero delle clausole
    numClausole = 0;
    while (*ptr && *ptr >= '0' && *ptr <= '9') {
        numClausole = numClausole * 10 + (*ptr - '0');
        ++ptr;
    }
}

int main() {
    ifstream file("formula.cnf");
    if (!file) {
        cerr << "Errore nell'apertura del file." << endl;
        return 1;
    }

    const int MAX_LINE_LENGTH = 256;
    char line[MAX_LINE_LENGTH];
    int numVariabili = 0, numClausole = 0;

    // Variabili per salvare la formula
    int** formula = nullptr;       // Array di puntatori per le clausole
    int* clausoleLength = nullptr; // Array per il numero di letterali per clausola

    while (file.getline(line, MAX_LINE_LENGTH)) {
        if (line[0] == 'c' || line[0] == '\n') continue; // Salta commenti e righe vuote
        if (line[0] == 'p') {
            // Riga del problema
            parseProblemLine(line, numVariabili, numClausole);

            // Allocazione dinamica per la formula
            formula = new int*[numClausole];
            clausoleLength = new int[numClausole];
        } else {
            static int clausolaIdx = 0;
            int count = 0;
            int letterali[256]; // Buffer temporaneo per i letterali
            char* token = line;

            // Parsing manuale dei letterali
            while (*token) {
                int literal = strtol(token, &token, 10); // Converte un numero e aggiorna il puntatore
                if (literal == 0) break; // Fine della clausola
                letterali[count++] = literal;
            }

            // Alloca spazio per la clausola e copia i letterali
            formula[clausolaIdx] = new int[count];
            clausoleLength[clausolaIdx] = count;
            for (int i = 0; i < count; ++i) {
                formula[clausolaIdx][i] = letterali[i];
            }
            ++clausolaIdx;
        }
    }
    file.close();

    // Genera tutte le possibili assegnazioni di valori booleani
    bool* assegnazioni = new bool[numVariabili];
    int totalAssegnazioni = 1 << numVariabili; // 2^numVariabili
    for (int i = 0; i < totalAssegnazioni; ++i) {
        for (int j = 0; j < numVariabili; ++j) {
            assegnazioni[j] = (i & (1 << j)) != 0; // Estrai il bit j-esimo
        }

        // Verifica se questa assegnazione soddisfa la formula
        if (verificaFormula(formula, clausoleLength, numClausole, numVariabili, assegnazioni)) {
            cout << "Formula soddisfacibile con assegnazione: ";
            for (int j = 0; j < numVariabili; ++j) {
                cout << (assegnazioni[j] ? "true" : "false") << " ";
            }
            cout << endl;

            // Dealloca memoria e termina
            delete[] assegnazioni;
            for (int i = 0; i < numClausole; ++i) {
                delete[] formula[i];
            }
            delete[] formula;
            delete[] clausoleLength;

            return 0;
        }
    }

    // Nessuna assegnazione soddisfa la formula
    cout << "Formula non soddisfacibile." << endl;

    // Dealloca memoria
    delete[] assegnazioni;
    for (int i = 0; i < numClausole; ++i) {
        delete[] formula[i];
    }
    delete[] formula;
    delete[] clausoleLength;

    return 0;
}
