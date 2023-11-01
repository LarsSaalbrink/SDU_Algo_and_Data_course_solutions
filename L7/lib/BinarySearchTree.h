#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include <algorithm>
using namespace std;

class BinaryNode
{
public:
	int element;
	BinaryNode *left;
	BinaryNode *right;

	BinaryNode(const int & theElement, BinaryNode *lt, BinaryNode *rt)
		: element{ theElement }, left{ lt }, right{ rt } { }

	BinaryNode(int && theElement, BinaryNode *lt, BinaryNode *rt)
		: element{ std::move(theElement) }, left{ lt }, right{ rt } { }
};


class BinarySearchTree
{
public:
	BinarySearchTree(); 
	BinarySearchTree(const BinarySearchTree & rhs); 
	BinarySearchTree(BinarySearchTree && rhs); 
	~BinarySearchTree();
	
	const int & findMin() const;
	const int & findMax() const;
	bool contains(const int & x) const;
	bool isEmpty() const;
	void printTree() const;
	
	void makeEmpty();
	void insert(const int & x);
	void insert(int && x);
	void remove(const int & x);

	bool preOrder_search(int x) const;
	bool inOrder_search(int x) const;
	bool postOrder_search(int x) const;
	bool levelOrder_search(int x) const;
	
	unsigned int numNodes() const;
	unsigned int numLeaves() const;
	unsigned int numFullNodes() const; 

	unsigned int internalPathLength() const;

private:
	BinaryNode *root;

	void insert(const int & x, BinaryNode * & t);
	void insert(int && x, BinaryNode * & t);
	void remove(const int & x, BinaryNode * & t);
	BinaryNode * findMin(BinaryNode *t) const;
	BinaryNode * findMax(BinaryNode *t) const;
	
	bool contains(const int & x, BinaryNode *t) const;
	
	void makeEmpty(BinaryNode * & t);
	void printTree(BinaryNode *t) const;
	BinaryNode * clone(BinaryNode *t) const;
	
	bool preOrder_search_helper(int target, BinaryNode *t) const;
	bool inOrder_search_helper(int target, BinaryNode *t) const;
	bool postOrder_search_helper(int target, BinaryNode *t) const;
	bool levelOrder_search_helper(int target, BinaryNode *t) const;

	unsigned int numNodes_helper(BinaryNode *t) const;
	unsigned int numLeaves_helper(BinaryNode *t) const;
	unsigned int numFullNodes_helper(BinaryNode *t) const;

	unsigned int internalPathLength_helper(BinaryNode *t, unsigned int depth) const;
};

#endif
