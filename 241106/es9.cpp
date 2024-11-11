#include <iostream>
using namespace std;
/*
Problema di Giuseppe Flavio:
  - Immaginiamo che N persone debbano eleggere un leader.
  - L'elezione avviene nel seguente modo:
    . le persone si dispongono in cerchio, eliminando una persona ogni
      M, seguendo l'ordine del cerchio, e richiudendo il cerchio ad
      ogni eliminazione.
  - Il problema e' quello di scoprire quale persona rimarra' per
    ultima, e sara' quindi il leader.
  - O piu' in generale e' quello di determinare l'ordine in cui le
    persone verranno eliminate.

  Suggerimento:

  Per rappresentare persone disposte in cerchio costruiamo una lista
  concatenata circolare dove, per ogni persona, un link connette la
  persona alla persona immediatamente alla sua sinistra nel
  cerchio. La costruzione della lista la si puo' fare come segue:
  - Si costruisce una lista circolare di un solo nodo per la persona 1.
  - Si inseriscono una alla volta le altre N-1 persone.
  - Il risultato e' un cerchio con i nodi da 1 a N.
  - Prendiamo il primo nodo del cerchio e saltiamo M-1 nodi,
    rimuoviamo il nodo M aggiornando i link per mantenere la struttura
    circolare.
  - Ripartiamo dal nodo M-1 applicando lo stesso principio.

  - Ripetiamo l'approccio fino a quando un solo nodo e' rimasto. Il
    contenuto dara' il nomde del leader. La memorizzazione dell'ordine
    in cui gli elementi sono rimossi risponde alla domanda.

*/

struct node {
    node * next;
    int data;
};

void giuseppe_flavio(int n, int m);
void remove_element(node * &head, int element, node *start);
void delete_list(node * &s);
void visualizza(node *, node *);
void insert_last(node * &s, int d);
void insert_first(node * &, int);
node * copia(node *head);
int main() {
    giuseppe_flavio(12,2);
    return 0;
}

void giuseppe_flavio(int n, const int m) {
    node* head = new node;
    head->next = nullptr;
    head->data = 1;
    node* current = head;

    for (int i = 2; i <= n; ++i) {
        node *temp = new node;
        temp->data = i;
        temp->next = nullptr;

        current->next = temp;

        current = current->next;
    }
    
    current->next = head;
    node* prev = nullptr;
    current = head;

    while (current->next != current) {
        for (int i = 0; i < m; i++) {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        cout << "eliminato: " << current->data << endl;
        delete current;
        
        current = prev->next;
    }

    int leader = current->data;
    delete current;
    cout << leader;
}

void delete_list(node * & s) {
  while(s != NULL) {
    node * t = s;
    s = s->next;
    delete t;
  }
}

void visualizza(node *l, node *start){
    for(node *s=l; s!=start;s=s->next)
        cout << s->data <<" ";
    cout << endl;
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

void remove_element(node * &head, int element, node *start) {
    if (head != NULL) {
        node *q = head;
        if (q->data == element) {
            head = head->next;
            delete q;
        } else {
            while(q->next != start) {
                if (q->next->data == element) {
                    node *r = q->next;
                    q->next = q->next->next;
                    delete r;
                    return;
                }
                if (q->next != start) {
                    q=q->next;
                }
            }
        }
    }
}