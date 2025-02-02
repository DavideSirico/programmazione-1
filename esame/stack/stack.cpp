#include <iostream>
#include <cstdlib>
#include <cassert>

typedef struct List {
    int data;
    struct List * next;
} List;

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
        std::cout << message << std::endl;
        struct Stack * temp = s;
        while (temp != nullptr) {
            std::cout << temp->data << "\n";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}

int getElement(Stack *& s, int n);
void removeElement(Stack *& s, int n);
void removeElement_aux(Stack*& s, int n);
bool findElement(Stack *& s, int n);
void changeElement(Stack *& s, int index, int value);
void changeElement_aux(Stack*& s, int index, int value, int index_start);
void reverse(Stack *& s);
void insert_last(Stack *& s, int n);
void sort(Stack *& s);
void insertElement(Stack *& s, int index, int value);
int sumElementsWithDistance(Stack *& s, int n);
int sumElementsWithDistance_aux(Stack *& s, int n, int to_remove);

int main() {
    Stack *s = initStack();
    for(int i = 0; i < 10; i++) {
        push(s,i);
    }
    printStack(s);
    std::cout << getElement(s, 0);
    return 0;
}

void insert_last(Stack *& s, int n) {
    if (isEmpty(s)){
        push(s,n);
        return;
    }
    int topElement = pop(s);
    insert_last(s, n);
    push(s,topElement);
}

void reverse(Stack *& s) {
    if (isEmpty(s)) {
        return;
    }

    int topElement = pop(s);
    reverse(s);
    insert_last(s, topElement);
}

int getElement(Stack *& s, int n) {
    if(n == 0) {
        return top(s);
    }
    int value = pop(s);
    int ris = getElement(s, n - 1);
    push(s, value);
    return ris;
}

void removeElement(Stack *& s, int n) {
    removeElement_aux(s, n);
}
void removeElement_aux(Stack *& s, int n) {
    if(isEmpty(s)) {
        return;
    }
    if(n == 0) {
        pop(s);
    }
    int value = pop(s);
    removeElement_aux(s, n - 1);
    push(s, value);
}

bool findElement(Stack *& s, int n) {
    if (isEmpty(s)) {
        return false;
    }

    int topElement = top(s);
    pop(s);

    if (topElement == n) {
        push(s, topElement);
        return true;
    }

    bool found = findElement(s, n);

    push(s,topElement);

    return found;
}

void changeElement(Stack *& s, int index, int value) {
    changeElement_aux(s, index, value, 0);
}
void changeElement_aux(Stack *& s, int index, int newValue, int currentIndex) {
    if (isEmpty(s) || index < 0) {
        return;
    }

    int topElement = top(s);
    pop(s);

    if (currentIndex == index) {
        topElement = newValue;
    }

    changeElement_aux(s, index, newValue, currentIndex + 1);

    push(s, topElement);
}

void insertSorted(Stack *& s, int element) {
    if (isEmpty(s) || top(s) <= element) {
        push(s, element);
        return;
    }
    int topElement = top(s);
    pop(s);
    insertSorted(s, element);
    push(s, topElement);
}

void sort(Stack *& s) {
    if (isEmpty(s)) {
        return;
    }

    int topElement = top(s);
    pop(s);
    sort(s);
    insertSorted(s, topElement);
}

int sumElementsWithDistance_aux(Stack *&s, int n, int to_remove) {
    if (isEmpty(s)) {
        return 0;
    }
    int current = pop(s);  // Pop element from stack
    
    int sum = 0;
    if (to_remove == 0) {
        to_remove = n;
        sum = sumElementsWithDistance_aux(s, n, to_remove);
        sum += current;
    } else if (to_remove <= n) {
        to_remove--;
        sum = sumElementsWithDistance_aux(s, n, to_remove);
    }
    
    push(s, current);  // Ensure the element is pushed back to the stack
    return sum;
}


int sumElementsWithDistance(Stack *& s, int n) {
    int ris = sumElementsWithDistance_aux(s,n,0);
    return ris;
}

void insertElement(Stack *& s, int element, int index) {
    if (index == 0) {
        push(s, element);
        return;
    }
    
    if (isEmpty(s)) {
        return;
    }

    // Pop the top element
    int topElement = top(s);
    pop(s);
    insertElement(s, element, index-1);

    // Push the previously popped element back
    push(s, topElement);
}