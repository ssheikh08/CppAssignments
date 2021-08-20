//HW6.  Due: Wednesday (May 5) at 11:59pm

#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

class myCompareClass {
	//For all comparions, compare the sums of all int objects in the structures.
	//For Hashing function use h(sums int in the sturcture), where hash<int> h;
public:

	bool operator()(int* p1, int* p2) const { return *p1 < *p2; }
	bool operator()(list<set<int*, myCompareClass>*>* p1, list<set<int*, myCompareClass>*>* p2) {
		int sum1{ 0 }, sum2{ 0 };
		for (auto i : *p1) {
			for (auto j : *i) {
				sum1 += *j;
			}
		}
		for (auto i : *p2) {
			for (auto j : *i) {
				sum2 += *j;
			}
		}
		return sum1 < sum2;
	}

	bool operator() (const map < list<set<int*, myCompareClass>*>*, vector<int*>*, myCompareClass >& M1,
		const map < list<set<int*, myCompareClass>*>*, vector<int*>*, myCompareClass >& M2)  const {
		int sum1{ 0 }, sum2{ 0 };
		for (auto i : M1) {
			
			for (auto j : *i.first) {
				for (auto s : *j) {
					sum1 += *s;
				}
			}
			for (auto j : *i.second) {
				sum1 += *j;
			}
		}
		for (auto i : M2) {

			for (auto j : *i.first) {
				for (auto s : *j) {
					sum2 += *s;
				}
			}
			for (auto j : *i.second) {
				sum2 += *j;
			}
		}
		return sum1 < sum2;

	}

	size_t operator() (const map < list<set<int*, myCompareClass>*>*, vector<int*>*, myCompareClass >& M1){
		hash<int> h;
		int sum1{ 0 };
		for (auto i : M1) {

			for (auto j : *i.first) {
				for (auto s : *j) {
					sum1 += *s;
				}
			}
			for (auto j : *i.second) {
				sum1 += *j;
			}
		}
		return h(sum1);

	}

};

class myCompareClass1 {
	//Need a functor for ==
	//For Hashing function use h(sums int in the sturcture), where hash<int> h;
	bool operator() (const map < list<set<int*, myCompareClass>*>*, vector<int*>*, myCompareClass >& M1,
		const map < list<set<int*, myCompareClass>*>*, vector<int*>*, myCompareClass >& M2)  const {
		int sum1{ 0 }, sum2{ 0 };
		for (auto i : M1) {
			for (auto j : *i.first) {
				for (auto s : *j) {
					sum1 += *s;
				}
			}
			for (auto j : *i.second) {
				sum1 += *j;
			}
		}

		for (auto i : M2) {
			for (auto j : *i.first) {
				for (auto s : *j) {
					sum2 += *s;
				}
			}
			for (auto j : *i.second) {
				sum2 += *j;
			}
		}
		return sum1 == sum2;

	}
	size_t operator() (const map < list<set<int*, myCompareClass>*>*, vector<int*>*, myCompareClass >& M1)  {
		hash<int> h;
		int sum1{ 0 };
		for (auto i : M1) {
			for (auto j : *i.first) {
				for (auto s : *j) {
					sum1 += *s;
				}
			}
			for (auto j : *i.second) {
				sum1 += *j;
			}
		}
		return h(sum1);
	
	}

	
};
//You need to implement overloaded operator<< .
ostream& operator<< (ostream& str, const set<map < list<set<int*, myCompareClass>*>*, vector<int*>*, myCompareClass >, myCompareClass>& M1) {
	str << "<";
	for (auto i : M1) {
		str << "<";
			for (auto j : i) {
				str << "{";
				for (auto s : *j.first) {
					str << "<";
					for (auto t : *s) {
						str << *t << " ";
					}
					str << ">";
				}
			}
			str << ",";
			
		for (auto j : i) {
			str << "(";
			for (auto s : *j.second) {
				str << *s << " ";
			}
			str << ")";
		}
		str << "}";
	}
	str << ">";
	return str;
}


int main() {
	set<map < list<set<int*, myCompareClass>*>*, vector<int*>*, myCompareClass >, myCompareClass> S1{  
		{  {new list<set<int*, myCompareClass>*>{new set<int*, myCompareClass>{ new int{6}, new int{8}, new int{0}}, 
		                                         new set<int*, myCompareClass>{ new int{3}, new int{1}, new int{2}},
											     new set<int*, myCompareClass>{ new int{7}, new int{4}, new int{5}}} , 
											   
											     new vector<int*>{ new int{5}, new int{5}, new int{11}} },
		   {new list<set<int*, myCompareClass>*>{new set<int*, myCompareClass>{ new int{55}, new int{65}, new int{14}},
												 new set<int*, myCompareClass>{ new int{77}, new int{88}, new int{25}},
												 new set<int*, myCompareClass>{ new int{52}, new int{44}, new int{12}}} ,

												 new vector<int*>{ new int{45}, new int{65}, new int{12}} },
		   {new list<set<int*, myCompareClass>*>{new set<int*, myCompareClass>{ new int{27}, new int{38}, new int{14}},
												 new set<int*, myCompareClass>{ new int{28}, new int{15}, new int{20}},
												 new set<int*, myCompareClass>{ new int{75}, new int{45}, new int{58}}} ,

												 new vector<int*>{ new int{5}, new int{43}, new int{92}} }},

		 {  {new list<set<int*, myCompareClass>*>{new set<int*, myCompareClass>{ new int{9}, new int{8}, new int{0}},
												 new set<int*, myCompareClass>{ new int{3}, new int{1}, new int{2}},
												 new set<int*, myCompareClass>{ new int{7}, new int{4}, new int{5}}} ,

												 new vector<int*>{ new int{5}, new int{8}, new int{11}} },
		   {new list<set<int*, myCompareClass>*>{new set<int*, myCompareClass>{ new int{55}, new int{65}, new int{14}},
												 new set<int*, myCompareClass>{ new int{77}, new int{88}, new int{25}},
												 new set<int*, myCompareClass>{ new int{52}, new int{44}, new int{12}}} ,

												 new vector<int*>{ new int{45}, new int{56}, new int{12}} },
		   {new list<set<int*, myCompareClass>*>{new set<int*, myCompareClass>{ new int{27}, new int{38}, new int{14}},
												 new set<int*, myCompareClass>{ new int{99}, new int{15}, new int{20}},
												 new set<int*, myCompareClass>{ new int{75}, new int{45}, new int{58}}} ,

												 new vector<int*>{ new int{5}, new int{43}, new int{92}} }}
	};//Create your initial values with at least 3 elements in every STL container. 
	cout << S1 << endl;

	//unordered_set< map < list<set<int*, myCompareClass>*>*, vector<int*>*, myCompareClass >, myCompareClass1, myCompareClass1> H1{ ... };//You can re-use the above.

	//cout << H1 << endl;

	list<list<int>> L1 { { {5}}, { {5}} };
	return 0;
}