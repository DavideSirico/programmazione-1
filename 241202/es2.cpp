#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    srand(time(NULL));
    
    const int dim = 100;
    int testo[dim];
    for(int i  = 0; i < dim; i++) {
        testo[i] = rand()%3+1;
    }

    for(int i  = 0; i < dim; i++) {
        cout << testo[i] << " ";
    }
    cout << endl;


    const int dim_pattern = 3;
    int pattern[dim_pattern] = {1,2,3};

    bool trovato = false;
    int i;
    for(i = 0; i <= dim-dim_pattern; i++) {
        int j = 0;
        while(testo[i+j] == pattern[j] && j < dim_pattern) {
            j++;
        }
        if(j==dim_pattern) {
            trovato = true;
            break;
        }
    }

    if(trovato) {
        cout << "sequenza trovata " << i;
    } else {
        cout << "sequenza non trovata";
    }
    return 0;
}
