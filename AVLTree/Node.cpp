#include "Node.h"

template <class T>
Node<T>::Node() :left(nullptr), right(nullptr) {}

template <class T>
Node<T>::Node(T k) : key(k), left(nullptr), right(nullptr) {}

template <class T>
T Node<T> ::getKey() {
	return key;
}

template <class T>
Node<T> * Node<T>::getLeft() {
	return left;
}

template <class T>
Node<T> * Node<T>::getRight() {
	return right;
}


template <class T>
void Node<T> ::setKey(T k) {
	key = k;
}


template <class T>
void Node<T> ::setLeft(Node<T> * l) {
	left = l;
}

template <class T>
void Node<T>::setRight(Node<T> * r) {
	right = r;
}

template <class T>
Node<T>::~Node()
{
}
