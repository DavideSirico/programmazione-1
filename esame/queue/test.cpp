#include <iostream>
#include <cassert>
#include "queue.cpp"

void testEnqueueDequeue() {
    Queue *q = initQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    assert(dequeue(q) == 1);
    assert(dequeue(q) == 2);
    assert(dequeue(q) == 3);
    deleteQueue(q);
}

void testIsEmpty() {
    Queue *q = initQueue();
    assert(isEmpty(q));
    enqueue(q, 1);
    assert(!isEmpty(q));
    dequeue(q);
    assert(isEmpty(q));
    deleteQueue(q);
}

void testFirst() {
    Queue *q = initQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    assert(first(q) == 1);
    dequeue(q);
    assert(first(q) == 2);
    deleteQueue(q);
}

void testLength() {
    Queue *q = initQueue();
    assert(length(q) == 0);
    enqueue(q, 1);
    enqueue(q, 2);
    assert(length(q) == 2);
    dequeue(q);
    assert(length(q) == 1);
    deleteQueue(q);
}

void testReverse() {
    Queue *q = initQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    reverse(q);
    assert(dequeue(q) == 3);
    assert(dequeue(q) == 2);
    assert(dequeue(q) == 1);
    deleteQueue(q);
}

void testGetElement() {
    Queue *q = initQueue();
    for (int i = 0; i < 5; i++) {
        enqueue(q, i);
    }
    assert(getElement(q, 0) == 0);
    assert(getElement(q, 2) == 2);
    assert(getElement(q, 4) == 4);
    deleteQueue(q);
}

void testRemoveElement() {
    Queue *q = initQueue();
    for (int i = 0; i < 5; i++) {
        enqueue(q, i);
    }
    removeElement(q, 2);
    assert(getElement(q, 2) == 3);
    deleteQueue(q);
}

void testFindElement() {
    Queue *q = initQueue();
    for (int i = 0; i < 5; i++) {
        enqueue(q, i);
    }
    assert(findElement(q, 2) == 2);
    assert(findElement(q, 4) == 4);
    deleteQueue(q);
}

void testChangeElement() {
    Queue *q = initQueue();
    for (int i = 0; i < 5; i++) {
        enqueue(q, i);
    }
    changeElement(q, 2, 10);
    assert(getElement(q, 2) == 10);
    deleteQueue(q);
}

void testSort() {
    Queue *q = initQueue();
    enqueue(q, 3);
    enqueue(q, 1);
    enqueue(q, 2);
    sort(q);
    assert(dequeue(q) == 1);
    assert(dequeue(q) == 2);
    assert(dequeue(q) == 3);
    deleteQueue(q);
}

void testSumElementsWithDistance() {
    Queue *q = initQueue();
    for (int i = 1; i <= 5; i++) {
        enqueue(q, i);
    }
    assert(sumElementsWithDistance(q, 2) == 5); // 1 + 3 + 5
    deleteQueue(q);
}

void testMerge() {
    Queue *q1 = initQueue();
    Queue *q2 = initQueue();
    enqueue(q1, 1);
    enqueue(q1, 3);
    enqueue(q2, 2);
    enqueue(q2, 4);
    merge(q1, q2);
    assert(dequeue(q1) == 1);
    assert(dequeue(q1) == 2);
    assert(dequeue(q1) == 3);
    assert(dequeue(q1) == 4);
    deleteQueue(q1);
    deleteQueue(q2);
}

int main() {
    testEnqueueDequeue();
    testIsEmpty();
    testFirst();
    testLength();
    testReverse();
    testGetElement();
    testRemoveElement();
    testFindElement();
    testChangeElement();
    testSort();
    testSumElementsWithDistance();
    testMerge();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}