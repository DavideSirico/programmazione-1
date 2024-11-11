#include <iostream>
using namespace std;
/*Scrivere una funzione che ritorni true se un elemento x occorre
nella lista, false se l'elemento non occorre*/
struct node {
    int data;
    node * next;
};

void insert_node(node * x, node *t);
bool trova(node * head, const int x);
int main() {
    node * head = new node;
    for (int i = 0; i < 10; i++) {
        node * t = new node;
        cout << "Inserire un numero: ";
        cin >> t->data;
        t->next = NULL;
        insert_node(head, t);
    }
    for (node *s = head; s != NULL; s=s->next)
        cout << "valore = " << s->data << endl;

    if(trova(head,10)) {
        cout << "trovato";
    } else {
        cout << "non trovato";
    }
    return 0;
}

void insert_node(node * x, node *t) {
    t -> next = x -> next;
    x -> next = t;
}
bool trova(node * head, const int x) {
    if(head == nullptr) {
        return false;
    }
    node *current = head;
    while(current->next != nullptr) {
        if(current->data == x) {
            return true;
        }
        current = current->next;
    }
    return false;
}
