#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;


// è possibile definire funzioni di supporto


int main(int argc, char * argv []) {
  
  // inserire qui il codice
  char buffer[256];
  fstream in;
  in.open(argv[1], ios::in);

  if(in.fail()) {
    exit(1);
  }
  char pattern[256];
  cout << "pattern da cercare: ";
  cin >> pattern;
  int pattern_lenght = strlen(pattern);
  while(in >> buffer) {
    bool valid = true;
    for(int i = 0; i < pattern_lenght; i++) {
      if(buffer[i] == '\0') {
        valid = false;
      }
      if(!(pattern[i] == '*' || pattern[i] == buffer[i])) {
        valid = false;        
      }
    }
    if(valid) {
      cout << buffer << endl;
    }
  }

  in.close();
  return 0;

}
