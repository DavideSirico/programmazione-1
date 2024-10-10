#include <iostream>
#include <cstdlib>
using namespace std;
/*
Scrivere un programma che simuli un attacco 1 contro 1 a RisiKo!. Tirare 1
dado a 6 facce per l’attaccante e 1 dado per il difensore. Dichiarare infine il
numero più alto come il vincitore.
*/

int main() {
    srand(time(NULL));
    int dado_atk = rand() % 6 + 1;
    int dado_def = rand() % 6 + 1;
    if (dado_atk > dado_def) {
        cout << "atk vince";
    } else if(dado_atk < dado_def) {
        cout << "def vince";
    } else {
        cout << "parita";
    }
    return 0;
}


int n_cifre(int n) {
    int cifre = 1;
    while(n>9) {
        n = n/10;
        cifre++;
    }
    return cifre;
} 

int pow(int base, int esponente) {
    int res = 1;
    for(int i = 0; i < esponente; i++) {
        res = res*base;
    }
    return res;
}

void ribalta(int n) {
    int ribaltato = 0;
    int cifre = n_cifre(n)-1;
    while(n>0) {
        ribaltato += (n%10)*pow(10,cifre);
        n = n/10;
        cifre--;
    }
    cout << ribaltato;
}