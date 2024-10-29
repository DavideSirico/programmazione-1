#include <iostream>
using namespace std;
/*
Si scriva in linguaggio C++ la funzione ricorsiva capitale_maturato che riceva in ingresso (ovvero
come parametro) l’ammontare α del capitale inizialmente investito (un numero reale), il numero n di
mesi trascorsi (un numero intero), la percentuale di rendimento mensile γ (un numero reale) e
l’ammontare σ delle spese di gestione (un numero reale), calcoli e restituisca come valore di ritorno il
capitale maturato dopo n mesi (un numero reale), applicando la formula sopra riportata

Si scriva, quindi, un programma C++ che chieda all’utente di inserire da tastiera il numero k di mesi
corrispondenti alla durata di un investimento, verifichi che k sia maggiore o uguale a 6 (durata
minima dell’investimento) e chiami la funzione ricorsiva capitale_maturato passando k come
parametro attuale per il numero di mesi n e i seguenti valori per gli altri parametri: 25000.00 per alpha,
0.0015 per gamma e 1.0 per sigma. Il programma stampa a video il valore di ritorno della funzione,
ovvero il capitale maturato dopo n mesi, avendo investito 25000.00 Euro con un tasso di rendimento
mensile dello 0.15% e costi mensili di gestione pari a 1.0 Euro. Nel caso in cui l’utente immetta un
numero minore di 6, il programma stampa a video un messaggio di errore e termina.
Esempio: se l'utente inserisce il valore k = 36, il programma stampa a video 26349.1, cioè dopo 36
mesi il capitale passa da 25000 Euro a 26349.10 Euro.
*/
double capitale_maturato(double capitale, int mesi, double rendimento, double gestione);
int main() {
    int k;
    cin >> k;
    cout << "Inserire durata investimento: ";
    if(k < 6) {
        cout << "numero di mesi troppo piccolo";
        return 0;
    }
    cout << capitale_maturato(25000.00, k, 0.0015, 1.0);
    return 0;
}

double capitale_maturato(double capitale, int mesi, double rendimento, double gestione) {
    if(mesi == 0) {
        return capitale;
    }
    return ((1+(rendimento))*capitale_maturato(capitale, mesi-1, rendimento, gestione)-gestione);
}