#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


/*
Scrivere un programma che utilizzi tutte le funzioni definite nei precedenti
esercizi per fornire delle funzionalità molto semplici di database per
memorizzare i dati degli studenti. La dimensione del database è fissata a priori a
100. Il programma dovrà permettere all’utente di eseguire le seguenti azioni:
● Aggiungere un utente al sistema (se si raggiunge la dimensione massima
notificare l’utente);
● Cercare un utente per matricola, nome/cognome e stamparlo a video (se
l’utente non esiste, notificare l’utente);
● Ritornare l’utente con la media ponderata più alta;
● Caricare gli studenti da un file esterno.
*/

const int DIM = 100;

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
        cout << "es4.cpp <filename> <rows>";
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
    int index = N;
    database = carica_studenti(in, N);
    for(int i = 0; i < N; i++) {
        stampa_studente(database[i]);
    }

// ● Aggiungere un utente al sistema (se si raggiunge la dimensione massima
// notificare l’utente);
// ● Cercare un utente per matricola, nome/cognome e stamparlo a video (se
// l’utente non esiste, notificare l’utente);
// ● Ritornare l’utente con la media ponderata più alta;
// ● Caricare gli studenti da un file esterno.
    while(true) {
        char scelta;
        cout << "1) Aggiungere un utente al sistema: " << endl;
        cout << "2) Cerca un utente per matricola " << endl;
        cout << "3) Cerca un utente per nome/cognome " << endl;
        cout << "4) Stampa l'utente con la media ponderata piu' alta " << endl;
        cout << "5) Caricare gli studenti da un file esterno " << endl;
        cout << "Scelta: ";
        cin >> scelta;
        switch(scelta) {
            case '1':
                {
                    char nome[30]; 
                    char cognome[30]; 
                    float media;
                    int matricola;

                    cout << "Nome: ";
                    cin >> nome;
                    cout << "Cogome: ";
                    cin >> cognome;
                    cout << "Media: ";
                    cin >> media;
                    cout << "Matricola: ";
                    cin >> matricola;
                    database[index] = genera_studente(nome, cognome, matricola, media);
                    index++;
                    break;
                }
            case '2':
                {
                    cout << "Inserire matricola: ";
                    int matricola;
                    cin >> matricola;
                    int index_matricola = cerca_matricola(database, matricola, index);
                    if(index_matricola==-1) {
                        cout << "Studente non trovato" << endl;
                    } else {
                        stampa_studente(database[index_matricola]);
                    }
                    break;
                }
            case '3':
                {
                    char nome[30];
                    char cognome[30];
                    cout << "Inserire nome: ";
                    cin >> nome;
                    cout << "Inserire cognome: ";
                    cin >> cognome;
                    int index_matricola = cerca_nome_e_cognome(database, nome, cognome, index);
                    if(index_matricola == -1) {
                        cout << "Studente non trovato" << endl;
                    } else {
                        stampa_studente(database[index_matricola]);
                    }
                    break;
                }
            case '4':
                {
                    int index_media_max = studente_top_media(database, index);
                    if(index_media_max == -1) {
                        cout << "Studente non trovato" << endl;
                    } else {
                        stampa_studente(database[index_media_max]);
                    }
                    break;
                }
            case '5':
                fstream in;
                carica_studenti(in,N);
                in.close();
                break;
        }
    }
    return 0;
}

int studente_top_media(Studente ** database, int N) {
    int index_max = 0;
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
