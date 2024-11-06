#include <iostream>
#include <fstream>
using namespace std;

/*
Realizzare una struttura dati "archivio di studenti" dove gli
studenti siano ordinati sia per cognome sia per numero di
matricola.
*/
struct studente {
    int matricola;
    char nome[100];
    char cognome[100];
};
struct archivio {
    int n_studenti;
    studente *cognome[100];
    studente *matricola[100];
};

void inserisci_studente(archivio &a, const studente &s);
void input_studente(studente &s);
void stampa_archivio_cognome(const archivio &a);
void stampa_archivio_matricola(const archivio &a);
void leggi_archivio(archivio &a, ifstream &read);
void salva_archivio(const archivio &a, ofstream &write);
void sort_cognome(studente *s[], int size);
void sort_matricola(studente *s[], int size);
void swap(studente *& s1, studente *& s2);
void stampa_studente(const studente &s);

int main() {

    archivio a;
    char scelta;
    ifstream read;
    read.open("data.txt", ios::in);

    leggi_archivio(a, read);
    read.close();

    do {
        cout << endl;
        cout << " i: inserisci\n";
        cout << " m: stampa per matricola\n";
        cout << " c: stampa per cognome\n";
        cout << " e: esci\n";
        cout << "\nLeggi Scelta: ";
        cin >> scelta;
        switch (scelta) {
            case 'i': {
                studente *s = new studente;
                input_studente(*s);
                inserisci_studente(a, *s);
                break;
            }  
            case 'm': {
                stampa_archivio_matricola(a);
                break;
            }
            case 'c': {
                stampa_archivio_cognome(a);
                break;
            }
            case 'e': {
                break;
            }
            default: {
                cout << "scelta non capita\n";
            }
        }
    } while(scelta=='i' || scelta=='s' || scelta=='c' || scelta=='m');

    ofstream write;
    write.open("data.txt", ios::out);
    salva_archivio(a, write);
    write.close();
    return 0;
}

void stampa_archivio_cognome(const archivio &a) {
    for(int i = 0; i < a.n_studenti; i++) {
        stampa_studente(*a.cognome[i]);
    }
}

void stampa_archivio_matricola(const archivio &a) {
    for(int i = 0; i < a.n_studenti; i++) {
        stampa_studente(*a.matricola[i]);
    }
}

void leggi_archivio(archivio &a, ifstream &read) {
    int n_studenti;
    read >> n_studenti;
    a.n_studenti = 0;
    for(int i = 0; i < n_studenti; i++) {
        studente *s = new studente;
        read >> s->nome >> s->cognome >> s->matricola;
        inserisci_studente(a, *s);
    }
    sort_cognome(a.cognome,a.n_studenti);
    sort_matricola(a.matricola,a.n_studenti);
}
void salva_archivio(const archivio &a, ofstream &write) {
    write << a.n_studenti << endl;
    for(int i = 0; i < a.n_studenti; i++) {
        studente *p = a.cognome[i];
        write << p->nome << " " << p->cognome << " " << p->matricola << endl;
    }
}

void inserisci_studente(archivio &a, const studente &s) {
    studente *temp;
    temp = new (studente);
    *temp = s;
    a.cognome[a.n_studenti] = temp;
    a.matricola[a.n_studenti] = temp;
    a.n_studenti++;
    sort_cognome(a.cognome, a.n_studenti);
    sort_matricola(a.matricola, a.n_studenti);
}

void sort_cognome(studente *s[], int size) {
    int i, j;
    for (i = size - 1; i > 0; i--)
        for (j = 0; j < i; j++)
        if (strcmp(s[j]->cognome, s[j+1]->cognome) > 0)
            swap(s[j], s[j+1]);
}

void sort_matricola(studente *s[], int size) {
    int i, j;
    for (i = size - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (s[j]->matricola > s[j+1]->matricola)
                swap(s[j], s[j+1]);
}

void swap(studente *& s1, studente *& s2) {
    studente *temp;
    temp = s1;
    s1 = s2;
    s2 = temp;
}

void input_studente(studente &s) {
    cout << "\n Inserisci nome: ";
    cin >> s.nome;
    cout << "\n Inserisci cognome: ";
    cin >> s.cognome;
    cout << "\n Inserisci matricola: ";
    cin >> s.matricola;
}

void stampa_studente(const studente &s) {
    cout << "nome: " << s.nome << endl;
    cout << "cognome: " << s.cognome << endl;
    cout << "matricola: " << s.matricola << endl << endl;
}

