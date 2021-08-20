//HW3
//Due: 11:59PM, March 23 (Tuesday)
#include <iostream>
#include<string>
#include<tuple>
#include<map>
#include <vector>
using namespace std;

class course {
public:
	string name;
	int section;
	int credits;
	string grade;
	course() {}
	course(string n, int s, int c, string g) { name = n; section = s; credits = c; grade = g; }
	float num_grade();
	//You might need to implement some overloaded operators here.
};

float course::num_grade()
{
	map<string, float> M{ {"A",4.0000},{"A-",3.667},{"B+",3.3300},{"B",3.000},{"B-",2.798} };
	return M[this->grade];
}

int main() {
	course C1("CIS554", 1, 3, "A-");
	vector<course> v1;
	v1.insert(v1.begin(), C1);
	//cout << v1[0].name;
	tuple<int, float, vector<course>> tup_a(v1[0].section, v1[0].num_grade(), v1);
	vector<course> a = get<2>(tup_a);
	//cout << a[0].name; 
	map<int, tuple<int, float, vector<course>>> map_a;
	map_a[1] = tup_a;
	//cout << get<2>(map_a[1])[0].name;
	tuple<int, float, map<int, tuple<int, float, vector<course>>>> tup_b(1, 3.6, map_a);
	cout << get<2>((get<2>(tup_b))[1])[0].name;
	pair<int, tuple<int, float, map<int, tuple<int, float, vector<course>>>>> pair_A;
	pair_A.first = 23;
	pair_A.second = tup_b;
	cout << endl;
	cout << pair_A.first << "\n";
	cout << get<2>((get<2>(tup_b))[1])[0].name;
	return 0;
}