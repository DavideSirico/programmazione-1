#include <iostream>
using namespace std;
/*
Scrivere una funzione che cancella un elemento x da una lista
doppiamente concatenata s.
*/


struct node {
    node * next;
    node * prev;
    int data;
};

void free_list(node * &head);
void visualizza(node *);
void insert_last(node * &head, int element);
void insert_first(node * &head, int element);
void delete_element(node * &head, int element);
int main() {
    node *lista = new node;
    lista->data = 0;
    lista->prev = nullptr;
    lista->next = nullptr;
    for(int i = 1; i < 10; i++) {
        insert_last(lista, i);
    }
    visualizza(lista);
    delete_element(lista, 4);
    visualizza(lista);
    free_list(lista);
    
    return 0;
}

void delete_element(node * &head, int element) {
    if(head == nullptr) {
        return;
    }

    // If the head node holds the value to be deleted
    node *copia = head;
    if (copia->data == element) {
        head = copia->next;  // Move head to the next node
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete copia;
        return;
    }
    while(copia != nullptr && copia->data != element) {
        copia = copia->next;
    }
    if (copia == nullptr) {
        return;
    }
    if (copia->next != nullptr) {
        copia->next->prev = copia->prev;
    }
    if (copia->prev != nullptr) {
        copia->prev->next = copia->next;
    }

    delete copia;
}

void insert_first(node * &head, int element) {
    node *temp = new node;
    temp->data = element;

    temp->next = head;
    if(head!=nullptr) {
        head->prev = temp;
    }
    head = temp;
}

void insert_last(node * &head, int element) {
    node *temp = new node;
    temp->data = element;
    if (head == nullptr) {
        head = temp;
        return;
    }

    node *list = head;

    while(list->next!=nullptr) {
        list = list->next;
    }
    temp->prev = list;
    list->next = temp;
}

void free_list(node * &head) {
    while(head != NULL) {
        node * temp = head;
        head = head->next;
        delete temp;
    }
}

void visualizza(node *l){
    for(node *s=l; s!=nullptr;s=s->next)
        cout << s->data <<" ";
    cout << endl;
}