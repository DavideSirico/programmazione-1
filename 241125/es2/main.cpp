#include <iostream>
#include "pila.h"
using namespace std;

/*
scrivere un programma che legge una sequenza di caratteri in input
dall’utente e determina se le parentesi sono “bilanciate”:
*/

int main() {
    pila_init();

    char parentesi[256];
    cout << "Inserire stringa: ";
    cin >> parentesi;

    bool bilanciate = false;

    for(int i = 0; parentesi[i] != '\0'; i++) {
        char ch = parentesi[i];

        if (ch == '(') {
            pila_push((int)ch);

        } else if (ch == ')') {
            int t;
            if (!pila_top(t)) {
                cout << "sbilanciato";
                break;
            }

            int top;
            pila_top(top);
            pila_pop();

            // Verifichiamo che sia un match valido
            if ((ch == ')' && (char)top != '(')) {
                cout << "sbilanciato";
                break;
            }
        }
    }
    if(!pila_pop()) {
        cout << "bilanciato";
    } else {
        cout << "sbinaciato";
    }
    pila_deinit();

    return 0;
}

