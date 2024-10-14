#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;

/*
Scrivere un programma che simuli un attacco 3 contro 3 a RisiKo!. Tirare 3 dadi
a 6 facce per l’attaccante e 3 per il difensore. Confrontare il dado più alto
dell’attaccante contro il più alto del difensore, il medio dell’attaccante contro il
medio del difensore e il più basso dell’attaccante contro il più basso del
difensore. Dichiarare infine gli scontri vinti dall’attaccante e dal difensore.
*/



void sort(int array[], int size);
void swap(int &a, int &b);
int main() {
    srand(time(NULL));
    int dadi_attk[3];
    for(int i = 0; i < 3; i++) {
        dadi_attk[i] = (rand() % 6 + 1);
    }
    sort(dadi_attk, 3);

    int dadi_def[3];
    for(int i = 0; i < 3; i++) {
        dadi_def[i] = (rand() % 6 + 1);
    }
    sort(dadi_def, 3);
    int vittore_attk = 0;
    int vittore_def = 0;
    for(int i = 0; i < 3; i++) {
        if(dadi_def[i] > dadi_attk[i]) {
            vittore_def++;
        } else {
            vittore_attk++;
        }
    }
    cout << "Vittore attacco: " << vittore_attk << endl;
    cout << "Vittore difesa: " << vittore_def;

    return 0;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void sort(int array[], int size) {
    for(int i = 0; i < size-1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(array[i] > array[j]) {
                swap(array[i], array[j]);
            }
        }
    }
}