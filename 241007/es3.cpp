#include <iostream>
using namespace std;
/*
Scrivere un programma che stampi a video i caratteri
compresi tra un intervallo di valori ASCII (quindi, interi)
a e b definito dall’utente in input.
Controllare anche che l’intervallo inserito dall’utente
sia valido (a < b, a >= 0, b <= 127), altrimenti
terminare il programma. 
*/
int main()
{
    cout << "Inserire un intervallo: ";
    int a,b;
    cin >> a >> b;
    if (a>=b || a<0 || b > 127) {
        return -1;
    }

    for(int i = a; i < b; i++) {
        cout << char(i) << " ";
    }
    return 0;
}