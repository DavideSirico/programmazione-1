#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

/* Scrivere un programma che, dato un file in input da linea di comando
contenente diverse temperature. Il file è costituito da una sola colonna
e le temperature sono rappresentate come numeri reali. Il programma
salvi queste temperature in un array dinamico e stampi a video le
prime N temperature più alte. Il valore N viene specificato dall’utente
da linea di comando. Il programma accetta anche un intero M che
indica quante temperature al massimo sono presenti nel file. */

void sort_array(double *array, int size);
int main(int argc, char *argv[]) {
    srand(time(NULL));
    if(argc<3) {
        cout << "parametri insufficienti";
        return 0;
    }
    int m = 100;
    if(argc==4) {
        m = atoi(argv[3]);
    }
    char *file_name = argv[1];
    int n = atoi(argv[2]);

    ifstream in;
    in.open(file_name, ios::in);
    if(in.fail()) {
        cout << "errore nell'apertura del file";
        in.close();
        return 0;
    }
    double *temperature = new double[m];
    int size = 0;
    while(!in.eof() && size < m) {
        in >> temperature[size];
        size++;
    }
    sort_array(temperature, size);
    for(int i = 0; i < size && i < n; i++) {
        cout << temperature[i] << " ";
    }
    cout << endl;
    in.close();
    delete[] temperature;

    return 0;
}



void sort_array(double *array, int size) {
    for(int i = 0; i < size-1; i++) {
        for(int j = i+1; j < size; j++) {
            if(array[i] < array[j])
                swap(array[i], array[j]);
        }
    }
}
