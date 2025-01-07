#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// Inserire la dichiarazione qui sotto

int generaKmer(int k);
// Inserire la dichiarazione qui sopra

int main(int argc, char * argv[]) {
  if (argc != 2) {
    cout << "Formato accettato: " << argv[0] << " <numero_positivo> " << endl;
    exit(1);
  }
  int k = atoi(argv[1]);
  if (k <= 0) {
    cout << "Formato accettato: " << argv[0] << " <numero_positivo> " << endl;
  }
  cout << "Start" << endl;
  int count = generaKmer(k);
  cout << "Numero di k-mer generati: " << count << endl;
  cout << "Finish!" << endl;
  return 0;
}

// Inserire la definizione qui sotto
char next_char(char k) {
  switch(k) {
    case 'A':
      return 'C';
    case 'C':
      return 'G';
    case 'G':
      return 'T';
    case 'T':
      return 'A';
  }
}
int generaKmer(int k) {
  int i;
  char *str = new char[k+1];
  for(i = 0; i < k; i++) {
    str[i] = 'A';
  }
  str[i] = '\0';
  char *str_last = new char[k+1];
  for(i = 0; i < k; i++) {
    str_last[i] = 'T';
  }
  str_last[i] = '\0';
  int counter = 1;
  while (strcmp(str, str_last) != 0) {
    counter ++;
    // You can uncomment the next line to see all k-mers.
    cout << str << endl;
    for (int i=0; i<k; i++) {
      if (str[i] == 'T') {
	      str[i] = next_char(str[i]);
      }
      else {
	      str[i] = next_char(str[i]);
	      break;
      }
    }
  }

  delete[] str;
  delete[] str_last;
  return counter;
}
// Inserire la definizione qui sopra
