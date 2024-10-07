#include <iostream>
using namespace std;
/*
Scrivere un programma che stampi a video il valore ASCII
di tutte le lettere dell’alfabeto minuscole e maiuscole.
*/
int main()
{
    for (int i = 0; i < int('z'-'a'); i++) {
        cout << char('a'+i) << " ";
    }
    cout << endl;
    for (int i = 0; i < int('Z'-'A'); i++) {
        cout << char('A'+i) << " ";
    }
    return 0;
}