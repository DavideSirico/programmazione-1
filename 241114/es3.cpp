#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


/*
Modificare il programma scritto precedentemente implementando le funzioni
definite sotto: la funzione cerca_matricola permette di cercare uno studente
tramite il numero di matricola, la funzione cerca_nome_e_cognome permette di
cercare uno studente per nome e cognome, mentre la funzione
studente_top_media ritorna lo studente con la più alta media ponderata. Tutte le
funzioni ritornano l’indice del database corrispondente.
Si può utilizzare la funzione strcmp della libreria cstring.
● int cerca_matricola(Studente ** database, int matricola, int DIM);
● int cerca_nome_e_cognome(Studente ** database, char * nome, char *
cognome, int DIM);
● int studente_top_media(Studente ** database, int DIM);
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
int cerca_matricola(Studente ** database, int matricola, int N);
int cerca_nome_e_cognome(Studente ** database, char * nome, char *cognome, int N);
int studente_top_media(Studente ** database, int N);

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

int studente_top_media(Studente ** database, int N) {
    int index_max = -1;
    float max = database[0]->media;
    for(int i = 1; i < N; i++) {
        if(database[i]->media > max) {
            max = database[i]->media;
            index_max = i;
        }
    }
    return index_max;
}

int cerca_nome_e_cognome(Studente ** database, char * nome, char *cognome, int N) {
    for(int i = 0; i < N; i++) {
        if(strcmp(database[i]->nome, nome)  == 0 && strcmp(database[i]->cognome, cognome) == 0) {
            return i;
        }
    }
    return -1;
}

int cerca_matricola(Studente ** database, int matricola, int N) {
    for(int i = 0; i < N; i++) {
        if(database[i]->matricola == matricola) {
            return i;
        }
    }
    return -1;
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
Studente* genera_studente(char nome[], char cognome[], int matricola, float media_ponderata) {
    Studente *s = new Studente;
    strcpy(s->nome, nome);
    strcpy(s->cognome, cognome);
    s->matricola = matricola;
    s->media = media_ponderata;
    return s;
}
