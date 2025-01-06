// Allowed include 
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>

// Add your code hereafter
using namespace std;

struct Paziente {
    double peso;
    int eta;
    int glicemia[12][31];
};
int Monitora(struct Paziente p, int mese, int ipo, int iper, int &ipo_c, double& media, double &varianza);
int main(int argc, char *argv[]) {
    if(argc != 5) {
        cout << "Il numero di parametri e’ diverso da 4. Errore!";
        exit(1);
    }
    fstream in(argv[1], ios::in);
    int mese = atoi(argv[2]);
    int ipo = atoi(argv[3]);
    int iper = atoi(argv[4]);
    if(ipo>iper || ipo<80 || ipo>95 || iper<105 || iper>120 || mese<1 || mese>12) {
        cout << "I valori di ipoglicemia e iperglicemia non sono corretti. Errore!";
        exit(1);
    }
    mese = mese-1;

    if(in.fail()) {
        cout << "Il file non esiste. Errore!";
        exit(1);
    }
    struct Paziente p;
    in>>p.peso>>p.eta;
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 31; j++) {
            in >> p.glicemia[i][j];
        }
    }
    int ipo_c;
    double media;
    double varianza;
    int iper_c = Monitora(p,mese,ipo,iper,ipo_c,media,varianza);
    cout << "Il numero di giorni di iperglicemia e’: " << iper_c << endl;
    cout << "il numero di giorni di ipoglicemia e’: " << ipo_c << endl;
    cout << "la media e’: " << media << endl;
    cout << "la varianza e’: " << varianza << endl;
    return 0;
}

int Monitora(struct Paziente p, int mese, int ipo, int iper, int &ipo_c, double& media, double &varianza) {
    int iper_c = 0;
    media = 0;
    ipo_c = 0;
    varianza = 0;
    for(int j = 0; j < 31; j++) {
        if(p.glicemia[mese][j]>iper) {
            iper_c++;
        }
        if(p.glicemia[mese][j]<ipo) {
            ipo_c++;
        }
        media += p.glicemia[mese][j];
    }
    media = media / 31;
    for(int j = 0; j < 31; j++) {
        varianza += pow(p.glicemia[mese][j]-media,2);
    }
    varianza = varianza/31;
    return iper_c;
}
