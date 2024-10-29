#include <iostream>
using namespace std;

/*
Il rompicapo consiste di tre pali A, B, C e un numero n di dischi forati
di diametro diverso. Inizialmente, tutti i dischi sono impilati sul palo
A. Scopo del gioco è reimpilare tutti i dischi sul palo C.
Regole:
• Si può spostare un disco per volta;
• Nessun disco può avere sopra di sé dischi di diametro più grande
• I dischi non possono essere «parcheggiati» fuori dai pali
*/
void torre_di_hanoi(int numero_dischi, char p, char a, char s);
int main() {
    torre_di_hanoi(3, '1', '2', '3');
    return 0;
}
/*
Il problema generale consiste nello spostare n dischi da una torre ad un’altra, usando la terza
torre come parcheggio temporaneo. Per spostare n dischi da una torre all’altra supponiamo di
saper spostare n-1 dischi da una torre all’altra.
Il caso base si ha quando n = 1. Se n=1, possiamo spostare liberamente il disco da una torre
ad un’altra.
Procedura per spostare n dischi dalla torre A alla torre C:
• Passo 1: gli n-1 dischi in cima alla torre A vengono spostati sulla torre B, usando la torre C
come parcheggio temporaneo (si usa una chiamata ricorsiva, al termine della quale la torre
C è vuota)
• Passo 2: il disco rimasto nella torre A viene portato nella torre C
• Passo 3: gli n-1 dischi in cima alla torre B vengono spostati nella torre C, usando la torre A
come parcheggio temporaneo (si usa una chiamata ricorsiva, al termine della quale la torre
A è vuota)
*/
void torre_di_hanoi(int numero_dischi, char p, char a, char s) {
    if(numero_dischi == 1) {
        cout << "sposto il disco da " << p << " a " << a << endl; 
    } else {
        torre_di_hanoi(numero_dischi-1, p, s, a);
        cout << "Sposta il disco da " << p << " a " << a << endl;
        torre_di_hanoi(numero_dischi-1, s, a, p);
    }
    return;
}
