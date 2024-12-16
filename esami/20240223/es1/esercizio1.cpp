#include <iostream>
#include <fstream>
using namespace std;
// Inserire qui sotto la soluzione all'esercizio

double Percentuale(int superato, int totale);
int main(int argc, char *argv[]) {
    fstream in1;
    fstream in2;

    if(argc < 3) {
        cout << "./es1 <file1> <file2>";
        return 0;
    }
    char *filename1 = argv[1];
    char *filename2 = argv[2];
    
    in1.open(filename1, ios::in);
    in2.open(filename2, ios::in);

    if(in1.fail()) {
        cout << "errore nell'apertura del file" << endl;
        return 0;
    }
    if(in2.fail()) {
        cout << "errore nell'apertura del file" << endl;
        return 0;
    }

    int total = 0;
    int c = 0;
    while(!in1.eof() && !in2.eof()) {
        double temp1;
        double temp2;
        in1 >> temp1;
        in2 >> temp2;
        total++;
        if(temp1<temp2) {
            c++;
        }
    }
    if(total==0) {
        cout << "zero misurazioni";
        return 0;
    }
    cout << Percentuale(c,total);
    in1.close();
    in2.close();


    return 0;
}

double Percentuale(int superato, int totale) {
    return (double)superato/(double)totale*100.0;
}