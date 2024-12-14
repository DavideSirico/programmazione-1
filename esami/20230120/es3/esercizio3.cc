#include <iostream>
#include "pila.h"

using namespace std;

int * collidiAsteroidi(int asteroidi[], int numeroAsteroidi, int & numeroAsteroidiRimasti);

int main() {
    
    // Potete modificare l'array di asteroidi (e la sua
    // dimensione) per testare la vostra soluzione
    int asteroidi [] = {11, -5, -12, 4, -6};
    int numeroAsteroidi = 5;


    int numeroAsteroidiRimasti;
    int * asteroidiRimasti = collidiAsteroidi(asteroidi, numeroAsteroidi, numeroAsteroidiRimasti);


    // La stampa dell'array dinamico degli
    // asteroidi rimasti avviene nel main
    for (int i = 0; i < numeroAsteroidiRimasti ; i++) {
        cout << asteroidiRimasti[i] << " ";
    }
    cout << endl;

    // La deallocazione dell'array dinamico 
    // degli asteroidi rimasti avviene nel main
    delete[] asteroidiRimasti;
}


// Implementare la funzione sottostante come da consegna:
// - ritornare un'array di interi allocato dinamicamente che 
//   contenga lo stato degli asteroidi dopo tutte le collisioni
// - assegnare a 'numeroAsteroidiRimasti' il numero di elementi 
//   nell'array ritornato
int * collidiAsteroidi(int asteroidi[], int numeroAsteroidi, int & numeroAsteroidiRimasti) {
    // init();
    init();
    numeroAsteroidiRimasti = numeroAsteroidi;
    int asteroidePila;

    for (int i = 0; i < numeroAsteroidi; i++) {
        int current = asteroidi[i];
        // se positivo
        if (current > 0 || vuota()) {
            push(current);
        } else {
            current = -current;
            top(asteroidePila);

            while(!vuota() && asteroidePila > 0 && asteroidePila < current) {
                numeroAsteroidiRimasti--;
                pop();
                top(asteroidePila);
            }

            if (!vuota() && asteroidePila == current) {
                pop();
                numeroAsteroidiRimasti -= 2;
            } else {
                if (vuota() || asteroidePila < 0) {
                    push(-current);
                } else {
                    numeroAsteroidiRimasti--;
                }
            }
        }
    }
    int *rimasti = new int[numeroAsteroidiRimasti];
    int index = numeroAsteroidiRimasti;
    while(!vuota()) {
        index--;
        int temp;
        top(temp);
        rimasti[index] = temp;
        pop();
    }

    deinit();
    return rimasti;
}
