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

void print_clauses(int ** clauses) {
    int max = 0;
    int c = 0;
    for (c = 0; clauses[c] != NULL; c++) {
        for (int j = 0; clauses[c][j] != 0; j++) {
            max = std::max(max, abs(clauses[c][j]));
            std::cout << clauses[c][j] << " ";
        }
        std::cout << "0" << std::endl;
    }
    std::cout << "p cnf " << c << " " << max << std::endl;
}


int main(int argc, char ** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <number>" << std::endl;
        return 1;
    }

    std::ifstream cnffile(argv[1], std::ios::in);
    /*
    x1 OR x2 OR NOT x3
    AND
    NOT x1 OR NOT x2 OR x3
    */

    if (cnffile.fail()) {
        std::cerr << "Error opening file \"" << argv[1] << "\"" << std::endl;
        return 1;
    }

    int nclauses, nvariables;
    char prefix[100];
    char cnf[100];
    // Read p cnf nclauses nvariables
    cnffile >> prefix >> cnf >> nclauses >> nvariables;
    if (strcmp(prefix, "p") != 0 || strcmp(cnf, "cnf") != 0 || 
        nclauses <= 0 || nvariables <= 0) {
        std::cerr << "Error reading header of file \"" << argv[1] << "\"" << std::endl;
        cnffile.close();
        return 1;
    }

    // Allocate memory for the clauses array and terminator!
    int ** clauses = new int * [nclauses+1];

    int i = 0;
    bool error = false;
    // Read the clauses and store them in the clauses array, 
    // if EOF is reached before having read the whole file, error is reported!
    int *clausoleLength = new int[nclauses];
    for (i = 0; !error && i < nclauses && !cnffile.eof(); i++) {
        int n;
        // Read the number of literals in the clause
        cnffile >> n;
        clausoleLength[i] = n;
        clauses[i] = new int[n + 1];
        // Read the literals
        for (int j = 0; j < n; j++) {
            cnffile >> clauses[i][j];
            // If EOF is reached or a literal is greater 
            // than nvariables, or the literal is 0, error and stop reading
            if (cnffile.eof() || std::abs(clauses[i][j]) > nvariables ||
                clauses[i][j] == 0) {
                error = true;
                break;
            }
        }
        // If no error, add the terminator 0 to the clause
        if (!error) {
            clauses[i][n] = 0;
        }
    }
    {
        char c;
        cnffile >> c;
        if (!cnffile.eof()) {
            error = true;
        }
    }

    cnffile.close();

    // The number of read clauses must be equal to nclauses, otherwise error
    if (i != nclauses || error) {
        std::cerr << "Error reading file \"" << argv[1] << "\": eof or clause out of bound, or 0 encountered, or more clauses encountered" << std::endl;
        for (int j = 0; j < i; j++) {
            delete [] clauses[j];
        }
        delete [] clauses;
        return 1;
    }
    clauses[i] = NULL;

    // Now we have the clauses in the clauses array, we print it
    print_clauses(clauses);


    // Genera tutte le possibili assegnazioni di valori booleani
    bool* assegnazioni = new bool[nvariables];
    int totalAssegnazioni = 1 << nvariables; // 2^numVariabili
    for (int i = 0; i < totalAssegnazioni; ++i) {
        for (int j = 0; j < nvariables; ++j) {
            assegnazioni[j] = (i & (1 << j)) != 0; // Estrai il bit j-esimo
        }

        // Verifica se questa assegnazione soddisfa la formula
        if (verificaFormula(clauses, clausoleLength, nclauses, nvariables, assegnazioni)) {
            cout << "Formula soddisfacibile con assegnazione: ";
            for (int j = 0; j < nvariables; ++j) {
                cout << (assegnazioni[j] ? "true" : "false") << " ";
            }
            cout << endl;

            // Dealloca memoria e termina
            for(int i = 0; i < nclauses && clauses[i] != NULL; i++) {
                delete [] clauses[i];
            }
            delete [] clauses;
            delete[] assegnazioni;
            delete[] clausoleLength;
            return 0;
        }
    }

    // Nessuna assegnazione soddisfa la formula
    cout << "Formula non soddisfacibile." << endl;

    // Dealloca memoria
    for(int i = 0; i < nclauses && clauses[i] != NULL; i++) {
        delete [] clauses[i];
    }
    delete [] clauses;
    delete[] assegnazioni;
    delete[] clausoleLength;

    return 0;
}
