#pragma once
#include "Node.cpp"
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
template <class T>
class AVLTree
{
private:
	Node<T> * root;
	bool searchHelper(Node<T> * r, T k);
	Node<T> * addHelper(Node<T> *r, Node<T> * p);
	Node<T> * removeHelper(Node<T> * r, T k);
	Node<T> * removeNode(Node<T> *);
	Node<T> * successorNode(Node<T> *, T &);
	int getHeightHelper(Node<T> * );
	Node<T> * leftRotate(Node<T> *);
	Node<T> * rightRotate(Node<T> *);
	int getBalance(Node<T> * r);
	void inOrder(Node<T> *r);


public:
	bool search(T);
	bool add(T);
	bool remove(T);
	void clear();
	int  getHeight();
	void inOrderTraversal();
public:
	AVLTree();
	~AVLTree();
};

