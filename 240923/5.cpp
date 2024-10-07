#include <iostream>
using namespace std;

/*(recap) dato in input un carattere maiuscolo, ritorna lo
stesso carattere minuscolo… e viceversa SENZA costrutti
condizionali
VARIANTE: risolvere il problema SENZA usare espressioni
booleane (nessun operatore), o l’operatore ternario
SUPERSFIDA: implementare anche il controllo dell’input
sotto gli stessi vincoli*/

int main() {
    char carattere;

    cin >> carattere;

    int is_char = ((carattere > 'a')&(carattere < 'z')) | ((carattere > 'A')&(carattere < 'Z')) ;

    char carattere_trasformato = (carattere ^ 32) * is_char;

    cout << carattere_trasformato;

    return 0;
}