//HW2 Shoaib Sheikh
//SU NetId: ssheikh SUID: 631608148

#include <iostream>
#include <string>
using namespace std;
//int m = 50;
class Node {
public:
	int value;
	Node* l_child;
	Node* r_child;
	Node() : l_child(nullptr), r_child(nullptr) {}
	Node(int i) :value(i), l_child(nullptr), r_child(nullptr) {}

};



class Tree { //an n-level full binary tree of 2^n - 1 nodes
public:
	Node* root;
	Tree() : root(nullptr) {}
	Node* makeTree(int n, int m);
	void printTree1(Node* p); //in-order printing
	void printTree2(Node* p); //pre-order printing
	void printTree3(Node* p); //post-order printing
	void mirror(Node* p);
	int sum(Node* p);



	/*
	HW2: Implement the following three member functions.
	*/

	Node* mirrorCopy(Node* p);//5 points
	//Create an external mirror copy of a tree rooted at a node pointed by p
	//and return a pointer pointing to the root of this external tree.
	//Note that the function will not change the original tree.
	//You are required to implement this function with recursion.


	void minHeap(Node* p);//8 points
	//Recall that in a Min Heap, at all nodes, 
	//value(parent)<= value(l_child) and value(parent) <= value(r_child).
	//This function re-structures the tree, whose root is pointed by p, into a Min Heap.
	//You are required to use recursion.

	pair<Node*, Node* >  sort(Node* p);//22 points
	//sorting such that
	//ascending sequence in pre-order traversal
	//This function returns a pair of pointers,  which point to the node with the smallest
	//value and the node with the largest values in the tree rooted at node pointed by p .
	//printTree2 will give a sorted sequence.
	//You are required to use recursion, but additional while loop is allowed.

	
};


Node* Tree::mirrorCopy(Node* p) {

	
	if (p== nullptr) { return nullptr; }
	Node* mirror = new Node(p->value);
	mirror->l_child = mirrorCopy(p->r_child);
	mirror->r_child = mirrorCopy(p->l_child);
	return mirror;
	

}
void Tree::minHeap(Node* p) {
	

	if (p == nullptr) {
		return;
	}
		minHeap(p->l_child);
		minHeap(p->r_child);
		if (p->l_child != nullptr && p->l_child->value < p->value) {
			swap(p->l_child->value, p->value);
		}
		if (p->r_child != nullptr && p->r_child->value < p->value) {
			swap(p->r_child->value, p->value);
		}
		
	}


pair<Node*, Node* >  Tree::sort(Node* p) {


	if (p == nullptr || p->l_child == nullptr) {
		return make_pair(nullptr,nullptr);
	}
	bool swapping = false;
	pair<Node*,Node*> left =sort(p->l_child);

	pair<Node*, Node*> right = sort(p->r_child);
	
	if (p->l_child->value < p->value) {
		swap(p->l_child->value, p->value);
		swapping = true;
		

	}
	if ( p->r_child->value < p->value) {
		swap(p->r_child->value, p->value);
		swapping = true;
		

	}
	if (p->l_child->value > p->r_child->value) {
		swap(p->l_child->value, p->r_child->value);
		swapping = true;
	}

	if (!p->l_child->l_child) { 
		return make_pair(p, p->r_child);
	}
	else {
		while (swapping || left.second->value > right.first->value) {
			left = sort(p->l_child);
			right = sort(p->r_child);
			swapping = false;

			if(left.second->value > right.first->value) {
				swap(left.second->value, right.first->value);
				swapping = true;
			}
		}
		return make_pair(p, right.second);
	}
	 
}




int Tree::sum(Node* p) {
	if (!p) return 0;
	if (!p->l_child) return p->value;
	return p->value + sum(p->l_child) + sum(p->r_child);
}

void Tree::mirror(Node* p) {
	if (!p || !p->l_child) return;
	mirror(p->l_child);
	mirror(p->r_child);
	swap(p->l_child, p->r_child);
}



Node* Tree::makeTree(int n, int m) { //Create an n-level full binary tree with 
							  //with random values between 0 ... m-1
							  //and returns a pointer to the root.

	Node* p = new Node(rand() % m);
	if (n == 1) return p;
	p->l_child = makeTree(n - 1, m);
	p->r_child = makeTree(n - 1, m);
	return p;
}

void Tree::printTree1(Node* p) { //in-order printing
	if (p == nullptr) return;
	printTree1(p->l_child);
	cout << p->value << " ";
	printTree1(p->r_child);
}

void Tree::printTree2(Node* p) { //pre-order printing

	if (p == nullptr) return;
	cout << p->value << " ";
	printTree2(p->l_child);
	printTree2(p->r_child);
}
void Tree::printTree3(Node* p) { //post-order printing
	if (p == nullptr) return;
	printTree3(p->l_child);
	printTree3(p->r_child);
	cout << p->value << " ";
}


int main() {
	Tree T1;
	T1.root = T1.makeTree(4, 20);
	T1.printTree1(T1.root);
	cout << endl;
	T1.printTree2(T1.root);
	cout << endl;
	T1.printTree3(T1.root);
	cout << endl;
	Tree T2;
	T2.root = T1.mirrorCopy(T1.root);
	T2.printTree1(T2.root);
	cout << endl;
	T2.printTree2(T2.root);
	cout << endl;
	T2.printTree3(T2.root);
	cout << endl;
	T2.minHeap(T2.root);
	T2.printTree1(T2.root);
	cout << endl;
	T2.printTree2(T2.root);
	cout << endl;
	T2.printTree3(T2.root);
	cout << endl;
	Tree T3;
	T3.root = T3.makeTree(5, 20);
	T3.sort(T3.root);
	T3.printTree1(T3.root);
	cout << endl;
	T3.printTree2(T3.root);
	cout << endl;
	T3.printTree3(T3.root);
	cout << endl;

	return 0;
}