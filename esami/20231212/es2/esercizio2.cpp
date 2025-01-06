#include <iostream>


/* Inserire qui sotto la dichiarazione della funzione extract */
char* extract(const char * stringa);
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

/* Inserire qui sotto la definizione della funzione estract */
int extract_aux(const char * stringa, int index) {
  if(stringa[index] == '\0') {
    return 0;
  }
  if(stringa[index] == '@') {
    return 1+extract_aux(stringa, index+1);
  }
  return extract_aux(stringa,index+1);
}
void create(char* stringa, int index, int lenght) {
  if(index == lenght-1) {
    stringa[index] = '\0';
    return;
  }
  stringa[index] = '@';
  create(stringa, index+1, lenght);
}
char* extract(const char * stringa) {
  int lenght = extract_aux(stringa, 0)+1;
  char *output = new char[lenght];
  create(output, 0, lenght);
  return output;
}
/* Inserire qui sopra la definizione della funzione estract */
