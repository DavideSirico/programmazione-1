#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

char to_upper(char c);
int main(int argc, char * argv []) {
  fstream input;
  fstream output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  if(input.fail() || output.fail()) {
    cout << "Errore nell'apertura del file";
    exit(1);
  }

  char buffer;
  bool next_capital = true;
  while(input >> buffer) {
    if(next_capital) {
      next_capital = false;
      buffer = to_upper(buffer);
    }
    if(buffer == '.' || buffer == '\n' || buffer == '!' || buffer == '?') {
      next_capital = true;
    }
    output << buffer;
  }

  input.close();
  output.close();
  return 0;
}

char to_upper(char c) {
  if(c>='a' && c<='z') {
    return (c-('a'-'A'));
  }
  return c;
}