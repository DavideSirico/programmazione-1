#include <iostream>
#include <fstream>
using namespace std;


char* estrai(char str[80]);
char* estrai(char str[80], int index, char output[80], int index_output);
int main() {
    char stringa[80];
    cin >> stringa;
    char stringa_output[80];
    cout << estrai(stringa,0, stringa_output,0);
    cout << stringa_output;

    return 0;
}
char* estrai(char str[80], int index, char output[80], int index_output) {
    if(str[index] == '\0') {
        output[index_output] = '\0';
        return '\0';
    }
    if(str[index]>= 'A' && str[index] <= 'Z') {
        output[index_output] = str[index];
        index_output++;
    }
    estrai(str,++index, output, index_output);
}
