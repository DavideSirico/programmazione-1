#include <iostream>

// Includere qui la libreria da usare, i.e. stack.h o queue.h a
// seconda della richiesta
#include "stack.h"
// #include "queue.h"

#define MAXSIZE 20

struct list {
  int node;
  struct list * next;
};

bool ** genera(const int N) {
  bool ** result = new bool * [N];
  for (int i = 0; i < N; i++) {
    result[i] = new bool[N]();
    for (int j = 0; j < N; j++) {
      result[i][j] = (bool)(rand()%2);
    }
  }
  return result;
}

void dealloca(bool * * & r, int N) {
  for(int i = 0; i < N; i++) {
    delete [] r[i];
  }
  delete [] r;
  r = NULL;
}

void print(bool ** G, int N) {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      std::cout << G[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void print(list * l) {
  std::cout << "Lista: ";
  while(l!=NULL) {
    std::cout << l->node << ((l->next != NULL) ? " " : "");
    l = l->next;
  }
  std::cout << std::endl;
}

void dealloca(list * l) {
  while(l!=NULL) {
    list * t = l;
    l=l->next;
    delete t;
  }
}

// Inserire qui sotto la dichiarazione di visita
list* visit(bool **m, int N, int i);

// Inserire qui sopra la dichiarazione di visita


int main(int argc, char * argv[]) {
  unsigned s = unsigned(time(0));
  srand(s);
		//
		// Commentare la linea seguente per avere comportamento
		// non-deterministico
		//
		srand(1688544644);
  int N = rand()%MAXSIZE;
  bool **G = genera(N);
  int i = rand()%N;
  std::cout << "Grafo G["<< N << "][" << N << "]" << std::endl;
  print(G, N);
  list * res = visit(G,N,i);
  print(res);
  dealloca(G,N);
  dealloca(res);
}

// Inserire qui sotto la definizione di visita
void insert_first(list * &s, int d) {
  // Creo il nuovo nodo e memorizzo il valore utilizzando costruttore
  // ad un solo argomento
  list * n = new list;
  n->node = d;
  // Il campo next di n punta a s
  n->next = s;
  // s punt a nuovo nodo n
  s = n;
}

list* visit(bool **A, int N, int i) {
  bool *visited = new bool[N];
  for(int i = 0; i < N; i++) {
    visited[i] = false;
  }
  list * result = NULL;
  Stack *s = init();
  push(s, i);
  while(!isEmpty(s)) {
    int element = pop(s);
    if(!visited[element]) {
      visited[element] = true;
      insert_first(result, element);
      for (int j = 0; j < N; j++) {
        if (A[element][j] && !visited[j]) {
          push(s,j);
        }
      }
    }
  }
  delete[] visited;
  quit(s);
  return result;
}
// Inserire qui sopra la definizione di visita
