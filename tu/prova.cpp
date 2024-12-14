#include <iostream>
#include <cstdlib>

struct List {
  int v;
  List * next;
};

void calcola(List * & result, int in[], int n) {
  result = nullptr;
  for(int j = 0; j < n; j++) {
    List * nl  = new List;
    nl->v = in[j];
    // (*nl).v = in[j];
    nl->next = result;
    result = nl;
  }
  //r = result;
}

int main () {
  int in[10] = {1, 2, 3, 4, 5, 6, 7, 8};

  List * l;

  for(int i = 0; i < 10 ; i++) std::cout << in[i] << " ";
  std::cout << std::endl;

  calcola(l, in, 10);

  while(l != nullptr) {
    List * t = l;
    std::cout << l->v <<  " " << std::endl;
    l = l->next;
    delete t;
  }
}
