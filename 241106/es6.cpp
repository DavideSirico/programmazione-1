#include <iostream>
using namespace std;
/*
Scrivere una funzione che costruisca la lista risultante dalla
  concatenazione di due liste x e y.
  - Diverse soluzioni sono possibili:
    . Side effects sulla lista destinazione.
    . Nuova lista.
*/

struct node {
    node * next;
    int data;
};

node * concat(node * lista1, node * lista2);
void remove_element(node * &head, int element);
void delete_list(node * &s);
void visualizza(node *);
void insert_last(node * &s, int d);
void insert_first(node * &, int);
node * copia(node *head);
int main() {
    node *lista1 = nullptr;
    node *lista2 = nullptr;
    for(int i = 1; i < 10; i++) {
        insert_first(lista1,i);
    }
    for(int i = 1; i < 10; i++) {
        insert_last(lista2,i);
    }
    visualizza(lista1);
    visualizza(lista2);
    node *lista3 = concat(lista1,lista2);
    visualizza(lista1);
    visualizza(lista2);
    visualizza(lista3);
    delete_list(lista1);
    delete_list(lista2);
    delete_list(lista3);

    return 0;
}

node * concat(node * lista1, node * lista2) {
    node *lista_concat = copia(lista1);
    while(lista2!=nullptr) {
        insert_last(lista_concat,lista2->data);
        lista2=lista2->next;
    }
    return lista_concat;
}

node * copia(node *head) {
    node *lista_copia = new node;
    lista_copia->data = head->data;

    for(node *s=head->next; s!=nullptr;s=s->next) {
        insert_last(lista_copia,s->data);
    }
    return lista_copia;
}

void delete_list(node * & s) {
  while(s != NULL) {
    node * t = s;
    s = s->next;
    delete t;
  }
}

void visualizza(node *l){
    for(node *s=l; s!=nullptr;s=s->next)
        cout << s->data <<" ";
    cout << endl;
}

void insert_first(node * &n, int element) {
  node * temp = new node;
  temp->data = element;
  temp->next = n;
  n = temp;
}

void insert_last(node * &head, int element) {
    node *temp = new node;
    temp->data = element;
    temp->next = nullptr;

    if(head == nullptr) {
        head = temp;
    } else {
        node * temp_head = head;
        while(temp_head->next!=nullptr) {
            temp_head = temp_head->next;
        }
        temp_head->next = temp;
    }
}

void remove_element(node * &head, int element) {
    if (head != NULL) {
        node *q = head;
        if (q->data == element) {
            head = head->next;
            delete q;
        } else {
            while(q->next != NULL) {
                if (q->next->data == element) {
                    node *r = q->next;
                    q->next = q->next->next;
                    delete r;
                    return;
                }
                if (q->next != NULL) {
                    q=q->next;
                }
            }
        }
    }
}