#include <iostream>
using namespace std;

/*
Scrivere una funzione che determini se l'oggetto t precede un
dato oggetto x
- Se x primo elemento ritornare x stesso.
*/
struct node {
    int data;
    node *next;
};

void insert_node(node * x, node *t);
void insert_node(node * x, const int i);
int main () {
    node * x = new node;
    cout << "Inserire numero testa: ";
    cin >> x->data;
    x->next = NULL;
    for (int i = 0; i < 10; i++) {
        insert_node(x, i);
    }
    for (node *s = x; s != NULL; s=s->next)
        cout << "valore = " << s->data << endl;

}

void insert_node(node * x, node *t) {
    t -> next = x -> next;
    x -> next = t;
}

void insert_node(node * nodo, const int x) {
    node * temp = new node;
    temp->data = x;
    temp->next=nodo->next;
    nodo->next=temp;
}