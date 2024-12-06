#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cassert>

const int fprecision = 5;

struct list {
  int info;
  struct list * next;
};

void delete_list(list * & l) {
  while(l != NULL) {
    list * t = l;
    l = l->next;
    delete t;
  }
}

void print_list(list * l) {
  std::cout << "The list of terms is: ";
  while(l != NULL) {
    std::cout << l->info << ((l->next != NULL) ? " " : "");
    l = l->next;
  }
  std::cout << std::endl;
}

// Aggiungere qui sotto la dichiarazione della funzione da
// implementare
list * crea_lista_aux(list * lista, unsigned int N, int index);
list * crea_lista(unsigned int N);

// Aggiungere qui sopra la dichiarazione della funzione da
// implementare


int main(int argc, char **argv) {
  int N;

  if (argc == 2) {
    N = atoi(argv[1]);
  } else {
    std::cerr << "Usage: " << argv[0] << " N ]" << std::endl;
    std::cerr << "N is an integer > 0" << std::endl;
    exit(1);
  }

  std::cout << "N = " << N << std::endl;
  list * result = crea_lista(N);
  print_list(result);
  delete_list(result);
  return 0;
}

// Aggiungere qui sotto la definizione della funzione da
// implementare

list * crea_lista(unsigned int N) {
  list *lista = new list;
  return crea_lista_aux(lista, N, 0);
  
}

list * crea_lista_aux(list * lista, unsigned int N, int index) {
  if(index == N-1) {
    lista->info = (index*(index+1))/2;
    return lista;
  }
  list *nodo = new list;
  nodo->info = (index*(index+1))/2;
  nodo->next=lista->next;
  lista->next = nodo;
  crea_lista_aux(lista, N, ++index);
  return lista;
}
// Aggiungere qui sopra la definizione della funzione da
// implementare
