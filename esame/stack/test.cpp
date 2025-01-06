#include <iostream>
#include <cassert>
#include "stack.cpp"

void testPush() {
    Stack *s = initStack();
    push(s, 1);
    assert(top(s) == 1);
    push(s, 2);
    assert(top(s) == 2);
    deleteStack(s);
}

void testPop() {
    Stack *s = initStack();
    push(s, 1);
    push(s, 2);
    assert(pop(s) == 2);
    assert(pop(s) == 1);
    assert(isEmpty(s));
    deleteStack(s);
}

void testTop() {
    Stack *s = initStack();
    push(s, 1);
    assert(top(s) == 1);
    push(s, 2);
    assert(top(s) == 2);
    deleteStack(s);
}

void testIsEmpty() {
    Stack *s = initStack();
    assert(isEmpty(s));
    push(s, 1);
    assert(!isEmpty(s));
    deleteStack(s);
}

void testLength() {
    Stack *s = initStack();
    assert(lenght(s) == 0);
    push(s, 1);
    assert(lenght(s) == 1);
    push(s, 2);
    assert(lenght(s) == 2);
    deleteStack(s);
}

void testDeleteStack() {
    Stack *s = initStack();
    push(s, 1);
    push(s, 2);
    deleteStack(s);
    assert(isEmpty(s));
}

void testPrintStack() {
    Stack *s = initStack();
    push(s, 1);
    push(s, 2);
    printStack(s, "Test Stack: ");
    deleteStack(s);
}

void testGetElement() {
    Stack *s = initStack();
    for (int i = 0; i < 5; i++) {
        push(s, i);
    }
    std::cout << getElement(s, 0) << std::endl;
    assert(getElement(s, 0) == 4);
    assert(getElement(s, 4) == 0);
    deleteStack(s);
}

void testRemoveElement() {
    Stack *s = initStack();
    for (int i = 0; i < 5; i++) {
        push(s, i);
    }
    removeElement(s, 2);
    assert(lenght(s) == 4);
    assert(getElement(s, 2) == 1);
    deleteStack(s);
}

void testFindElement() {
    Stack *s = initStack();
    for (int i = 0; i < 5; i++) {
        push(s, i);
    }
    assert(findElement(s, 3));
    assert(!findElement(s, 5));
    deleteStack(s);
}

void testChangeElement() {
    Stack *s = initStack();
    for (int i = 0; i < 5; i++) {
        push(s, i);
    }
    changeElement(s, 2, 10);
    assert(getElement(s, 2) == 10);
    deleteStack(s);
}

void testReverse() {
    Stack *s = initStack();
    for (int i = 0; i < 5; i++) {
        push(s, i);
    }
    reverse(s);
    assert(getElement(s, 0) == 0);
    assert(getElement(s, 4) == 4);
    deleteStack(s);
}

void testSort() {
    Stack *s = initStack();
    push(s, 3);
    push(s, 1);
    push(s, 4);
    push(s, 2);
    sort(s);
    assert(getElement(s, 0) == 4);
    assert(getElement(s, 3) == 1);
    deleteStack(s);
}

void testInsertElement() {
    Stack *s = initStack();
    for (int i = 0; i < 5; i++) {
        push(s, i);
    }
    insertElement(s, 10, 2);
    assert(getElement(s, 2) == 10);
    deleteStack(s);
}

void testSumElementsWithDistance() {
    Stack *s = initStack();
    for (int i = 0; i < 10; i++) {
        push(s, i);
    }
    assert(sumElementsWithDistance(s, 2) == 18);
    deleteStack(s);
}

int main() {
    testPush();
    testPop();
    testTop();
    testIsEmpty();
    testLength();
    testDeleteStack();
    testPrintStack();
    testGetElement();
    testRemoveElement();
    testFindElement();
    testChangeElement();
    testReverse();
    testSort();
    testInsertElement();
    testSumElementsWithDistance();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}