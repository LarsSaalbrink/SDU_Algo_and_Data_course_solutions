#include "Lib.h"
#include "BinarySearchTree.h"

#include <iostream>
#include <optional>
#include <vector>
#include <cmath>

void task1() {
    std::cout << "\n\n---------- Task 1 ----------" << std::endl;

    BinarySearchTree tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);

    std::cout << "Pre-order search 7: " << (tree.preOrder_search(7) ? "found" : "not found") << std::endl;
    std::cout << "Pre-order search 8: " << (tree.preOrder_search(8) ? "found" : "not found") << std::endl << std::endl;

    std::cout << "In-order search 2: " << (tree.inOrder_search(2) ? "found" : "not found") << std::endl;;
    std::cout << "In-order search 1: " << (tree.inOrder_search(1) ? "found" : "not found") << std::endl << std::endl;

    std::cout << "Post-order search 4: " << (tree.postOrder_search(4) ? "found" : "not found") << std::endl;
    std::cout << "Post-order search 6: " << (tree.postOrder_search(6) ? "found" : "not found") << std::endl << std::endl;

    std::cout << "Level-order search 3: " << (tree.levelOrder_search(3) ? "found" : "not found") << std::endl;
    std::cout << "Level-order search 13: " << (tree.levelOrder_search(13) ? "found" : "not found") << std::endl << std::endl;
}

void task2(){
    std::cout << "\n\n---------- Task 2 ----------" << std::endl;

    BinarySearchTree tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);

    std::cout << "Number of nodes: " << tree.numNodes() << std::endl;
    std::cout << "Number of leaves: " << tree.numLeaves() << std::endl;
    std::cout << "Number of full nodes: " << tree.numFullNodes() << std::endl << std::endl;
}

void task3(){
    std::cout << "\n\n---------- Task 3 ----------" << std::endl;

    BinarySearchTree tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);

    std::cout << "Internal path length: " << tree.internalPathLength() << std::endl;
}


BinarySearchTree generate_perfect_tree(int height){
    BinarySearchTree tree;

    unsigned int amount_of_nodes = pow(2, height+1) - 1;
    std::cout << "Amount of nodes: " << amount_of_nodes << std::endl;

    // Regular binary tree must not arrange nodes according to their value,
    // anything goes for non BST
    for(unsigned int i = 1; i <= amount_of_nodes; i++){
        tree.insert(i);
    }

    return tree; 
}
void task4(){
    std::cout << "\n\n---------- Task 4 ----------" << std::endl;

    BinarySearchTree tree = generate_perfect_tree(3);

    tree.printTree();
}