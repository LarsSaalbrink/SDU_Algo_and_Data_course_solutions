#ifndef STACK_H
#define STACK_H

class Stack {
public:
    Stack();
    Stack(int);
    ~Stack();
    void push(char);
    char pop();
    bool isEmpty() const;
    bool isFull() const;
private:
    char* stack;
    int top;
    int size;
};

#endif // STACK_H