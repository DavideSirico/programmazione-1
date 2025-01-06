#include <iostream>
#include <cstdlib>
#include <cassert>

typedef struct List {
    int data;
    struct List * next;
} List;

typedef struct Queue {
    List * head;
    List * tail;
} Queue;

Queue * initQueue() {
    return new Queue {nullptr, nullptr};
}

bool isEmpty(Queue * s) {
    return ((s != nullptr) && (s->head == s->tail) && (s->head == nullptr));
}

void enqueue(Queue * &s, int value) {
    if (s == nullptr) {
        std::cerr << "enqueue Error: the queue is nullptr" << std::endl;
        assert(false);
        exit(1);
    }
    List * newElement = new List {value, nullptr};
    if (isEmpty(s)) {
        s->tail = s->head = newElement;
    } else {
      s->tail->next = newElement;
      s->tail = newElement;
    }
}

int first(Queue * s) {
    if (isEmpty(s)) {
        std::cerr << "first Error: the queue is empty" << std::endl;
        assert(false);
        exit(1);
    }
    return s->head->data;
}

int dequeue(Queue * &s) {
    if (isEmpty(s)) {
        std::cerr << "dequeue Error: queue is empty" << std::endl;
        assert(false);
        exit(1);
    }
    int value = s->head->data;
    List * temp = s->head;
    if (s->head == s->tail) {
        s->head = s->tail = nullptr;
    } else {
        s->head = s->head->next;
    }
    delete temp;
    return value;
}

int length(Queue * s) {
    int count = 0;
    List * temp = s->head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void reverse(Queue * & s) {
    if (!isEmpty(s)) {
        int v = dequeue(s);
        reverse(s);
        enqueue(s, v);
    }
}

void deleteQueue(Queue * &s) {
    while (!isEmpty(s)) {
        dequeue(s);
    }
}

void printQueue(Queue * s, const char * message = "Queue: ") {
    if (isEmpty(s)) {
        std::cout << message << "Queue is empty" << std::endl;
    }
    else
    {
        std::cout << message;
        List * temp = s->head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}


int getElement(Queue *& q, int n);
int getElement_aux(Queue*& q, int n, int result);
void removeElement(Queue *& q, int n);
void removeElement_aux(Queue*& q, int n);
int findElement(Queue *& q, int n);
int findElement_aux(Queue*& q, int n, int result, int index);
void changeElement(Queue *& q, int index, int value);
void changeElement_aux(Queue*& q, int index, int value, int index_start);
void sort(Queue *& q);
int sumElementsWithDistance(Queue *& q, int n);
int sumElementsWithDistance_aux(Queue *& q, int n, int to_remove);
// TODO
void insertElement(Queue *& q, int index, int value);
void insertElement_aux(Queue *& q, int index, int value);

int main() {
    srand(time(NULL));
    Queue *q = initQueue();
    for(int i = 1000; i >= 0; i--) {
        enqueue(q,rand()%100);

    }
    // insertElement(q, 0, 1000);
    sort(q);
    printQueue(q);
    return 0;
}

int sumElementsWithDistance_aux(Queue *& q, int n, int to_remove) {
    if (isEmpty(q)) {
        return 0;
    }
    int current = dequeue(q);
    if(to_remove == 0) {
        to_remove = n;
        int sum = sumElementsWithDistance_aux(q,n,to_remove);
        enqueue(q, current);
        // std::cout << "CURRENT ELEMENT: " << current << std::endl;
        return sum+current;
    }
    if(to_remove <= n) {
        to_remove--;
        int sum = sumElementsWithDistance_aux(q,n,to_remove);
        enqueue(q, current);
        return sum;
    }
}

int sumElementsWithDistance(Queue *& q, int n) {
    int ris = sumElementsWithDistance_aux(q,n,0);
    reverse(q);
    return ris;
}

int getElement(Queue *& q, int n) {
    int result = 0;
    int ris = getElement_aux(q, n, result);
    reverse(q);
    return ris;
}
int getElement_aux(Queue*& q, int n, int result) {
    if(isEmpty(q)) {
        return result;
    }
    if(n == 0) {
        result = first(q);
    }
    int value = dequeue(q);
    int ris = getElement_aux(q, n - 1, result);
    enqueue(q, value);
    return ris;
}

void removeElement(Queue *& q, int n) {
    removeElement_aux(q, n);
    reverse(q);
}
void removeElement_aux(Queue*& q, int n) {
    if(isEmpty(q)) {
        return;
    }
    if(n == 0) {
        dequeue(q);
    }
    int value = dequeue(q);
    removeElement_aux(q, n - 1);
    enqueue(q, value);
}

int findElement(Queue *& q, int n) {
    int result = 0;
    int index = 0;
    int ris = findElement_aux(q, n, result, index);
    reverse(q);
    return ris;
}
int findElement_aux(Queue*& q, int n, int result, int index) {
    if(isEmpty(q)) {
        return result;
    }
    if(first(q) == n) {
        result = index;
    }
    int value = dequeue(q);
    int ris = findElement_aux(q, n, result, index + 1);
    enqueue(q, value);
    return ris;
}

void changeElement(Queue *& q, int index, int value) {
    changeElement_aux(q, index, value, 0);
    reverse(q);
}
void changeElement_aux(Queue*& q, int index, int value, int index_start) {
    if (isEmpty(q)) {
        return;
    }
    int first = dequeue(q);
    if (index == index_start) {
        first = value;
    }
    changeElement_aux(q, index, value, index_start + 1);
    enqueue(q, first);
}

void FrontToLast(Queue *& q, int qsize) {
    if (qsize <= 0)
        return;
    
    enqueue(q, first(q));
    dequeue(q);
    FrontToLast(q, qsize - 1);
}
void pushInQueue(Queue *& q, int temp, int qsize) {
    if (isEmpty(q) || qsize == 0) {
        enqueue(q, temp);
        return;
    } else if (temp <= first(q)) {
        enqueue(q, temp);
        FrontToLast(q, qsize);
    } else {
        enqueue(q, first(q));
        dequeue(q);
        pushInQueue(q, temp, qsize - 1);
    }
}
void sort(Queue *& q) {
    if (isEmpty(q))
        return;

    int temp = first(q);
    dequeue(q);
    sort(q);
    pushInQueue(q, temp, length(q));
}

void merge(Queue *& q1, Queue *& q2) {
    while (!isEmpty(q2)) {
        enqueue(q1, first(q2));
        dequeue(q2);
    }
    sort(q1);
}

void insertElement(Queue *& q, int index, int value) {
    if (index == 1) {
        enqueue(q, value);
        return;
    }

    int tempValue = dequeue(q);
    insertElement(q, value, index - 1);
    enqueue(q, tempValue);
}