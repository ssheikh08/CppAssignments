#include <iostream>
#include <vector>
//#include <list>
//#include <string>

using namespace std;
template <class T> class ThreeD {
public:
	T ht;
	T wid;
	T dep;
	ThreeD() :ht(0), wid(0), dep(0) {}
	ThreeD(T i, T j, T k) :ht(i), wid(j), dep(k) {}
	T getVol() const { return ht * wid * dep; }
	bool operator==(const ThreeD<T>& t) { return getVol() == t.getVol(); }
};

template <class T> class node {
public:
	T value;
	node<T>* next;
	node<T>* previous;
	node<T>() { next = nullptr; previous = nullptr; }
	node<T>(T v) { value = v; next = nullptr; previous = nullptr; }
	bool operator==(const node<T>& t) const { return value == t.value; }
};

template <class T> ostream& operator<<(ostream& str, const ThreeD<T>& t);

template <class T> class linked_list {
public:
	node<T>* head;
	node<T>* tail;
	linked_list() { head = tail = nullptr; }
	linked_list(const initializer_list<T>& V);
	void push_front(T t);
	void push_back(T t);
	bool operator==(const linked_list<T>& L) const;

	linked_list(const linked_list<T>& L); //copy constructor
	linked_list(linked_list<T>&& L); //move constructor
	~linked_list();//destructor
	void operator=(const linked_list<T>& L);//L-value operator=; copy assignment
	void operator=(linked_list<T>&& L);//R-value operator= ; move assignment
	template <class T> friend ostream& operator<<(ostream& str, const linked_list<T>& L);
};

template <class T> ostream& operator<<(ostream& str, const linked_list<T>& L);

template <class T> linked_list<T>::linked_list(const initializer_list<T>& V) : linked_list() {
	//Your code
	for (auto i : V)
	{
		push_back(i);
	}
	cout << "initializer_list LL" << endl;
}

template <class T> linked_list<T>::~linked_list() {  //destructor			
	if (!head) 
	{ 
		return;
	}
	while (head->next)
	{
		auto temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
	head = nullptr;
	tail = nullptr;
	cout << "Destructor LL" << endl;
}

template <class T> linked_list<T>::linked_list(const linked_list<T>& L) : linked_list() { //copy constructor																			  																		  //num_nodes = 0;
	auto copyList = L.head;
	while (copyList)
	{
		push_back(copyList->value);
		copyList = copyList->next;
	}
	cout << "Copy Constructor LL" << endl;
}

template <class T> linked_list<T>::linked_list(linked_list<T>&& L) {//move constructor
	//Your code
	head = L.head;
	tail = L.tail;
	L.tail = nullptr;
	L.head = nullptr;
	cout << "Move Constructor LL" << endl;
}

template <class T> void linked_list<T>::operator=(const linked_list<T>& L) { //Lvalue operator=
//Your code
	if (!head) 
	{ 
		return; 
	}
	while (head->next)
	{
		auto temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
	head = nullptr;
	tail = nullptr;

	auto newList = L.head;
	while (newList)
	{
		push_back(newList.value);
		newList = newList->next;
	}
	cout << "Copy Assignment LL" << endl;
}

template<class T> void linked_list<T>::operator=(linked_list<T>&& L) {//R-value operator=
	if (head)
	{
		auto holderNode = head;
		while (assignNode)
		{
			auto temp = holderNode->next;
			delete temp;
			newNode = holderNode->next;
		}
		delete head;
		head = tail = nullptr;
	}
	head = L.head;
	tail = L.tail;
	L.head = nullptr;
	L.tail = nullptr;
	cout << "Move Assignment LL" << endl;
}


template <class T> void linked_list<T>::push_front(T t) {
	node<T>* p = new node<T>(t);
	if (head == nullptr) { head = tail = p; }
	else {
		p->next = head;
		head->previous = p;
		head = p;
	}
}

template <class T> void linked_list<T>::push_back(T t)
{
	node<T>* p = new node<T>(t);
	if (head == nullptr) { head = tail = p; }

	else {
		p->previous = tail;
		tail->next = p;
		tail = p;
	}
}

template <class T> bool linked_list<T>::operator==(const linked_list<T>& L) const {
	//Your code
}

template <class X> class NODE {
public:
	X value;
	NODE<X>* l_child;
	NODE<X>* r_child;
	NODE<X>* next;
	NODE<X>() : l_child(nullptr), r_child(nullptr), next(nullptr) {}
	NODE<X>(X t) : l_child(nullptr), r_child(nullptr), next(nullptr), value(t) {}
};

template <class X> class Triangle {
public:
	NODE<X>* head;
	Triangle() : head(nullptr) {};
	Triangle(const initializer_list<initializer_list<X>>& I);//initializer_list
	~Triangle();// {};//destructor
	Triangle(const Triangle<X>& T); //copy constructor
	void operator=(const Triangle<X>& T); //copy assignment (Lvalue assignment)
	Triangle<X> ThreeTimes(); //ThreeTimes
	Triangle(Triangle<X>&& T);//move constructor
	void operator=(Triangle<X>&& T);//move assignment (Rvalue assignment)
	bool operator==(const Triangle<X>& T);
};

template <class X> bool Triangle<X>::operator==(const Triangle<X>& T) {
	//Your code

}


template <class X> void Triangle<X>::operator=(Triangle<X>&& T) {//Move assignment (Rvalue assignment)
	//Your code

	cout << "Move Assignment Triangle" << endl;
}

template <class X> Triangle<X>::Triangle(Triangle<X>&& T) {//move constructor
	//Your code
	cout << "Move Constructor Triangle" << endl;

}

template <class X> Triangle<X> Triangle<X>::ThreeTimes() {//ThreeTimes
	/*Triangle<X> T{ *this };
	NODE<X>* iter = T.head;
	NODE<X>* current_row = iter;
	while (current_row)
	{
		if (iter->next == current_row)
		{
			iter->value *= 3;
			iter = current_row->l_child;
			current_row = iter;
		}
		else {
			iter->value *= 3;
			iter = iter->next;
		}
	}*/
	//return T.head;

	cout << "ThreeTimes Triangle" << endl;
}

template <class X> Triangle<X>::~Triangle() {// {};//destructor
	//Your code
	if (!head) { return; }
	NODE<X>* currentRow = head->l_child;
	while (currentRow)
	{
		NODE<X>* currIt = currentRow;
		while (currIt->next->next != currentRow)
		{
			NODE<X>* temp = currIt->next;
			currIt->next = currIt->next->next;
			delete(temp);
		}
		NODE<X>* temp = currIt->next;
		currIt->next = nullptr;
		delete(temp);
		currentRow = currentRow->l_child;
	}

	currentRow = head;
	while (currentRow->l_child)
	{
		NODE<X>* temp = currentRow->l_child;
		currentRow->l_child = currentRow->l_child->l_child;
		delete(temp);
	}
	delete head;
	head = nullptr;
	cout << "Destructor Triangle" << endl;

}

template <class X> void Triangle<X>::operator=(const Triangle<X>& T) {//copy assignment

	if (head) {
		NODE<X>* newhead = this->head;
		NODE<X>* currentRow = newhead->l_child;
		while (currentRow)
		{
			NODE<X>* currIt = currentRow;
			while (currIt->next->next != currentRow)
			{
				NODE<X>* temp = currIt->next;
				currIt->next = currIt->next->next;
				delete(temp);
			}
			NODE<X>* temp = currIt->next;
			currIt->next = nullptr;
			delete(temp);
			currentRow = currentRow->l_child;
		}

		currentRow = newhead;
		while (currentRow->l_child)
		{
			NODE<X>* temp = currentRow->l_child;
			currentRow->l_child = currentRow->l_child->l_child;
			delete(temp);
		}
		delete newhead;
		this->head = nullptr;

	}

	if (T.head) {

		NODE<X>* currentRow = nullptr;
		NODE<X>* prevRow = nullptr;
		NODE<X>* prevIt = nullptr;
		NODE<X>* currIt = nullptr;

		NODE<X>* currentRow_T = T.head;
		NODE<X>* prevRow_T = nullptr;
		NODE<X>* prevIt_T = nullptr;
		NODE<X>* currIt_T = T.head;

		NODE<X>* headNode = new NODE<X>(T.head->value);
		headNode->next = headNode;
		head = headNode;
		prevRow = head;
		prevIt = head;

		currentRow_T = T.head->l_child;
		currIt_T = T.head->l_child;



		while (currentRow_T) {
			if (prevRow) {
				currentRow = prevRow->l_child;
			}
			//Handling first item separately once.
			NODE<X>* newNode = new NODE<X>(currIt_T->value);
			if (!head) {
				head = newNode;
				head->next = head;
			}
			if (!currentRow) {
				currentRow = newNode;
				currIt = currentRow;
			}
			else {
				currIt->next = newNode;
				currIt = newNode;
				newNode->next = currentRow;
			}

			if (prevRow) {
				if (prevIt->l_child) {
					prevIt->r_child = newNode;
					if (prevIt->next != prevRow) {
						prevIt->next->l_child = newNode;
						prevIt = prevIt->next;
					}
				}
				else {
					prevIt->l_child = newNode;
				}
			}
			currIt_T = currIt_T->next;

			while (currIt_T != currentRow_T) {
				NODE<X>* newNode = new NODE<X>(currIt_T->value);
				if (!head) {
					head = newNode;
					head->next = head;
				}
				if (!currentRow) {
					currentRow = newNode;
					currIt = currentRow;
				}
				else {
					currIt->next = newNode;
					currIt = newNode;
					newNode->next = currentRow;
				}

				if (prevRow) {
					if (prevIt->l_child) {
						prevIt->r_child = newNode;
						if (prevIt->next != prevRow) {
							prevIt->next->l_child = newNode;
							prevIt = prevIt->next;
						}
					}
					else {
						prevIt->l_child = newNode;
					}
				}
				currIt_T = currIt_T->next;
			}
			prevRow = currentRow;
			prevIt = prevRow;
			currIt = nullptr;
			prevRow_T = currentRow_T;
			currentRow_T = currentRow_T->l_child;
			currIt_T = currentRow_T;
		}
	}
	cout << "Copy Assignment Triangle" << endl;

}

template <class X> Triangle<X>::Triangle(const Triangle<X>& T) { //copy constructor
	//Your code
	if (T.head) {

		NODE<X>* currentRow = nullptr;
		NODE<X>* prevRow = nullptr;
		NODE<X>* prevIt = nullptr;
		NODE<X>* currIt = nullptr;

		NODE<X>* currentRow_T = T.head;
		NODE<X>* prevRow_T = nullptr;
		NODE<X>* prevIt_T = nullptr;
		NODE<X>* currIt_T = T.head;
		NODE<X>* headNode = new NODE<X>(T.head->value);
		headNode->next = headNode;
		head = headNode;
		prevRow = head;
		prevIt = head;
		currentRow_T = T.head->l_child;
		currIt_T = T.head->l_child;
		while (currentRow_T) {
			if (prevRow) {
				currentRow = prevRow->l_child;
			}
			//Handling first item separately once.
			NODE<X>* newNode = new NODE<X>(currIt_T->value);
			if (!head) {
				head = newNode;
				head->next = head;
			}
			if (!currentRow) {
				currentRow = newNode;
				currIt = currentRow;
			}
			else {
				currIt->next = newNode;
				currIt = newNode;
				newNode->next = currentRow;
			}

			if (prevRow) {
				if (prevIt->l_child) {
					prevIt->r_child = newNode;
					if (prevIt->next != prevRow) {
						prevIt->next->l_child = newNode;
						prevIt = prevIt->next;
					}
				}
				else {
					prevIt->l_child = newNode;
				}
			}
			currIt_T = currIt_T->next;

			while (currIt_T != currentRow_T) {
				NODE<X>* newNode = new NODE<X>(currIt_T->value);
				if (!head) {
					head = newNode;
					head->next = head;
				}
				if (!currentRow) {
					currentRow = newNode;
					currIt = currentRow;
				}
				else {
					currIt->next = newNode;
					currIt = newNode;
					newNode->next = currentRow;
				}

				if (prevRow) {
					if (prevIt->l_child) {
						prevIt->r_child = newNode;
						if (prevIt->next != prevRow) {
							prevIt->next->l_child = newNode;
							prevIt = prevIt->next;
						}
					}
					else {
						prevIt->l_child = newNode;
					}
				}
				currIt_T = currIt_T->next;
			}
			prevRow = currentRow;
			prevIt = prevRow;
			currIt = nullptr;
			prevRow_T = currentRow_T;
			currentRow_T = currentRow_T->l_child;
			currIt_T = currentRow_T;
		}
	}
	cout << "Copy Constructor Triangle" << endl;
}


template <class X> Triangle<X>::Triangle(const initializer_list<initializer_list<X>>& I) {
	//Your code
	NODE<X>* currentRow = nullptr;
	NODE<X>* prevRow = nullptr;
	NODE<X>* prevIt = nullptr;
	NODE<X>* currIt = nullptr;

	for (auto list_of_items : I) {
		if (prevRow) {
			currentRow = prevRow->l_child;
		}
		for (auto item : list_of_items) {
			NODE<X>* newNode = new NODE<X>(item);
			if (!head) {
				head = newNode;
				head->next = head;
			}
			if (!currentRow) {
				currentRow = newNode;
				currIt = currentRow;
			}
			else {
				currIt->next = newNode;
				currIt = newNode;
				newNode->next = currentRow;
			}

			if (prevRow) {
				if (prevIt->l_child) {
					prevIt->r_child = newNode;
					if (prevIt->next != prevRow) {
						prevIt->next->l_child = newNode;
						prevIt = prevIt->next;
					}
				}
				else {
					prevIt->l_child = newNode;
				}
			}
		}
		prevRow = currentRow;
		prevIt = prevRow;
		currIt = nullptr;
	}
	cout << "initializer_list Triangle" << endl;
}

template <class T> ostream& operator<<(ostream& str, const ThreeD<T>& t);


template <class T> ostream& operator<<(ostream& str, const linked_list<T>& L);



template <class X> ostream& operator<<(ostream& str, const Triangle<X>& T);

int main() {


	Triangle<int> T1{ {1},  {2,3},  {4, 5, 6}, {7, 8, 9, 10} };//initializer_list
	cout << T1 << endl;
	Triangle<int> T2{ T1 };
	cout << T2 << endl;
	Triangle<int> T3;
	T3 = T1;
	cout << T3 << endl;
	//Triangle<int> T4;
	//cout << T1.ThreeTimes();
	//cout << T4 << endl;
	Triangle<linked_list<ThreeD<int>>> T5{ {{{3,4,5},{7,1,4},{6,7,3}}}, {{ {5,4,8 },{4,2,16  }, {7, 8, 4} } ,{ { {8,2,4},{8,4,4}}} } };

	cout << T5 << endl;
	return 0;
}

template <class T> ostream& operator<<(ostream& str, const ThreeD<T>& t) {
	str << "(" << " " << t.ht << "," << t.wid << "," << t.dep << " " << ")";
	return str;
}

template <class T> ostream& operator<<(ostream& str, const linked_list<T>& L) {
	//Your code
	str << "[";
	node<T>* newList = L.head;
	while (newList)
	{
		str << newList->value;
		newList = newList->next;
	}
	str << "]";
	return str;
}


template <class X> ostream& operator<<(ostream& str, const Triangle<X>& T) {
	NODE<X>* iter = T.head;
	NODE<X>* current_row = iter;
	while (current_row)
	{
		if (iter == current_row)
		{
			str << "{" << " ";
		}
		if (iter->next == current_row)
		{
			str << iter->value << " " << "}" << endl;
			iter = current_row->l_child;
			current_row = iter;
		}
		else {
			str << iter->value << " ";
			iter = iter->next;
		}
	}
	return str;
}
