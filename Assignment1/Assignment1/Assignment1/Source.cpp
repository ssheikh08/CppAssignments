//HW1 by Shoaib Sheikh
//SU Net ID: ssheikh  SUID: 631608148


#include <iostream>
using namespace std;

class node {
public:
	int value;
	node* next;
	node* previous;
	//constructors to initialize object contents

	node(int i) { value = i; next = previous = nullptr; }
	node() { next = previous = nullptr; }
};

class DoublyLinkedList {
public:
	node* head;
	node* tail;
	//constructor
	DoublyLinkedList() { head = tail = nullptr; }
	DoublyLinkedList(int n, int m);
	void print_f();
	void print_r();
	DoublyLinkedList(const initializer_list<int>& I);
	void reverse();
	void sort();//You are only allowed to change next and previous of nodes, but not value;
	void remove_all(int k);//Remove all nodes with value k .

};

void DoublyLinkedList::remove_all(int k) {//Remove all nodes with value k;
	//Your code
	if (!head) return;
	node* p1 = head;
	node* p2;

	while (p1) {
		p2 = p1->next;
		if (p1->value == k) {
			if (p1 == head)
			{
				head = head->next;
			}
			if (p1 == tail) {
				tail = tail->previous;
			}
			
			if (p1->next != nullptr)
			{
				p1->next->previous = p1->previous;

			}
			if (p1->previous != nullptr) {
				p1->previous->next = p1->next;
			}

		}
		p1 = p2;
	}

}

void DoublyLinkedList::sort() {
	//Your code
	node* current{ head };
	//node* p2{ p1->next };
	while (current) {
		node* nextNode{ current->next };
		node* min{ current };

		while (nextNode) {
			if (nextNode->value <= min->value)
			{
				min = nextNode;
			}
			nextNode = nextNode->next;
		}

		if (min == current) {
			current = current->next;
		}
		else {
			if (min == tail) {
				min->previous->next = min->next;
				tail = min->previous;
				
			}
			else {
				min->next->previous = min->previous;
				min->previous->next = min->next;
			}


			if (current == head) {
				head = min;
				//min->previous = current->previous;
				//current->previous = min;
				//min->next = current;
				current->previous = min;
				min->next = current;
				min->previous = nullptr;
			}
			else {
				current->previous->next = min;
				min->previous = current->previous;
				current->previous = min;
				min->next = current;
			}
		}

	}

}




void DoublyLinkedList::reverse() {
	//Your code
	if (!head || !head->next) return;
	node* p1{ head };
	while (p1) {
		node* p2{ p1->next };
		p1->next = p1->previous;
		p1->previous = p2;
		p1 = p2;
	}
	p1 = head;
	head = tail;
	tail = p1;
}

DoublyLinkedList::DoublyLinkedList(int n, int m) {//construct a linked list of n modes with values in 0..m-1
	head = tail = nullptr;
	for (int i = 0; i < n; ++i) {
		node* p1 = new node(rand() % m);
		if (head == nullptr) { head = tail = p1; }
		else {//Add the new node after the node pointed by tail and let tail point to the new node.
			tail->next = p1;
			p1->previous = tail;
			tail = p1;
		}
	}
}


DoublyLinkedList::DoublyLinkedList(const initializer_list<int>& I) : DoublyLinkedList() {
	//Your code
	auto p1{ I.end() - 1 };//end() returns the address after the last element of I .
	auto p3{ I.begin() };
	for (size_t i = 0; i < I.size(); ++i) {//size_t is non-negative int
		node* p2 = new node(*p1);
		p2->next = head;
		head = p2;
		p1--;
	}
	for (size_t i = 0; i < I.size(); ++i) {//size_t is non-negative int
		node* p4 = new node(*p3);
		p4->previous = tail;
		tail = p4;
		p3++;
	}
}


void DoublyLinkedList::print_f() {//print forward from head
	if (!head) return;
	cout << endl;
	node* p1 = head;
	while (p1) {
		cout << p1->value << " ";
		p1 = p1->next;
	}
}
void DoublyLinkedList::print_r() {//print backward from tail
	if (!head) return;
	cout << endl;
	node* p1 = tail;
	while (p1) {
		cout << p1->value << " ";
		p1 = p1->previous;
	}
}


int main() {
	DoublyLinkedList L1(20, 10);
	L1.print_f();
	L1.print_r();
	L1.reverse();
	L1.print_f();
	L1.print_r();
	L1.remove_all(7);
	L1.print_f();
	L1.print_r();
	L1.sort();
	L1.print_f();
	L1.print_r();


	DoublyLinkedList L2{ 4,5,6,7,8 };//Declare and call initializer_list
	L2.print_f();//4 5 6 7 8
	L2.print_r();

	return 0;
}