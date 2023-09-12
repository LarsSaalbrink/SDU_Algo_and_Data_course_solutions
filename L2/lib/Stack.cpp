#include "Stack.h"

#include <iostream>

Stack::Stack() {
    size = 100;
    stack = new char[size];
    top = -1;
}
Stack::Stack(int size) {
    this->size = size;
    stack = new char[size];
    top = -1;
}
Stack::~Stack() {
    delete[] stack;
}

void Stack::push(char c) {
    if (isFull()) {
        std::cout << "Stack is full!" << std::endl;
        return;
    }
    stack[++top] = c;
}
char Stack::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
        return '\0';
    }
    return stack[top--];
}
bool Stack::isEmpty() {
    return top == -1;
}
bool Stack::isFull() {
    return top == size - 1;
}