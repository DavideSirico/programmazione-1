#include <iostream>
#include <fstream>
using namespace std;
/*
Si scriva un programma C++ che:
Prenda come argomenti:
a) un nome di un file che contiene i dati di un paziente secondo la specifica precedente;
b) un intero n che rappresenta il mese che si vuole analizzare;
c) un intero ipo che rappresenta il valore di glicemia sotto il quale si verifica un caso di
ipoglicemia;
d) un intero iper che rappresenta il valore di glicemia sopra il quale si verifica un caso di
iperglicemia.
*/
struct Paziente {
    double peso;
    int eta;
    int **glicemia;
};


int monitora(Paziente *p, int n, int ipo, int iper, int &under_ipo, double &media, double &varianza);
int main(int argc, char *argv[]) {

    if (argc!=5) {
        cout << "Il numero di parametri e' diverso da 4. Errore!";
        return 0;
    }
    char *nome_paziente = argv[1];
    int mese = strtol(argv[2], nullptr, 10) - 1;
    int ipo = strtol(argv[3], nullptr, 10);
    int iper = strtol(argv[4], nullptr, 10);
    if(ipo>iper || mese < 1 || mese > 12 || ipo < 80 || ipo > 95 || iper < 105 || iper > 120) {
        cout << "I valori di ipoglicemia e iperglicemia non sono corretti. Errore!";
        return 0;
    }

    fstream in;
    in.open(nome_paziente, ios::in);

    if(in.fail()) {
        cout << "Il file non esiste. Errore!";
        return 0;
    }

    double peso;
    int eta;
    in >> peso >> eta;

    int **glicemia = new int*[12];

    for(int i= 0; i < 12; i++) {
        glicemia[i] = new int[31];
        for(int j = 0; j < 31; j++) {
            in >> glicemia[i][j];
        }
    }

    struct Paziente p = {peso, eta, glicemia};
    int under_ipo;
    double media;
    double varianza;
    int over_iper = monitora(&p,mese,ipo,iper,under_ipo, media, varianza);

    cout << "Il numero di giorni di iperglicemia e’: " <<  over_iper << endl;
    cout << "il numero di giorni di ipoglicemia e’: " << under_ipo << endl;
    cout << "la media e’: " << media << endl;
    cout << "la varianza e’: " << varianza << endl;
    in.close();
    return 0;
}

int monitora(Paziente *p, int n, int ipo, int iper, int &under_ipo, double &media, double &varianza) {
    int over_iper=0;
    under_ipo = 0;
    media = 0;
    for(int i = 0; i < 31; i++) {
        if(p->glicemia[n][i]>iper) {
            over_iper++;
        }
        if(p->glicemia[n][i]<ipo) {
            under_ipo++;
        }
        media += p->glicemia[n][i];    
    }
    varianza = 0;
    media = media / 31;
    for(int i = 0; i < 31; i++) {
        varianza += (p->glicemia[n][i]*p->glicemia[n][i]) - (media*media);
         
    }
    varianza = varianza/31;
    return over_iper;
}