#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;


// E' possibile avere delle funzioni di appoggio per la codifica delle parole in numeri e viceversa.
// Ad esempio:
// int encode(char * decoded);
// void decode(int coded, char * decoded);



int main(int argc, char * argv []) {
  
  // inserire qui il codice
  if(argc!=3) {
    cout << "Errore";
    exit(1);
  }
  char *filename_input = argv[1];
  char *filename_output = argv[2];
  fstream in;
  fstream out;
  in.open(filename_input, ios::in);
  out.open(filename_output, ios::out);

  cout << "chiave di criptazione: ";
  int chiave;
  char buffer[10];
  do{
    cin.getline(buffer,10);
    chiave = atoi(buffer);
  }while(strlen(buffer)>7);

  string buffer2;
  while(in>>buffer2) {
    buffer2=buffer2.substr(0,4);
    int codifica = 0;
    for(int i = buffer2.size()-1; i >= 0; i--) {
      int code;
      
      if(buffer2[i]>='0' && buffer2[i]<='9') {
        code = buffer2[i]-'0';
      } else if(buffer2[i]>='a' && buffer2[i]<='z') {
        code = buffer2[i]-'a'+10;
      }
      codifica += code*pow(36,buffer2.size()-1-i);
    }
    codifica = (codifica+chiave);

    char parola[5];
    int index = buffer2.size();
    parola[index] = '\0';
    while(codifica != 0) {
      cout << codifica;
      int ultima_cifra = codifica%36;
      char lettera;
      if(ultima_cifra>=0 && ultima_cifra<=9) {
        lettera = ultima_cifra+'0';
      } else if(ultima_cifra>=10 && ultima_cifra<=36) {
        lettera = (ultima_cifra-10)+'a';
      }
      index--;
      parola[index] = lettera;
      codifica = (codifica-ultima_cifra)/36;
    }
    out << parola << " ";
  }
  in.close();
  out.close();
  return 0;

}
