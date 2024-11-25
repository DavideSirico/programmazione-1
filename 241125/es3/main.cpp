#include <iostream>
#include <cstring>
#include "coda.h"

using namespace std;
/*
Scrivere un programma che simuli l'arrivo e lo smaltimento di una coda
all'ufficio postale. Gli elementi della coda sono i nomi delle persone. Il
main sarà un menù con tre opzioni: (1) aggiungi persona, (2) smaltisci
persona, (3) stampa situazione corrente.
Non sono ammessi omonimi nella coda.
Potete usare la funzione strcmp della libreria <cstring>
*/

bool omonimo(char *nome);
int main() {
    char scelta;
    init();

    enqueue("prova1");
    enqueue("prova2");
    enqueue("prova3");
    enqueue("prova4");
    
    print();
    print();

    /*
    do {
        cout << "1) aggiungi persona;" << endl << "2) smaltisci persona" << endl << "3) stampa situazione corrente" << endl;
        cout << "scelta: ";
        cin >> scelta;
        switch(scelta) {
            case '1':
                cout << "nome persona: ";
                char nome[256];
                cin >> nome;
                if(!omonimo(nome)) {
                    enqueue(nome);
                }
                break;

            case '2':
                dequeue();
                break;
            
            case '3':
                print();
                break;
        }
    } while(scelta!='q');
    */
    deinit();
    return 0;
}
