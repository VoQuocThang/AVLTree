#pragma once

template <class T>
class Node
{
private:
	T key;
	Node<T> * left;
	Node<T> * right;
public:

	T getKey();
	Node<T> * getLeft();
	Node<T> * getRight();

	void setKey(T);
	void setLeft(Node<T> *);
	void setRight(Node<T> *);

public:
	Node();
	Node(T);
	~Node();
};

