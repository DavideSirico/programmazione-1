#include <iostream>
#include <fstream>
using namespace std;

// Realizzare una rubrica telefonica.
const int NmaxChar = 1000;
const int NmaxPers = 100;

struct indirizzo {
  char via[NmaxChar];
  int civico;
  char comune[NmaxChar];
  int cap;
  char prov[3];
};

struct persona {
    char nome[NmaxChar];
    char cognome[NmaxChar];
    char numero_telefono[11];
    indirizzo indirizzo;
};

struct rubrica {
    int n_persone;
    persona * persone[NmaxPers];
};

void leggi_rubrica(rubrica &rubrica, ifstream &read);
void salva_rubrica(const rubrica &rubrica, ofstream &write);
void inserisci_persona_rubrica(rubrica &rubrica, const persona &persona);
void input_persona(persona &persona);
void stampa_persona(const persona &persona);
void stampa_rubrica(const rubrica &rubrica);
void stampa_indirizzo(const indirizzo &indirizzo);
int main() {
    rubrica rubrica;
    char scelta;
    ifstream read;
    read.open("data.txt", ios::in);

    leggi_rubrica(rubrica, read);
    read.close();

    do {
        cout << endl;
        cout << " i: inserisci\n";
        cout << " s: stampa\n";
        cout << " e: esci\n";
        cout << "\nLeggi Scelta: ";
        cin >> scelta;
        switch (scelta) {
            case 'i': {
                persona *p = new persona;
                input_persona(*p);
                inserisci_persona_rubrica(rubrica, *p);
                break;
            }  
            case 's': {
                stampa_rubrica(rubrica);
                break;
            }
            case 'e': {
                break;
            }
            default: {
                cout << "scelta non capita\n";
            }
        }
    } while((scelta=='i' || scelta=='s'));

    ofstream write;
    write.open("data.txt", ios::out);
    salva_rubrica(rubrica, write);
    write.close();
    return 0;
}

void leggi_rubrica(rubrica &rubrica, ifstream &read) {
    int n_persone;
    read >> n_persone;
    rubrica.n_persone = 0;
    for(int i = 0; i < n_persone; i++) {
        persona *p = new persona;
        read >> p->nome >> p->cognome;
        indirizzo *ind = new indirizzo;
        read >> ind->via >> ind->civico >> ind->comune >> ind->cap >> ind->prov;
        p->indirizzo = *ind;
        inserisci_persona_rubrica(rubrica, *p);
    }
}
void salva_rubrica(const rubrica &rubrica, ofstream &write) {
    write << rubrica.n_persone << endl;
    for(int i = 0; i < rubrica.n_persone; i++) {
        persona *p = rubrica.persone[i];
        write << p->nome << " " << p->cognome << " ";
        indirizzo ind = p->indirizzo;
        write << " " << ind.via << " " << ind.civico << " " << ind.comune << " " << ind.cap << " " << ind.prov << endl;
    }
}

void inserisci_persona_rubrica(rubrica &rubrica, const persona &p) {
    persona *temp = new persona;
    *temp = p;
    rubrica.persone[rubrica.n_persone] = temp;
    rubrica.n_persone++;
}

void input_persona(persona &persona) {
    cout << "\n Inserisci nome: ";
    cin >> persona.nome;
    cout << "\n Inserisci cognome: ";
    cin >> persona.cognome;
    indirizzo *i = new indirizzo;
    cout << "\n Inserisci via: ";
    cin >> i->via;
    cout << "\n Inserisci civico: ";
    cin >> i->civico;
    cout << "\n Inserisci comune: ";
    cin >> i->comune;
    cout << "\n Inserisci cap: ";
    cin >> i->cap;
    cout << "\n Inserisci prov: ";
    cin >> i->prov;
    persona.indirizzo = *i;
}

void stampa_persona(const persona &persona) {
    cout << "nome: " << persona.nome << endl;
    cout << "cognome: " << persona.cognome << endl;
    cout << "numero di telefono: " << persona.numero_telefono << endl;
    stampa_indirizzo(persona.indirizzo);

}
void stampa_indirizzo(const indirizzo &indirizzo) {
    cout << "Via: " << indirizzo.via << endl;
    cout << "Civico: " << indirizzo.civico << endl;
    cout << "Comune: " << indirizzo.comune << endl;
    cout << "cap: " << indirizzo.cap << endl;
    cout << "prov: " << indirizzo.prov << endl;
    cout << endl;
}
void stampa_rubrica(const rubrica &rubrica) {
    for(int i = 0; i < rubrica.n_persone; i++) {
        stampa_persona(*rubrica.persone[i]);
    }
}