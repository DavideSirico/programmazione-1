#include <iostream>
#include <cstdlib>
#include <cassert>

typedef struct Stack {
    int data;
    struct Stack * next;
} Stack;

struct Stack * initStack() {
    return nullptr;
}

bool isEmpty(struct Stack * s) {
    return (s == nullptr);
}

void push(struct Stack * &s, int value) {
    struct Stack * newElement = new Stack;
    newElement->data = value;
    newElement->next = s;
    s = newElement;
}

int top(struct Stack * s) {
    if (isEmpty(s)) {
        std::cerr << "top Error: stack is empty" << std::endl;
        assert(false);
        exit(1);
    }
    return s->data;
}

int pop(struct Stack * &s) {
    if (isEmpty(s)) {
        std::cerr << "pop Error: stack is empty" << std::endl;
        assert(false);
        exit(1);
    }
    int value = s->data;
    struct Stack * temp = s;
    s = s->next;
    delete temp;
    return value;
}

int lenght(struct Stack * s) {
    int count = 0;
    struct Stack * temp = s;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void deleteStack(struct Stack * &s) {
    while (!isEmpty(s)) {
        pop(s);
    }
}

void printStack(struct Stack * s, const char * message = "Stack: ") {
    if (isEmpty(s)) {
        std::cout << "Stack is empty" << std::endl;
    }
    else
    {
        std::cout << message;
        struct Stack * temp = s;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}

void reverse(Stack *&s1);
void reverse_aux(Stack *s1, Stack *&s2);

int main() {
    Stack *s1;
    unsigned int seed = (unsigned int)time(NULL);
    // seed = 60000
    seed = 1697033220;
    srand(seed);

    s1 = initStack();
    for (int i = 0; i < 10; i++) {
        push(s1, rand() % 30);
    }
    printStack(s1, "S1: ");
    reverse(s1);
    printStack(s1, "S1: ");

    return 0;
}

void reverse_aux(Stack *s1, Stack *&s2) {
    if(s1==nullptr) {
        return;
    }
    int value = top(s1);
    pop(s1);
    push(s2,value);
    reverse_aux(s1,s2);
}

void reverse(Stack *&s) {
    Stack *s2 = initStack();
    reverse_aux(s,s2);
    s = s2;
}