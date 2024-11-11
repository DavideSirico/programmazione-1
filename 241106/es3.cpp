#include <iostream>
using namespace std;
/* Scrivere una funzione che costruisca una copia di una data lista
(cioe', una nuova lista che contiene le stesse informazioni nello
stesso ordine). */

struct node {
    node * next;
    int data;
};

void insert_last(node * s, int d);
node * copia(node *head);
void visualizza(node *);
void insertNode(node *, int);
int main() {
    node *lista = new node;
    lista->data=1;
    lista->next=nullptr;
    for(int i = 2; i < 10; i++) {
        insert_last(lista,i);
    }
    node *lista_copia = copia(lista);
    visualizza(lista);
    visualizza(lista_copia);
    delete lista;
    delete lista_copia;
    return 0;
}

node * copia(node *head) {
    node *lista_copia = new node;
    lista_copia->data = head->data;

    for(node *s=head->next; s!=nullptr;s=s->next) {
        insert_last(lista_copia,s->data);
    }
    return lista_copia;
}

void visualizza(node *l){
    for(node *s=l; s!=nullptr;s=s->next)
        cout << s->data <<" ";
    cout << endl;
}

void insertNode(node *l, int element){
    node *temp = new node;
    temp->data=element;
    temp->next=l->next;
    l->next=temp;
}

void insert_last(node *head, int element) {
    node *temp = new node;
    while(head->next!=nullptr) {
        head = head->next;
    }
    temp->data = element;
    temp->next = nullptr;
    head->next = temp;
}