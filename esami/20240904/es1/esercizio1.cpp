#include <iostream>
#include <cmath>
using namespace std;

// Funzione per valutare una clausola in AND
bool evaluateAND(const int clause[], int clauseSize, const bool assignment[], int numVariables) {
    for (int i = 0; i < clauseSize; ++i) {
        int var = clause[i];
        bool value = assignment[abs(var) - 1]; // Valore della variabile (indice base 0)
        if ((var > 0 && !value) || (var < 0 && value)) {
            return false; // Condizione per cui la clausola AND è falsa
        }
    }
    return true; // Tutti i termini sono veri
}

// Funzione per valutare la formula in OR tra clausole AND
bool evaluateFormula(const int formula[][10], const int clauseSizes[], int numClauses, const bool assignment[], int numVariables) {
    for (int i = 0; i < numClauses; ++i) {
        if (evaluateAND(formula[i], clauseSizes[i], assignment, numVariables)) {
            return true; // Una clausola vera rende la formula vera
        }
    }
    return false; // Nessuna clausola vera
}

// Funzione per generare tutti gli assegnamenti di verità
bool isValidFormula(const int formula[][10], const int clauseSizes[], int numClauses, int numVariables) {
    int totalAssignments = 1 << numVariables; // 2^numVariables
    bool assignment[10]; // Massimo 10 variabili booleane

    for (int i = 0; i < totalAssignments; ++i) {
        for (int j = 0; j < numVariables; ++j) {
            assignment[j] = (i & (1 << j)) != 0; // Genera assegnamenti di verità
        }
        if (!evaluateFormula(formula, clauseSizes, numClauses, assignment, numVariables)) {
            return false; // Un assegnamento rende la formula falsa
        }
    }
    return true; // Tutti gli assegnamenti rendono la formula vera
}

int main() {
    int formula[1][10] = {{1, 1}}; // Clausola: x1 AND x1
    int clauseSizes[1] = {2}; // Una clausola, con 2 variabili
    int numClauses = 1; // Una clausola
    int numVariables = 1; // Una variabile booleana

    if (isValidFormula(formula, clauseSizes, numClauses, numVariables)) {
        cout << "La formula è una tautologia (sempre vera)." << endl;
    } else {
        cout << "La formula NON è una tautologia." << endl;
    }

    return 0;
}
