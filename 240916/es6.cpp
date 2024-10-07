#include <iostream>
using namespace std;

int main() {
    char carattere_maiuscolo;
    do {
        cout << "Carattere (Maiuscolo): ";
        cin >> carattere_maiuscolo;
    } while(!(carattere_maiuscolo>='A' && carattere_maiuscolo<='Z'));
    
    char carattere_minuscolo = carattere_maiuscolo+('a'-'A');

    cout << "Carattere (Minuscolo): " << carattere_minuscolo;


    return 0;
}