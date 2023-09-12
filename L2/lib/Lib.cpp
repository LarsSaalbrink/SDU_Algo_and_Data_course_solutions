#include "Lib.h"
#include "time_measurement.h"
#include "Stack.h"
#include "Queue.h"
#include "Singly_linked_list.h"

#include <iostream>
#include <vector>
#include <tuple>

// Check if pairs are balanced
// Valid symbols: ( ) , { } , [ ]
std::vector<std::tuple<char,char>> validSymbols = {
    std::make_tuple('(', ')'),
    std::make_tuple('{', '}'),
    std::make_tuple('[', ']')
};
bool balPar(std::string text){
    Stack stack;
    for (char c : text) {  // For every character in the text
        for (auto symbol : validSymbols) {   // For every set of symbols
            if (c == std::get<0>(symbol)) {  // If opening character
                stack.push(c);               // Save to stack
            } else if (c == std::get<1>(symbol)) {  // If closing character
                if (stack.isEmpty()) {  //No match, not balanced
                    return false;
                }
                char top = stack.pop();
                if (top != std::get<0>(symbol)) {  //Wrong symbol, not balanced
                    return false;
                }
            }
        }
    }
    return stack.isEmpty();
}
void test1(){
    std::cout << "\n---Test 1: balPar()---" << std::endl;
    std::string text = "{[(hejsa, jeg er korrekt)]}";
    std::cout << text << std::endl;
    std::cout << "Balanced: " << balPar(text) << std::endl;

    text = "Nice, jeg er korrekt";
    std::cout << text << std::endl;
    std::cout << "Balanced: " << balPar(text) << std::endl;

    text = "{[(Dammit, jeg er ikke korrekt)]]";
    std::cout << text << std::endl;
    std::cout << "Balanced: " << balPar(text) << std::endl;

    text = "(((Ejjjj, jeg er ikke korrekt)";
    std::cout <<  text << std::endl;
    std::cout << "Balanced: " << balPar(text) << std::endl;

    text = "(Farvel, jeg er ikke korrekt)]}";
    std::cout << text << std::endl;
    std::cout << "Balanced: " << balPar(text) << std::endl;
}

// Unit tests for Queue class
void test2(){
    std::cout << "\n---Test 2: Queue---" << std::endl;
    Queue<int> queue(5);
    std::cout << "Is empty: " << (queue.isEmpty() ? "true" : "false") << std::endl;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    std::cout << "Queue: ";
    queue.print_content();
    std::cout << "Dequeue: " << queue.dequeue() << std::endl;
    std::cout << "Dequeue: " << queue.dequeue() << std::endl;
    queue.print_content();
    queue.peek();
    std::cout << "Is empty: " << (queue.isEmpty() ? "true" : "false") << std::endl;
    std::cout << "Resize to length 2" << std::endl;
    queue.resize(2);
    queue.print_content();
    std::cout << "Add another element to cause overflow error" << std::endl;
    queue.enqueue(5);
    queue.print_content();
}

// Unit tests for Singly_linked_list class
void test3(){
    std::cout << "\n---Test 3: Singly_linked_list---" << std::endl;
    Singly_linked_list<int> list;
    std::cout << "Size: " << list.size() << std::endl;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    std::cout << "Size: " << list.size() << std::endl;
    std::cout << "List: ";
    list.print_content();
    std::cout << "Remove 2" << std::endl;
    list.remove(2);
    list.print_content();
    std::cout << "Remove 4" << std::endl;
    list.remove(4);
    std::cout << "Try to remove 10 which is not present" << std::endl;
    list.remove(10);
    list.print_content();
    std::cout << "Try to add duplicate 3" << std::endl;
    list.insert(3);
    list.print_content();
}

