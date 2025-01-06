#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

void print_clauses(int ** clauses);
int main(int argc, char **argv) {
    if(argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <number>" << std::endl;
        return 1;
    }

    std::ifstream in;
    in.open(argv[1], std::ios::in);
    if(in.fail()) {
        std::cerr << "Error opening file \"" << argv[1] << "\"" << std::endl;
        return 1;
    }
    char buffer1[256];
    char buffer2[256];
    int n_clausole;
    int n_variabili;
    in >> buffer1 >> buffer2 >> n_clausole >> n_variabili;
    if(n_clausole<=0 || n_variabili<=0 || strcmp(buffer1, "p") != 0 || strcmp(buffer2, "cnf") != 0) {
        std::cerr << "Error reading header of file \"" << argv[1] << "\"" << std::endl;
        in.close();
        return 1;
    } 

    int **clausole = new int*[n_clausole+1];
    int i = 0;
    bool error = false;
    for(i = 0; !error && i < n_clausole && !in.eof(); i++) {
        int n;
        in >> n;
        clausole[i] = new int[n+1];
        for (int j = 0; j < n; j++) {
            in >> clausole[i][j];
            if (in.eof() || std::abs(clausole[i][j]) > n_variabili || clausole[i][j] == 0) {
                error = true;
                break;
            }
        }
        if(!error) {
            clausole[i][n] = 0;
        }
    }
    // se ci sono altri caratteri rimasti
    {
        char c;
        in >> c;
        if (!in.eof()) {
            error = true;
        }
    }
    in.close();

    if (i != n_clausole || error) {
        std::cerr << "Error reading file \"" << argv[1] << "\": eof or clause out of bound, or 0 encountered, or more clauses encountered" << std::endl;
        for (int j = 0; j < i; j++) {
            delete [] clausole[j];
        }
        delete [] clausole;
        return 1;
    }
    clausole[i] = nullptr;

    print_clauses(clausole);

    for(int i = 0; i < n_clausole && clausole[i] != nullptr; i++) {
        delete [] clausole[i];
    }
    delete [] clausole;
    
    return 0;
}

void print_clauses(int ** clauses) {
    int max = 0;
    int c = 0;
    for (c = 0; clauses[c] != nullptr; c++) {
        for (int j = 0; clauses[c][j] != 0; j++) {
            max = std::max(max, abs(clauses[c][j]));
            std::cout << clauses[c][j] << " ";
        }
        std::cout << "0" << std::endl;
    }
    std::cout << "p cnf " << c << " " << max << std::endl;
}