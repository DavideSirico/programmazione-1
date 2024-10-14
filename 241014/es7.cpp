#include <iostream>
#include <bitset>

using namespace std;

/*
Dati in input due interi (short), scrivere un programma che
con una procedura scambi gli 8 bit meno significativi dei
due numeri.
*/
void swap_8bit(short &n1, short &n2);
int main() {
    short n1 = 1855;
    short n2 = 1048;
    swap_8bit(n1,n2);
    cout << n1 << " " << n2;
    return 0;
}
void swap_8bit(short &n1, short &n2) {
    short n1_first_8bit = (n1 >> 8);
    short n2_first_8bit = (n2 >> 8);
    n1_first_8bit = (n1_first_8bit & (65535)) << 8;
    n2_first_8bit = (n2_first_8bit & (65535)) << 8;

    short n1_last_8bit = (n1 << 8);
    short n2_last_8bit = (n2 << 8);
    n1_last_8bit = (n1_last_8bit & (65535)) >> 8;
    n2_last_8bit = (n2_last_8bit & (65535)) >> 8;

    n1 = (n1_first_8bit) ^ (n2_last_8bit);
    n2 = (n2_first_8bit) ^ (n1_last_8bit);
}
