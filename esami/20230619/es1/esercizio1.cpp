#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;


// è possibile definire proprie funzioni
void right_shift(char v[], int length, int offset);
char to_lower(char c);
void to_lower(char *str);
bool is_letter(char c);
int main(int argc, char * argv []) {

  char buffer[256];
  fstream in;
  in.open(argv[1], ios::in);
  if(in.fail()) {
    exit(1);
  }
  char sequenza[256];
  cout << "sequenza: ";
  cin >> sequenza;
  to_lower(sequenza);
  cout << "Shift: ";
  int r_shift;
  cin >> r_shift;
  right_shift(sequenza, strlen(sequenza), r_shift);
  int occ = 0;
  while(in>>buffer) {
    int i = 0;
    while(i < strlen(buffer)) {
      int j;
      int c = 0;
      for(j = 0; j < strlen(sequenza); j++) {
        if(sequenza[j] == buffer[i+j]) {
          c++;
        }
      }
      if(c == strlen(sequenza)) {
        occ++;
      }
      i++;
    }
  }
  cout << occ;
  in.close();
  return 0;

}



bool is_letter(char c) {
  if((c>='A' && c<='Z') || (c>='a' && c<='z')) {
    return true;
  }
  return false;
}
void right_shift(char v[], int length, int offset) {
  for(int j = 0; j < offset; j++) {
    char temp = v[length-1];
    for(int i=length-1;i>=0;i--)
    {
        v[i+1] = v[i]; //move all element to the right except last one
    }
    v[0] = temp; //assign remembered value to first element
  }
}

char to_lower(char c) {
  if(c>='A' && c<='Z') {
    c = c + 'a'-'A';
  }
  return c;
}
void to_lower(char *str) {
  for(int i = 0; str[i] != '\0'; i++) {
    if(str[i]>='A' && str[i]<='Z') {
      str[i] = str[i] + 'a'-'A';
    }
  }
}