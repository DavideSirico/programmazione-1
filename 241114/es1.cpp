#include <iostream>
#include <cstring>
using namespace std;


/*
Scrivere un programma che definisca una struttura chiamata
Studente formata dai campi nome (array di 30 caratteri),
cognome (array di 30 caratteri), matricola (int) e media (float)
ponderata dei voti. Implementare poi le funzioni definite in basso: la
funzione stampa_studente stampa a video il contenuto di una
struttura Studente, mentre la funzione genera_studente genera una
struttura Studente dati in input il valore dei suoi campi.
Si può utilizzare la funzione strcpy della libreria cstring.
void stampa_studente (Studente * S);
Studente* genera_studente (char nome[], char cognome[], int
matricola, float media_ponderata );
*/


struct Studente {
    int matricola;
    float media;
    char nome[30];
    char cognome[30];
};

void stampa_studente(Studente * S);
Studente* genera_studente(char nome[], char cognome[], int matricola, float media_ponderata);


int main() {
    cout << "ciao mondo! ";
    int i = 0;
    cout << i;
    return 0;
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
