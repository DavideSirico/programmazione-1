#include <iostream>
#include <cstdlib>
using namespace std;

/* Scrivere un programma che, dato in input dall’utente da riga di
comando un numero intero N, ritorni a video una lista di N
numeri interi generati randomicamente nell’intervallo 0-99.
Questi numeri devono essere salvati in un array. Questo array
deve essere generato dinamicamente da una funzione con la
firma uguale a quella mostrata sopra. */

int * generate_numbers(int N);
int main(int argc, char *argv[]) {
    srand(time(NULL));
    int n;
    if(argc==2) {
        n = atoi(argv[1]);
        int *array = generate_numbers(n);
        for(int i = 0; i < n; i++) {
            cout << array[i] << " ";
        }
        delete array;

    }

    return 0;
}

int * generate_numbers(int N) { 
    int * array = new int[N];
    for(int i = 0; i < N; i++) {
        array[i] = rand()%100;
    }
    return array;
}