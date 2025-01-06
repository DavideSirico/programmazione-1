#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;


// è possibile definire proprie funzioni
void left_shift(char v[], int length, int offset, int start_index, int end_index);
char to_lower(char c);
bool is_letter(char c);
int main(int argc, char * argv []) {
  
  // inserire qui il codice
  char buffer[256];
  fstream in;
  fstream out;
  in.open(argv[1], ios::in);
  out.open(argv[2], ios::out);
  if(in.fail() || out.fail()) {
    exit(1);
  }
  cout << "Shift: ";
  int l_shift;
  cin >> l_shift;
  while(in>>buffer) {
    int word_shift = l_shift;
    int start_index = 0;
    int end_index = strlen(buffer);
    while(buffer[start_index] != '\0' && !is_letter(buffer[start_index])) {
      start_index++;
    }
    while(end_index>=0 && !is_letter(buffer[end_index-1])) {
      end_index--;
    }

    left_shift(buffer, strlen(buffer), word_shift, start_index, end_index);    

    for(int i = 0; buffer[i] != '\0'; i++) {
      buffer[i] = to_lower(buffer[i]);
    }
    cout << buffer << " ";
  }
  in.close();
  out.close();
  return 0;

}

bool is_letter(char c) {
  if((c>='A' && c<='Z') || (c>='a' && c<='z')) {
    return true;
  }
  return false;
}
void left_shift(char v[], int length, int offset, int start_index, int end_index) {
  for(int j = 0; j < offset; j++) {
    char temp=v[start_index];
    for (int i = start_index; i < end_index - 1; i++)		
    {
      v[i] = v[i + 1];
    }
    v[end_index-1]=temp;
  }
}

char to_lower(char c) {
  if(c>='A' && c<='Z') {
    c = c + 'a'-'A';
  }
  return c;
}