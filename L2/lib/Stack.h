#ifndef STACK_H
#define STACK_H

class Stack {
public:
    Stack();
    Stack(int);
    ~Stack();
    void push(char);
    char pop();
    bool isEmpty();
    bool isFull();
private:
    char* stack;
    int top;
    int size;
};

#endif // STACK_H