#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

/*
Si scriva la funzione append che concateni due array di numeri interi ordinati in senso
crescente. La funzione riceve come parametri i puntatori a due array di numeri interi pa e
pb e le loro dimensioni na e nb (due numeri interi) e restituisce come valore di ritorno il
puntatore a un array di numeri interi. Si suppone che gli array puntati da pa e pb siano
già ordinati in senso crescente. La funzione allocherà dinamicamente un array di (na +
nb) elementi e vi copierà gli elementi degli array puntati da pa e pb in modo tale che
l’array risultante sia a sua volta ordinato in senso crescente. La funzione restituirà infine il
puntatore all’array risultante. Sarà responsabilità del programma chiamante deallocare la
memoria allocata dalla funzione.
Si scriva quindi un programma C++ per verificare il corretto funzionamento della
funzione. Il programma chiederà all’utente di immettere da tastiera le dimensioni nx e ny
di due array di numeri interi, allocherà dinamicamente gli array e chiederà all’utente di
inserire i valori per entrambi gli array. Il programma utilizzerà quindi l’algoritmo
BubbleSort per ordinare entrambi gli array, chiamerà la funzione append e stamperà a
video l’array concatenato risultante.
*/

int * append(int *pa, int *pb, int na, int nb);
void print_array(int *array, int lenght);
void sort_array(int *array, int lenght);
int main() {
    srand(time(NULL));
    int na, nb;
    cout << "Dimensione primo array: ";
    cin >> na;
    cout << "Dimensione secondo array: ";
    cin >> nb;
    
    int *pa = new int[na];
    int *pb = new int[nb];
    cout << "Inserire gli elementi del primo array: ";
    for(int i = 0; i < na; i++) {
        cin >> pa[i];
    }
    cout << "Inserire gli elementi del secondo array: ";
    for(int i = 0; i < nb; i++) {
        cin >> pb[i];
    }

    sort_array(pa,na);
    sort_array(pb,nb);

    int *ris = append(pa,pb,na,nb);

    print_array(ris,na+nb);

    delete[] pa;
    delete[] pb;
    delete[] ris;
    return 0;
}

int * append(int *pa, int *pb, int na, int nb) {
    int index1 = 0;
    int index2 = 0;
    int *ris = new int[na+nb];
    int i = 0;
    while(index1<na && index2<nb) {
        if(index1<index2) {
            ris[i] = pa[index1];
            index1++;
        } else {
            ris[i] = pb[index2];
            index2++;
        }
        i++;
    }
    while(index1<na) {
        ris[i] = pa[index1];
        i++;
        index1++;
    }
    while(index2<nb) {
        ris[i] = pb[index2];
        i++;
        index2++;
    }
    return ris;
}

void print_array(int *array, int lenght) {
    for(int i = 0; i < lenght; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void sort_array(int *array, int length) {
    for(int i=0; i<length-1; i++) {
        for (int j=0; j<length-1; j++) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+i]);
            }
        }
    }
}
