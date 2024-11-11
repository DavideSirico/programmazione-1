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

node* precede(node* head, node* t, node* x);
void insert_node(node * x, node *t);
int main () {
    node * x = new node;
    cout << "Inserire numero: ";
    cin >> x->data;
    x->next = NULL;
    for (int i = 0; i < 10; i++) {
        node * t = new node;
        cout << "Inserire un numero: ";
        cin >> t->data;
        t->next = NULL;
        insert_node(x, t);
    }
    for (node *s = x; s != NULL; s=s->next)
        cout << "valore = " << s->data << endl;

    node* t = x->next;
    node* result = precede(x, t, x);
    if (result != nullptr) {
        cout << "t precedes x" << endl;
    } else {
        cout << "t does not precede x" << endl;
    }
}

void insert_node(node * x, node *t) {
    t -> next = x -> next;
    x -> next = t;
}

void insert_node(node * nodo, int x) {
    
}

node* precede(node* head, node* t, node* x) {
    if (head == nullptr || head == x) {
        return x;
    }

    node* current = head;
    while(current!=nullptr) {
        if(current->next == t && current->next->next == x) {
            return t;
        }
        current = current->next;
    }

    return nullptr; // t does not precede x
}