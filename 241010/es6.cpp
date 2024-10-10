#include <iostream>
#include <cstdlib>
using namespace std;
/*
Scrivere un programma che simuli un attacco 2 contro 2 a RisiKo!. Tirare 2
dadi a 6 facce per l’attaccante e 2 dadi per il difensore. Confrontare il dado
più alto dell’attaccante contro il più alto del difensore, e il più basso
dell’attaccante contro il più basso del difensore. Dichiarare infine gli
scontri vinti dall’attaccante e quelli vinti dal difensore.
*/
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    srand(time(NULL));
    int dadi_attk[2];
    int lancio1 = (rand() % 6 + 1);
    int lancio2 = (rand() % 6 + 1);
    dadi_attk[0] =  max(lancio1, lancio2);
    dadi_attk[1] =  min(lancio1, lancio2);

    int dadi_def[2];
    lancio1 = (rand() % 6 + 1);
    lancio2 = (rand() % 6 + 1);
    dadi_def[0] =  max(lancio1, lancio2);
    dadi_def[1] =  min(lancio1, lancio2);

    int vittore_attk = 0;
    int vittore_def = 0;
    if(dadi_def[0] > dadi_attk[0]) {
        vittore_def++;
    } else {
        vittore_attk++;
    }
    if(dadi_def[1] > dadi_attk[1]) {
        vittore_def++;
    } else {
        vittore_attk++;
    }
    cout << "Vittore attacco: " << vittore_attk << endl;
    cout << "Vittore difesa: " << vittore_def;

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