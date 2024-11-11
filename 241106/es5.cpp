#include <iostream>
using namespace std;
/* Scrivere una funzione che sposti l'elemento più piccolo di una lista
  concatenata nel primo nodo della lista.. */

struct node {
    node * next;
    int data;
};

void remove_element(node * &head, int element);
void first_min(node * &head);
void delete_list(node * &s);
void visualizza(node *);
void insert_last(node * &s, int d);
void insert_first(node * &, int);
int main() {
    node *lista = nullptr;
    for(int i = 1; i < 10; i++) {
        insert_first(lista,i);
    }
    visualizza(lista);
    first_min(lista);
    visualizza(lista);
    delete_list(lista);

    return 0;
}

void first_min(node * &head) {
    node *temp = head;
    int min = temp->data;
    while(temp!=nullptr) {
        if(temp->data<min) {
            min=temp->data;
        }
        temp = temp->next;
    }
    remove_element(head,min);
    insert_last(head,min);
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