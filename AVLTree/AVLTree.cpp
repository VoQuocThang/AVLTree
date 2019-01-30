#include "AVLTree.h"


template <class T>
AVLTree<T>::AVLTree() : root(nullptr) {}

/*
		Private area
*/

template <class T>
bool  AVLTree<T> ::searchHelper(Node<T> * r, T k) {
	if (r == nullptr) return false;
	if (r->getKey() == k) return true;
	if (r->getKey() > k) return searchHelper(r->getLeft(), k);
	else return searchHelper(r->getRight(), k);
}


template <class T> 
Node<T> * AVLTree<T> ::leftRotate(Node<T> * x) {
	Node<T> * y = x->getRight();
	x->setRight(y->getLeft());
	y->setLeft(x);
	return y;
	
}

template <class T>
Node<T> * AVLTree<T> ::rightRotate(Node<T> * x) {
	Node<T> * y = x->getLeft();
	x->setLeft(y->getRight());
	y->setRight(x);
	return y;
}

template <class T>
int AVLTree<T> ::getHeightHelper(Node<T> * r) {
	if (r == nullptr) return 0;
	return 1 + max(getHeightHelper(r->getLeft()), getHeightHelper(r->getRight()));
}



template <class T> 
int AVLTree<T> ::getBalance(Node<T> *r) {
	return getHeightHelper(r->getLeft()) - getHeightHelper(r->getRight());
}


/*
	   Always add to a leave node

*/
template <class T>
Node<T> * AVLTree<T> ::addHelper(Node<T> *r, Node<T> * p) {
	if (r == nullptr) return p;
	if (p->getKey() < r->getKey()) r->setLeft(addHelper(r->getLeft(), p));
	else r->setRight(addHelper(r->getRight(), p));

	/* 
	        rebalance  
			check 4 case
			use p.key() to choose case
	*/

	int balance = getHeightHelper(r->getLeft()) - getHeightHelper(r->getRight());

	if (balance > 1) {
		 
		if (p->getKey() > r->getLeft()->getKey())  r->setLeft(leftRotate(r->getLeft()));
		return rightRotate(r);
	}
	else if (balance < -1) {

		if (p->getKey() < r->getRight()->getKey()) r->setRight(rightRotate(r->getRight()));
		return leftRotate(r);

	}

	return r;
}

/*
		Find the biggest node of the subtree has root r
*/
template<class T>
Node<T> * AVLTree<T> ::successorNode(Node<T> *r, T & successorKey) {
	if (r->getRight() == nullptr) {
		successorKey = r->getKey();
		return removeNode(r);
	}
	r->setRight(successorNode(r->getRight(), successorKey));
	return r;
}

template <class T>
Node<T> * AVLTree<T>::removeNode(Node<T> * r) {

	/*if node has only right child
	  then replaced by right child
	*/

	if (r->getLeft() == nullptr) {
		Node<T> * temp = r->getRight();
		delete r;
		return temp;
	}
	/* if node has only left child
	   then replaced by left child
	*/
	else if (r->getRight() == nullptr) {
		Node<T> * temp = r->getLeft();
		delete r;
		return temp;
	}
	/*  if node has both left and right chlid,
		then find the biggest node in left-subtree to replace it
	*/
	else {
		int successorKey;
		r->setLeft(successorNode(r->getLeft(), successorKey));
		r->setKey(successorKey);
		return r;
	}
}



template <class T>
Node<T> * AVLTree<T> ::removeHelper(Node<T> *r, T k) {
	if (r == nullptr) return r;
	if (r->getKey() == k) {
		r=removeNode(r);
	}
	else if (r->getKey() > k)  r->setLeft(removeHelper(r->getLeft(), k));
	else r->setRight(removeHelper(r->getRight(), k));

	if (r == nullptr) return r;
	/*
	       rebalance 
		   check 4 case
		   compare heights of its children

	*/
	int balance = getBalance(r);

	if (balance > 1) {

		if (  getBalance(r->getLeft() ) < 0 )  r->setLeft(leftRotate(r->getLeft()));
		return rightRotate(r);
	}
	else if (balance < -1) {

		if (getBalance(r->getRight() ) > 0 ) r->setRight(rightRotate(r->getRight()));
		return leftRotate(r);
		
	}
	return r;

}

template<class T>
void AVLTree<T> ::inOrder(Node<T> *r) {
	if (r == nullptr) return;
	inOrder(r->getLeft());
	std::cout << r->getKey() << " ";
	inOrder(r->getRight());
}


/*
		Public area
*/
template <class T>
bool AVLTree<T> ::search(T k) {
	return searchHelper(root, k);
}

template <class T>
bool AVLTree<T>::add(T k) {
	if (search(k)) return false;
	Node<T> * p = new Node<T>(k);
	root = addHelper(root, p);
	return true;
}


template <class T>
bool AVLTree<T>::remove(T k) {
	if (!search(k)) return false;
	root = removeHelper(root, k);
	return true;
}

template <class T>
int AVLTree<T>::getHeight() {
	return getHeightHelper(root);
}

/*
		  Clear the tree by removing from root
*/
template<class T>
void AVLTree<T>::clear() {
	while (root != nullptr) remove(root->getKey());
}

template <class T>
void AVLTree<T>::inOrderTraversal() {
	inOrder(root);
	std::cout << "\n";
}

template <class T>
AVLTree<T>::~AVLTree()
{

}
