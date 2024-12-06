#include <iostream>


/* Inserire qui sotto la dichiarazione della funzione extract */
char * extract(const char *str);
/* Inserire qui sopra la dichiarazione della funzione extract */

/* Solo di esempio, non fate assunzioni su questo valore */
const int DIM = 255;

int main(int argc, char ** argv) {
  char input_string[DIM+1];
  char * extracted;
  char answer;

  do {
    std::cout << "Inserire la stringa da controllare: ";
    std::cin >> input_string;

    extracted = extract(input_string);
    std::cout << "La stringa estratta e': " << extracted << std::endl;

    delete [] extracted;
    std::cout << "Si vuole inserire un'altra stringa? [*/n]";
    std::cin >> answer;
  } while (answer != '\0' && answer != 'N' && answer != 'n');
  return 0;
}


int extract_aux(const char *str, int index, int& lunghezza) {
  if(str[index] == '\0') {
    return 0;
  }
  if(str[index] == '@') {
    lunghezza = lunghezza+1;
  }
  extract_aux(str,index+1,lunghezza);
}
char * generate_string(int n, int index, char *string) {
  if(index==n) {
    return string;
  }
  string[index]='@';
  return generate_string(n,index+1,string);
}
/* Inserire qui sotto la definizione della funzione estract */
char * extract(const char *str) {
  int lunghezza = 0;
  extract_aux(str,0,lunghezza);
  char *ris = new char[lunghezza];
  return generate_string(lunghezza, 0, ris);
}
/* Inserire qui sopra la definizione della funzione estract */
