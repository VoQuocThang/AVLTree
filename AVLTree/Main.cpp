/*
		 Programmer : Vo Quoc Thang
		 Date       : 30/1/2019
		 Content    : AVL Tree - Balanced Binary Search Tree
		 Note       : Use pointers and Oriented-Object Programming
*/
#include "AVLTree.cpp"
#include <iostream>
using namespace std;

int main() {
	int arr[] = { 5,8,2,4,6,2,1,3,4,9,11,7,10,23,15 };
	AVLTree<int> AVLTree;
	for (int i = 0; i < 15; i++)  AVLTree.add(arr[i]);
	AVLTree.inOrderTraversal();
	cout << "Heights of AVL Tree:" << AVLTree.getHeight() << endl;
	AVLTree.remove(2);
	AVLTree.remove(1);
	AVLTree.inOrderTraversal();
	cout << "Heights of AVL Tree:"<<AVLTree.getHeight()<<endl;
	AVLTree.clear();
	system("pause");
	return 0;
}