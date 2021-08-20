//HW2 Shoaib Sheikh
//SU NetId: ssheikh SUID: 631608148

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class node {
public:
	shared_ptr<node> east;
	weak_ptr<node> south;
	int value;
	node() {}
	node(int i) { value = i; }
};

class ring {
public:
	//Implement all functions described below


	shared_ptr<node> head;
	int num_rows;
	int num_cols;
	ring() {}

	//Implement all functions described below
	ring(int i, int j, int k);//constructor
	//i rows and j cols, values randomly distributed in 0 ... k-1
	~ring();//destructor; do as little work as possible
	ring(const ring& r); //copy constructor
	ring(ring&& r); //move constructor
	void operator=(ring&& r);//move assignment
	void operator=(const ring& r); //copy assignment
	ring(const initializer_list<initializer_list<int>>& V);//nested initializer_list
	void DelCol(int i);//delete col i of *this; row numbers start from 0
	void DelRow(int i);//delete row i of *this; col numbers start from 0
	ring Threetimes();
	//return a ring with the same dimenstion as *this, and the value of every node is three times of that of *this.

	friend ostream& operator<<(ostream& str, const ring& R);

};


void ring::DelRow(int i)
{
	if (i == 0)
	{
		shared_ptr<node> fRow = nullptr;
		shared_ptr<node> lRow = head;
		shared_ptr<node> lNode = nullptr;
		for (int row = 0; row < num_rows - 1; row++)
		{
			lRow = lRow->south.lock();
		}
		lNode = lRow;
		while (lNode->east != head)
		{
			lNode = lNode->east;
		}
		head = head->south.lock();
		lNode->east = head;
		lNode->south = head;
		fRow = head;
		while (lRow->east != head)
		{
			lRow->south = fRow->east;
			lRow = lRow->east;
			fRow = fRow->east;
		}
	}

	else if (i == num_rows - 1)
	{
		shared_ptr<node> lNode = nullptr;
		shared_ptr<node> pRow = nullptr;
		shared_ptr<node> fRow = head;
		shared_ptr<node> lRow = head;

		for (int r = 0; r < num_rows - 1; r++)
		{
			pRow = lRow;
			lRow = lRow->south.lock();
		}
		lNode = pRow;
		for (int c = 0; c < num_cols - 1; c++)
		{
			lNode = lNode->east;
		}
		//cout << lastNode->value;
		lNode->east = head;
		lNode->south = head;
		while (pRow->east != head)
		{
			pRow->south = fRow->east;
			pRow = pRow->east;
			fRow = fRow->east;
		}
	}

	else
	{
		shared_ptr<node> row = head;
		shared_ptr<node> pRow = nullptr;
		shared_ptr<node> nRow = nullptr;
		shared_ptr<node> prev = nullptr;
		for (int r = 0; r < i; r++)
		{
			pRow = row;
			row = row->south.lock();
		}
		prev = pRow;
		nRow = row->south.lock();
		for (int c = 0; c < num_cols - 1; c++)
		{
			pRow = pRow->east;
		}
		pRow->east = nRow;
		while (nRow->east != head)
		{
			prev->south = nRow;
			prev = prev->east;
			nRow = nRow->east;
		}
		prev->south = nRow;
	}
	num_rows = num_rows - 1;
}



void ring::DelCol(int i) {

	if (i == 0)
	{
		shared_ptr<node> lCol = head;
		shared_ptr<node> lNode = nullptr;
		shared_ptr<node> nCol = nullptr;
		for (int col = 0; col < num_cols - 1; col++)
		{
			lCol = lCol->east;
		}
		lNode = lCol;
		for (int row = 0; row < num_rows - 1; row++)
		{
			lNode = lNode->south.lock();
		}

		head = head->east;
		nCol = head;
		lNode->east = head;
		nCol = head;
		lNode->south.lock() = head;
		while (lCol->east != head)
		{
			lCol->east = nCol->south.lock();
			lCol = lCol->south.lock();
			nCol = nCol->south.lock();
		}
	}
	else if (i == num_cols - 1)
	{
		shared_ptr<node> lCol = head;
		shared_ptr<node> fCol = head;
		shared_ptr<node> lNode = nullptr;
		for (int col = 0; col < num_cols - 2; col++)
		{
			lCol = lCol->east;
		}
		lNode = lCol;
		for (int row = 0; row < num_rows - 1; row++)
		{
			lNode = lNode->south.lock();
		}
		lNode->east = head;
		lNode->south.lock() = head;
		while (lCol->east != head)
		{
			lCol->east = fCol->south.lock();
			lCol = lCol->south.lock();
			fCol = fCol->south.lock();
		}
	}
	else
	{
		shared_ptr<node> column = head;
		shared_ptr<node> pCol = nullptr;
		shared_ptr<node> nCol = nullptr;
		shared_ptr<node> next = nullptr;
		shared_ptr<node> prev = nullptr;


		for (int c = 0; c < i; c++)
		{

			pCol = column;
			column = column->east;
		}
		nCol = column->east;
		next = nCol;

		for (int c = 0; c < num_rows; c++)
		{
			pCol->east = nCol;
			prev = pCol;
			pCol = pCol->south.lock();
			column = column->south.lock();
			nCol = nCol->south.lock();
		}
		prev->south = next;
	}
	num_cols = num_cols - 1;

}



ring::ring(ring&& r) {

	head = r.head;
	r.head = nullptr;
	num_rows = r.num_rows;
	num_cols = r.num_cols;
	cout << "Move Constructor" << endl;
}

ring::ring(int i, int j, int k) {
	num_rows = i;
	num_cols = j;
	shared_ptr<node> tail = nullptr;
	head = nullptr;
	for (auto m = 0; m < i * j; m++) {
		if (!head) {
			head = make_shared<node>(rand() % k);
			tail = head;
		}
		else {
			tail->east = make_shared<node>(rand() % k);
			tail = tail->east;
		}
	}
	tail->east = head;
	tail->south = head;
	auto p2 = head;
	for (auto n = 0; n < num_cols; ++n) {
		p2 = p2->east;
	}
	auto p1 = head;

	while (p1 != tail) {
		p1->south = p2;
		if (p2 == tail) p2 = p2->east;
		p1 = p1->east;
		p2 = p2->east;
	}
}

ring::ring(const initializer_list<initializer_list<int>>& V) {
	head = nullptr;
	num_rows = V.size();
	num_cols = V.begin()->size();
	shared_ptr<node> tail = nullptr;

	head = nullptr;
	for (auto row : V) {
		for (auto col : row) {
			if (!head) {
				head = make_shared<node>(col);
				tail = head;
			}
			else {
				tail->east = make_shared<node>(col);
				tail = tail->east;
			}
		}
	}
	tail->east = head;
	tail->south = head;
	auto p2 = head;
	for (auto n = 0; n < num_cols; ++n) {
		p2 = p2->east;
	}
	auto p1 = head;

	while (p1 != tail) {
		p1->south = p2;
		if (p2 == tail) p2 = p2->east;
		p1 = p1->east;
		p2 = p2->east;
	}
}

ring ring::Threetimes()
{
	ring threeTimes(*this);
	auto iter = threeTimes.head;
	while (iter->east != threeTimes.head)
	{
		iter->value = iter->value * 3;
		iter = iter->east;
	}
	iter->value = iter->value * 3;
	cout << "Threetimes" << endl;
	return threeTimes;
}

ostream& operator<<(ostream& str, const ring& R) {
	int cols = R.num_cols;
	int cnt = 0;
	auto iter = R.head;
	while (iter->east != R.head)
	{

		if (cnt == cols)
		{
			str << "\n";
			cnt = 0;
		}

		str << iter->value << " ";
		iter = iter->east;
		cnt += 1;
	}
	str << iter->value << "\n";
	return str;
}

ring::~ring() {
	if (!head) {
		cout << "Destructor" << endl;
		return;
	}
	head->east.reset();
	head.reset();
	cout << "Destructor" << endl;

}

void ring:: operator=(ring&& r)
{
	if (head != nullptr)
	{
		head->east.reset();
		head.reset();
	}
	head = r.head;
	r.head = nullptr;
	num_rows = r.num_rows;
	num_cols = r.num_cols;
	cout << "Move Assignment" << endl;
}


void ring::operator=(const ring& r)
{
	if (head != nullptr)
	{
		head->east.reset();
		head.reset();
	}
	num_rows = r.num_rows;
	num_cols = r.num_cols;
	shared_ptr<node> tail = nullptr;
	head = nullptr;
	auto rNode = r.head;
	if (!rNode) { return; }
	for (auto m = 0; m < num_rows * num_cols; m++) {
		if (!head) {
			head = make_shared<node>(rNode->value);
			rNode = rNode->east;
			tail = head;
		}
		else {
			tail->east = make_shared<node>(rNode->value);
			rNode = rNode->east;
			tail = tail->east;
		}
	}
	tail->east = head;
	tail->south = head;
	auto p2 = head;
	for (auto n = 0; n < num_cols; ++n) {
		p2 = p2->east;
	}
	auto p1 = head;

	while (p1 != tail) {
		p1->south = p2;
		if (p2 == tail) p2 = p2->east;
		p1 = p1->east;
		p2 = p2->east;
	}
	cout << "Copy Assignment" << endl;
}

ring::ring(const ring& r)
{
	num_rows = r.num_rows;
	num_cols = r.num_cols;
	shared_ptr<node> tail = nullptr;
	head = nullptr;
	auto rNode = r.head;
	if (!rNode) { return; }
	for (auto m = 0; m < num_rows * num_cols; m++) {
		if (!head) {
			head = make_shared<node>(rNode->value);
			rNode = rNode->east;
			tail = head;
		}
		else {
			tail->east = make_shared<node>(rNode->value);
			rNode = rNode->east;
			tail = tail->east;
		}
	}
	tail->east = head;
	tail->south = head;
	auto p2 = head;
	for (auto n = 0; n < num_cols; ++n) {
		p2 = p2->east;
	}
	auto p1 = head;

	while (p1 != tail) {
		p1->south = p2;
		if (p2 == tail) p2 = p2->east;
		p1 = p1->east;
		p2 = p2->east;
	}
	cout << "Copy Constructor" << endl;
}

int main() {

	ring R1(4, 6, 20);
	cout << R1 << endl;

	//cout << R1.Threetimes() << endl;

	R1.DelCol(3);
	cout << R1 << endl;
	R1.DelCol(4);
	cout << R1 << endl;
	R1.DelCol(0);
	cout << R1 << endl;

	ring R2(5, 7, 20);
	cout << R2 << endl;
	R2.DelRow(3);
	cout << R2 << endl;
	R2.DelRow(3);
	cout << R2 << endl;
	R2.DelRow(0);
	cout << R2 << endl;

	shared_ptr<ring> p1 = make_shared<ring>(3, 5, 10);
	cout << *p1 << endl;
	p1.reset();

	ring R3 = { {10,20,30,40,50} , {100, 200, 300, 400, 500}, {1000, 2000, 3000, 4000, 5000} };//
	cout << R3 << endl;
	ring R4(R3);
	cout << R4 << endl;
	ring R5;
	R5 = R3;
	cout << R5 << endl;
	ring R6;
	R6 = R5.Threetimes();
	cout << R6 << endl;
	return 0;
}