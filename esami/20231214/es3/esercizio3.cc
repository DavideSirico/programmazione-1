#include <iostream>

using namespace std;

bool* init(int n);
void deinit(bool * b);
void insert(bool * b, int n, char * array);
bool check(bool * b, int n, char *array);
int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
    int n = 255;

    bool* bloom_filter = init(n);

    char ciao[] = { 'c', 'i', 'a', 'o', '\0' };     
    insert(bloom_filter, n, ciao);
    cout << "Ho inserito la parola 'ciao' nel bloom filter" << endl;
    
    if (check(bloom_filter, n, ciao)) {
        cout << "La parola 'ciao' è presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'ciao' NON è presente nel bloom filter " << endl;
    }

    char volo[] = { 'v', 'o', 'l', 'o', '\0' }; 
    if (check(bloom_filter, n, volo)) {
        cout << "La parola 'volo' è presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'volo' NON è presente nel bloom filter " << endl;
    }

    deinit(bloom_filter);

    return 0;
}

bool* init(int n) {
    bool * bloom = new bool[n];
    for(int i = 0; i < n; i++) {
        bloom[i] = false;
    }
    return bloom;
}

void insert(bool * b, int n, char * array) {
    for(int i = 0; array[i] != '\0'; i++) {
        int index = array[i];
        if(index >= n) {
            index = index % n;
        }
        b[index] = true;
    }
}
bool check(bool * b, int n, char *array) {
    for(int i = 0; array[i] != '\0'; i++) {
        int index = array[i];
        if(index >= n) {
            index = index % n;
        }
        if(b[index] == false) {
            return false;
        }
    }
    return true;
}
void deinit(bool * b) {
    delete[] b;
}