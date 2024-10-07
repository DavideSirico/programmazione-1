#include <iostream>
using namespace std;
/*
Scrivere un programma che, dato in input un numero
dall’utente, ritorni a video se questo numero possa essere
espresso come la somma di due numeri primi.
Stampare anche i corrispondenti numeri primi a video.
*/

void find_primes(int numero, int *addendo1, int *addendo2);
bool is_prime(int n);
int biggest_prime(int n);


int main() {
    cout << "Inserire un numero: ";
    int numero;
    cin >> numero;
    int addendo1, addendo2;
    find_primes(numero, &addendo1, &addendo2);
    if(addendo1 != -1 && addendo2 != -1) {
        cout << addendo1 << "+" << addendo2; 
    } else {
        cout << "Somma impossibile";
    }

    return 0;
}

void find_primes(int numero, int *addendo1, int *addendo2) {
    *addendo1 = numero-2;
    *addendo1 = biggest_prime(*addendo1);
    *addendo2 = numero - *addendo1;
    while(!is_prime(*addendo2)) {
        *addendo1 = biggest_prime(--(*addendo1));
        if(*addendo1 == -1) {
            break;
        }
        *addendo2 = numero - *addendo1;
    }
}

int biggest_prime(int n) {
    int res;
    for(int i = n; i > 1;i--) {
        if (is_prime(i)) {
            res = i;
            return res;
        }
    }
    return -1;
}


bool is_prime(int n) {
    for(int i = 2; i <= (n/2); i++) {
        if(n%i == 0) {
            return false;
        }
    }
    return true;
}