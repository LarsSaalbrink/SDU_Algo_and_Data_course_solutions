#include "BinarySearchTree.h"
#include <queue>

BinarySearchTree::BinarySearchTree() : root{ nullptr }
{
}


BinarySearchTree::BinarySearchTree(const BinarySearchTree & rhs) : root{ nullptr }
{
	root = clone(rhs.root);
}


BinarySearchTree::BinarySearchTree(BinarySearchTree && rhs) : root{ rhs.root }
{
	rhs.root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	makeEmpty();
}

const int & BinarySearchTree::findMin() const
{
	if (isEmpty())
		return -1;
	return findMin(root)->element;
}


const int & BinarySearchTree::findMax() const
{
	if (isEmpty())
		return -1;
	return findMax(root)->element;
}

bool BinarySearchTree::contains(const int & x) const
{
	return contains(x, root);
}

bool BinarySearchTree::isEmpty() const
{
	return root == nullptr;
}

void BinarySearchTree::printTree() const
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	else
		printTree(root);
}

void BinarySearchTree::makeEmpty()
{
	makeEmpty(root);
}


void BinarySearchTree::insert(const int & x)
{
	insert(x, root);
}

void BinarySearchTree::insert(int && x)
{
	insert(std::move(x), root);
}

void BinarySearchTree::remove(const int & x)
{
	remove(x, root);
}

void BinarySearchTree::insert(const int & x, BinaryNode * & t)
{
	if (t == nullptr)
		t = new BinaryNode{ x, nullptr, nullptr };
	else if (x < t->element)
		insert(x, t->left);
	else if (t->element < x)
		insert(x, t->right);
	else
		;  // Duplicate; do nothing
}


void BinarySearchTree::insert(int && x, BinaryNode * & t)
{
	if (t == nullptr)
		t = new BinaryNode{ std::move(x), nullptr, nullptr };
	else if (x < t->element)
		insert(std::move(x), t->left);
	else if (t->element < x)
		insert(std::move(x), t->right);
	else
		;  // Duplicate; do nothing
}

void BinarySearchTree::remove(const int & x, BinaryNode * & t)
{
	if (t == nullptr)
		return;   // Item not found; do nothing
	if (x < t->element)
		remove(x, t->left);
	else if (t->element < x)
		remove(x, t->right);
	else if (t->left != nullptr && t->right != nullptr) // Two children
	{
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else
	{
		BinaryNode *oldNode = t;
		t = (t->left != nullptr) ? t->left : t->right;
		delete oldNode;
	}
}

BinaryNode * BinarySearchTree::findMin(BinaryNode *t) const
{
	if (t == nullptr)
		return nullptr;
	if (t->left == nullptr)
		return t;
	return findMin(t->left);
}

BinaryNode * BinarySearchTree::findMax(BinaryNode *t) const
{
	if (t != nullptr)
		while (t->right != nullptr)
			t = t->right;
	return t;
}

bool BinarySearchTree::contains(const int & x, BinaryNode *t) const
{
	if (t == nullptr)
		return false;
	else if (x < t->element)
		return contains(x, t->left);
	else if (t->element < x)
		return contains(x, t->right);
	else
		return true;    // Match
}

void BinarySearchTree::makeEmpty(BinaryNode * & t)
{
	if (t != nullptr)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = nullptr;
}


void BinarySearchTree::printTree(BinaryNode *t) const
{
	if (t != nullptr)
	{
		printTree(t->left);
		cout << t->element << endl;
		printTree(t->right);
	}
}

BinaryNode * BinarySearchTree::clone(BinaryNode *t) const
{
	if (t == nullptr)
		return nullptr;
	else
		return new BinaryNode{ t->element, clone(t->left), clone(t->right) };
}

bool BinarySearchTree::preOrder_search(int x) const
{
	return preOrder_search_helper(x, root);
}
bool BinarySearchTree::preOrder_search_helper(int target, BinaryNode *t) const
{
	if (t == nullptr)
		return false;
	if (t->element == target)
		return true;
	if (preOrder_search_helper(target, t->left))
		return true;
	if (preOrder_search_helper(target, t->right))
		return true;
	return false;
}

bool BinarySearchTree::inOrder_search(int x) const
{
	return inOrder_search_helper(x, root);
}
bool BinarySearchTree::inOrder_search_helper(int target, BinaryNode *t) const
{
	if (t == nullptr)
		return false;
	if (inOrder_search_helper(target, t->left))
		return true;
	if (t->element == target)
		return true;
	if (inOrder_search_helper(target, t->right))
		return true;
	return false;
}

bool BinarySearchTree::postOrder_search(int x) const
{
	return postOrder_search_helper(x, root);
}
bool BinarySearchTree::postOrder_search_helper(int target, BinaryNode *t) const
{
	if (t == nullptr)
		return false;
	if (postOrder_search_helper(target, t->left))
		return true;
	if (postOrder_search_helper(target, t->right))
		return true;
	if (t->element == target)
		return true;
	return false;
}

bool BinarySearchTree::levelOrder_search(int x) const
{
	return levelOrder_search_helper(x, root);
}
bool BinarySearchTree::levelOrder_search_helper(int target, BinaryNode *t) const
{
	if (t == nullptr)
		return false;
	std::queue<BinaryNode*> q;
	q.push(t);
	while (!q.empty())
	{
		BinaryNode *temp = q.front();
		q.pop();
		if (temp->element == target)
			return true;
		if (temp->left != nullptr)
			q.push(temp->left);
		if (temp->right != nullptr)
			q.push(temp->right);
	}
	return false;
}

unsigned int BinarySearchTree::numNodes() const
{
	return numNodes_helper(root);
}
unsigned int BinarySearchTree::numNodes_helper(BinaryNode *t) const
{
	if (t == nullptr)
		return 0;
	return 1 + numNodes_helper(t->left) + numNodes_helper(t->right);
}

unsigned int BinarySearchTree::numLeaves() const
{
	return numLeaves_helper(root);
}
unsigned int BinarySearchTree::numLeaves_helper(BinaryNode *t) const
{
	if (t == nullptr)
		return 0;
	if (t->left == nullptr && t->right == nullptr)
		return 1;
	return numLeaves_helper(t->left) + numLeaves_helper(t->right);
}

unsigned int BinarySearchTree::numFullNodes() const
{
	return numFullNodes_helper(root);
}
unsigned int BinarySearchTree::numFullNodes_helper(BinaryNode *t) const
{
	if (t == nullptr)
		return 0;
	if (t->left != nullptr && t->right != nullptr)
		return 1 + numFullNodes_helper(t->left) + numFullNodes_helper(t->right);
	return numFullNodes_helper(t->left) + numFullNodes_helper(t->right);
}

unsigned int BinarySearchTree::internalPathLength() const
{
	return internalPathLength_helper(root, 0);
}
unsigned int BinarySearchTree::internalPathLength_helper(BinaryNode *t, unsigned int depth) const
{
	if (t == nullptr)
		return 0;
	return depth + internalPathLength_helper(t->left, depth + 1) + internalPathLength_helper(t->right, depth + 1);
}