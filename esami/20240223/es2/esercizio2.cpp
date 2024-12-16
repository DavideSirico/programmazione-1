#include <iostream>
#include <cstdlib>

typedef struct node {
    char var;
    struct node * Then;
    struct node * Else;
} node;

node * makeTrue() {
    node * res = new node;
    res->var = '1';
    res->Then = res->Else = nullptr;
    return res;
}

node * makeFalse() {
    node * res = new node;
    res->var = '0';
    res->Then = res->Else = nullptr;
    return res;
 }

 bool isTrue(const node * n) {
    return n != nullptr && n->var == '1' && n->Then == nullptr && n->Else == nullptr;
 }

bool isFalse(const node * n) {
    return n != nullptr && n->var == '0' && n->Then == nullptr && n->Else == nullptr;
}

node * makeVar(char v) {
    node * res = new node;
    res->var = v;
    res->Then = makeTrue();
    res->Else = makeFalse();
    return res;
}

node * makeNode(char v, node * t, node * e) {
    node * res = new node;
    res->var = v;
    res->Then = t;
    res->Else = e;
    return res;
}

char getVar(const node * n) {
    return n->var;
}

node * getThen(const node * n) {
    return n->Then;
}

node * getElse(const node * n) {
    return n->Else;
}

node * makeNot(node * n) {
    if (isTrue(n)) {
        return makeFalse();
    } else if (isFalse(n)) {
        return makeTrue();
    } else {
        return makeNode(n->var, makeNot(n->Then), makeNot(n->Else));
    }
}

void deleteNode(node * n) {
    if (n != nullptr) {
        deleteNode(n->Then);
        deleteNode(n->Else);
        delete n;
    }
}

void printNode(const node * n) {
    if (isTrue(n)) {
        std::cout << "1";
    } else if (isFalse(n)) {
        std::cout << "0";
    } else {
        std::cout << n->var << "(";
        printNode(n->Then);
        std::cout << ",";
        printNode(n->Else);
        std::cout << ")";
    }
}

node * makeCopy(const node * n) {
    if (isTrue(n)) {
        return makeTrue();
    } else if (isFalse(n)) {
        return makeFalse();
    } else {
        return makeNode(n->var, makeCopy(n->Then), makeCopy(n->Else));
    }
}

bool areEquivalent(const node * n, const node * m) {
    if (isTrue(n)) {
        return isTrue(m);
    } else if (isFalse(n)) {
        return isFalse(m);
    } else if (isTrue(m)) {
        return false;
    } else if (isFalse(m)) {
        return false;
    } else {
        return getVar(n) == getVar(m) && 
        areEquivalent(getThen(n), getThen(m)) && 
        areEquivalent(getElse(n), getElse(m));
    }
}

// Inserire qui sotto la dichiarazione della funzione makeOperation

node * makeOperation(node *n1, node *n2);

// Inserire qui sopra la dichiarazione della funzione makeOperation

int main() {
    node * A = makeVar('A');
    node * B = makeVar('B');
    node * C = makeVar('C');
    node * D = makeVar('D');
    node * notA = makeNot(A);
    node * AandB = makeNode('A', makeCopy(B), makeFalse());
    node * AorB = makeNode('A', makeTrue(), makeCopy(B));
    node * AandBorC = makeNode('A', makeNode('B', makeTrue(), makeCopy(C)), makeFalse());
    node * AorBandC = makeNode('A', makeTrue(), makeNode('B', makeCopy(C), makeFalse()));
    std::cout << "A & B := "; printNode(AandB); std::cout << std::endl;
    std::cout << "A | B := "; printNode(AorB);std::cout << std::endl;
    std::cout << "A & (B | C) := "; printNode(AandBorC);std::cout << std::endl;
    std::cout << "A | (B & C) := "; printNode(AorBandC);std::cout << std::endl;
    node *res[10] = {nullptr};

    res[0] = makeOperation(A, B);
    res[1] = makeOperation(notA, AandB);
    res[2] = makeOperation(C, res[0]);
    res[3] = makeOperation(D, res[2]);
    res[4] = makeOperation(res[0], res[2]);
    
    for (int i = 0; i < 10; i++) {
        if (res[i] == nullptr) {
            break;
        }
        std::cout << "res[" << i << "] := ";
        printNode(res[i]);
        deleteNode(res[i]);
        std::cout << std::endl;
    }
    
    deleteNode(A);
    deleteNode(B);
    deleteNode(C);
    deleteNode(D);
    deleteNode(notA);
    deleteNode(AandB);
    deleteNode(AorB);
    deleteNode(AandBorC);
    deleteNode(AorBandC);

    return 0;
}

// Inserire qui sotto la definizione della funzione makeOperation

node * makeOperation(node *n1, node *n2) {
    bool n1_is_terminal = n1->Else==nullptr && n1->Then == nullptr;
    bool n2_is_terminal = n2->Else==nullptr && n2->Then == nullptr;
    // caso base
    if(n1_is_terminal || n2_is_terminal) {
        if(n1->var == '1') {
            return makeCopy(n2);
        }
        if(n2->var == '1') {
            return makeCopy(n1);
        }
        if(n1->var == '0' || n2->var == '0') {
            return makeFalse();
        }
    }
    if(n1->var == n2->var) {
        node *T = new node;
        node *E = new node;
        T = makeOperation(n1->Then, n2->Then);
        E = makeOperation(n1->Else, n2->Else);
        if(T->var == E->var) {
            deleteNode(E);
            return T;
        } else {
            return makeNode(n1->var,T,E);
        }
    }
    if(n1->var < n2->var) {
        node *T = new node;
        node *E = new node;
        T = makeOperation(n1->Then, n2);
        E = makeOperation(n1->Else, n2);
        return makeNode(n1->var,T,E);
    }
    if(n1->var > n2->var) {
        node *T = makeOperation(n2->Then, n1);
        node *E = makeOperation(n2->Else, n1);
        return makeNode(n2->var,T,E);
    }
    return makeFalse();
}

// Inserire qui sopra la definizione della funzione makeOperation

