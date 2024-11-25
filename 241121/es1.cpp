#include <iostream>
#include <fstream>
using namespace std;

/*
Scrivere un programma che, dato in input un file con un intero per
riga, crea una lista concatenata con i numeri contenuti nel file
*/

struct node {
    int value;
    node *next;
};

void primizzaLista(node * &head);
void stampaListaInvertita(node *listaDiNumeri);
void distruggiLista(node *&listaDiNumeri);
void stampaLista(node *listaDiNumeri);
bool isPrime(const int value);
int main() {
    fstream in;

    char filename [255];
    cout << "Nome del file: ";
    cin >> filename;
    in.open(filename, ios::in);
    if(in.fail()) {
        cout << "Errore nell'apertura del file";
        return 0;
    }
    node *head = new node;
    int value;
    in >> value;
    head->value = value;
    head->next = nullptr;
    while(!in.eof()) {
        node *temp = new node;
        in >> value;
        temp->value = value;
        temp->next = head->next;
        head->next = temp;
    }
    
    stampaLista(head);
    cout << endl << "----------------------------------" << endl;
    // stampaListaInvertita(head);
    // cout << endl << "----------------------------------" << endl;
    primizzaLista(head);
    cout << "main";
    stampaLista(head);
    // distruggiLista(head);
    in.close();
    return 0;
}

void stampaLista(node *listaDiNumeri) {
    node *temp = listaDiNumeri;
    while(temp!=nullptr) {
        cout << temp->value << " "; 
        temp = temp->next;
    }
}

void stampaListaInvertita(node *listaDiNumeri) {
    if(listaDiNumeri!=nullptr) {
        node *temp = listaDiNumeri;
        stampaListaInvertita(temp->next);
        cout << temp->value << " "; 
    }
}

void distruggiLista(node *&listaDiNumeri) {
    while(listaDiNumeri!=nullptr) {
        node *temp = listaDiNumeri;
        listaDiNumeri = listaDiNumeri->next;
        delete temp;
    }
}

bool isPrime(const int value) {
    for(int i = 2; i <= (value/2); i++) {
        if(value%i == 0) {
            return false;
        }
    }
    return true;
}

void remove_element(node * &head, int element) {
    if (head != nullptr) {
        node *q = head;
        if (q->value == element) {
            head = head->next;
            delete q;
        } else {
            while(q->next != nullptr) {
                if (q->next->value == element) {
                    node *r = q->next;
                    q->next = q->next->next;
                    delete r;
                    return;
                }
                if (q->next != nullptr) {
                    q = q->next;
                }
            }
        }
    }
}

void primizzaLista(node * &head) {
    node *temp = head;
    node *prev = nullptr;

    while (temp != nullptr) {
        if (!isPrime(temp->value)) {
            if (prev == nullptr) {
                head = temp->next;
                delete temp;
                temp = head;
            } else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}