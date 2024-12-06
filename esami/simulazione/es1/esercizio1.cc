#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char * argv [])
{
  if(argc != 3) {
    cout << "./es1 <input> <output>";
    exit(1);
  }

  fstream in;
  fstream out;

  in.open(argv[1], ios::in);
  out.open(argv[2], ios::out);

  if(in.fail() || out.fail()) {
    cout << "Errore nell'apertura del file";
    in.close();
    out.close();
    exit(1);

  }
  char buffer;
  bool to_upper = true;
  while(in.get(buffer)) {
    if(to_upper) {
      if(buffer>='a' && buffer<='z') {
        buffer = buffer - ('a' - 'A');
      }
      to_upper = false;
    }
    if(buffer == '.' || buffer == '!' || buffer == '?') {
      to_upper = true;
    }
    out << buffer;
  }
  in.close();
    out.close();
  return 0;
}
