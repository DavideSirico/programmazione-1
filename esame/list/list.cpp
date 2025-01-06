#include <iostream>

using namespace std;

// Struttura lista di interi
struct nodo {
  int dato;
  nodo * next;
};


// Calcolo della lunghezza di una lista ricorsiva
int length(nodo * s) {
    if (s == NULL) return 0;
    return 1 + length(s->next);
}

// Dealloca la memoria della lista
void delete_list(nodo * & s) {
  // Alla fine la lista e' vuota. Passaggio per riferimento.
  while(s != NULL) {
    // Salvo il valore del nodo corrente
    nodo * t = s;
    // Avanzo al nodo sucessivo
    s = s->next;
    // Dealloco il nodo salvato
    delete t;
  }
}

// Stampa contenuto della lista
void stampa(nodo * s) {
  int i = 0;
  while(s != NULL) {
    cout << s->dato << " ";
    s = s->next;
  }
}

void insert_first(nodo * &s, int d) {
  // Creo il nuovo nodo e memorizzo il valore utilizzando costruttore
  // ad un solo argomento
  nodo * n = new nodo;
  n->dato = d;
  // Il campo next di n punta a s
  n->next = s;
  // s punt a nuovo nodo n
  s = n;
}

nodo* insert_last(nodo * & s, int d) {
    if (s->next == NULL) {  
        nodo *temp = new nodo;        
        temp->next = NULL;
        temp->dato = d;
        s->next= temp;
        return temp;
    }  
    return insert_last(s->next, d);
}

void insert_order(nodo * & s, int d) {
    if (s == NULL || s->dato > d) {
        insert_first(s, d);
    }
    else {
        insert_order(s->next, d);
    }
}

void remove_first(nodo * & s) {
  if (s != NULL) {
    nodo * t = s;
    s = s->next;
    delete t;
  }
}

nodo * remove_last(nodo * & s) {
    if (s == nullptr) {
        return nullptr; // If the list is empty, return nullptr
    }

    if (s->next == nullptr) {
        // If there is only one node
        nodo *temp = s;
        s = nullptr;
        delete temp; // Free the memory of the last node
        return nullptr;
    }

    // Recursively remove the last node
    return remove_last(s->next);
}


// Rimuove l'elemento in posizione index ricorsiva
void remove_element_index(nodo * & s, int index) {
    if (index == 0) {
        remove_first(s);
    }
    else {
        if (s != NULL) {
            remove_element_index(s->next, index-1);
        }
    }
}

// Rimuove l'elemento d dalla lista
void remove_element(nodo * & p, int d) {
  if (p != NULL) {
    if (p->dato == d) {
      nodo * t = p;
      p = p->next;
      delete t;
      remove_element(p, d);
    }
    else {
      remove_element(p->next, d);
    }
  }
}
// recursive reverse
void reverse(nodo * & s) {
    if (s == NULL || s->next == NULL) return;
    nodo *rest = s->next;
    reverse(rest);
    s->next->next = s;
    s->next = NULL;
    s = rest;
}

// recursive
int get_n(nodo * s, int n) {
    if (n < 0) return NULL;
    if (n == 0) return s->dato;
    if (s == NULL) return NULL;
    return get_n(s->next, n-1);
}

// recursive left_shift
void left_shift(nodo * & s) {
    int temp = s->dato;
    remove_first(s);
    insert_last(s, temp);
}

void right_shift(nodo * & s) {
    int temp = get_n(s, length(s)-2);
    remove_last(s);
    insert_first(s, temp);
}



nodo * prec(nodo * s, nodo * x) {
  // primo ed unico elemento uguale a x
  if (s == x) return x;
  // primo e unico elemento e' differente da x
  if ((s == NULL) && (s->next == NULL)) return NULL;

  nodo * t = s; // nodo precedente al nodo corrente che sto cercando,
		// inizializzato al primo elemento della lista
  nodo * l = s->next; // nodo che uso per scorrere la lista,
		      // inizializzato al secondo elemento della
		      // lista.

  while((l != NULL) && (l != x)) {
    // Modifico l e t per rispettare il loro significato, ovvero che t
    // punta l nodo che precede l
    t = l;
    l = l->next;
  }
  // raggiunto ultimo elemento e non c'e' nulla
  if (l == NULL) return NULL;
  return t;
}

nodo  * concat_se_ricorsiva(nodo  * s1, nodo  * s2) {
  if (s1 == NULL) return s2;
  s1->next = concat_se_ricorsiva(s1->next, s2);
  return s1;
}

nodo  * copy_seq(nodo  * s) {
  if (s == NULL) return NULL;
  nodo * t = new nodo;
  t->dato = s->dato;
  t->next = copy_seq(s->next);
  return t;
}

int occorrenze(nodo * s, int d) {
    if (s == NULL) return 0;
    if (s->dato == d) return 1 + occorrenze(s->next, d);
    return occorrenze(s->next, d);
}

nodo * remove_duplicates(nodo * s) {
    if (s == NULL) return NULL;
    if (s->next == NULL) return s;
    if (s->dato == s->next->dato) {
        nodo *temp = s->next;
        s->next = s->next->next;
        delete temp;
        return remove_duplicates(s);
    }
    return remove_duplicates(s->next);
}

void remove_at(nodo *& head, int n) {
  if (head == nullptr) {
    return;
  }
  if (n < 0) {
    return;
  }
  if (n == 0) {
    nodo * temp = head;
    head = head->next;
    delete temp;
    return;
  }
  remove_at(head->next, n - 1);
}

void insert_at(nodo *& head, int value, int n) {
    if (n < 0) {
        return;
    }
    if (n == 0) {
        nodo * new_node = new nodo;
        new_node->dato = value;
        new_node->next = head;
        head = new_node;
        return;
    }
    if (head == nullptr) {
        return;
    }
    insert_at(head->next, value, n - 1);
}

int main() {
  nodo * L1 = NULL;
  srand(time(NULL));
  for(int i = 0; i < 10; i++) {
    int d = rand()%10;
    insert_order(L1, d);
    // insert_first(L1, d);
  }
  cout << "La lista L1 creata e':" << endl;
  stampa(L1);
  cout << endl;
  remove_duplicates(L1);
  stampa(L1);

  delete_list(L1);
}
