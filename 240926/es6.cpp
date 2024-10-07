#include <iostream>
#include <cmath>
using namespace std;

/*
L’area di un triangolo di cui sono noti i lati a, b e c può essere calcolata,
utilizzando la formula di Erone, come:
𝑝(𝑝 − 𝑎)(𝑝 − 𝑏)(𝑝 − 𝑐) dove 𝑝 = (𝑎 + 𝑏 + 𝑐)/2
Si scriva un programma in linguaggio C++ che chieda all’utente di immettere
da tastiera le lunghezze dei lati a, b e c (tre numeri reali positivi), calcoli
l’area A e ne stampi il valore a video. Per il calcolo della radice quadrata si
può usare la funzione di libreria sqrt, disponibile in <cmath>.
Per fare di più: verificate che a,b,c siano effettivamente positivi e che il
triangolo non sia degenere
*/

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    float p = (a+b+c)/2.0F;
    float area = sqrt(p*(p - a)*(p - b)*(p - c));
    cout << "area: " << area;

    return 0;
}