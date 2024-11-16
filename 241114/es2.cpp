#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


/*
Utilizzando le funzioni scritte precedentemente, scrivere un programma
che, dato in input un file contenente i dati di alcuni studenti e il numero di
righe del file, generi un array dinamico che contenga tutti questi studenti. E’
consigliato raggruppare questa logica all’interno di una funzione separata.
Utilizzare la libreria fstream.
Studente **database = new Studente*[N];
*/

struct Studente {
    int matricola;
    float media;
    char nome[30];
    char cognome[30];
};

void stampa_studente(Studente * S);
Studente* genera_studente(char nome[], char cognome[], int matricola, float media_ponderata);
Studente** carica_studenti(fstream &input, int rows);

int main(int argc, char *argv[]) {
    if(argc < 3) {
        cout << "es2.cpp <filename> <rows>";
        return 0;
    }
    char *filename = argv[1];
    int N = atoi(argv[2]);
    fstream in;
    in.open(filename, ios::in);
    if(in.fail()) {
        cout << "Errore apertura file";
        return 0;
    }
    Studente **database;
    database = carica_studenti(in, N);
    for(int i = 0; i < N; i++) {
        stampa_studente(database[i]);
    }
    return 0;
}


Studente** carica_studenti(fstream &input, int rows) {
    Studente **database = new Studente*[rows];
    int i = 0;
    while(!input.eof() && i < rows) {
        char nome[30];
        char cognome[30];
        int matricola;
        float media;
        input >> nome >> cognome >> matricola >> media;
        database[i] = genera_studente(nome, cognome, matricola, media);
        i++;
    }
    return database;
}


void stampa_studente(Studente * S) {
    cout << "Nome: " << S->nome << endl;
    cout << "Cognome: " << S->cognome << endl;
    cout << "Matricola: " << S->matricola << endl;
    cout << "Media: " << S->media << endl;
    cout << "==============================" << endl;

}
Studente* genera_studente(char *nome, char *cognome, int matricola, float media_ponderata) {
    Studente *s = new Studente;
    strncpy(s->nome, nome, sizeof(s->nome) - 1);
    s->nome[sizeof(s->nome) - 1] = '\0';
    strncpy(s->cognome, cognome, sizeof(s->cognome) - 1);
    s->cognome[sizeof(s->cognome) - 1] = '\0';

    s->matricola = matricola;
    s->media = media_ponderata;
    return s;
}
