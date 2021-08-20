//HW3
//Due: 11:59PM, March 23 (Tuesday)

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <tuple>

#include <vector>
#include <iomanip>
using namespace std;

class course {
public:
	string name;
	int section;
	int credits;
	string grade;
	course() {}
	course(string n, int s, int c, string g) { name = n; section = s; credits = c; grade = g; }
	bool operator==(const course& C) const { return name == C.name; }
	bool operator<(const course& C) const { return name < C.name; }
	float num_grade();

	//You might need to implement some overloaded operators here.

};

float course::num_grade() {
	map<string, float> M{
		{"A", 4.000},{"A-", 3.667}, {"B+", 3.333}//...
	};
	return M[grade];

}
//Implement the following functions.
//When adding a student, if the student is already in DB, then ignore the operation.
//When adding a course, if the course is already in DB, then ignore the operation.
//When dropping a course, if the course does not exist, then ignore the operation.
//When removing a student, if the student does not exist, then ignore the operation.
//All courses in a semester need to be sorted.
//When dropping or adding a course, overall GPA, semester GPA, overall credits and semester credits all need to be updated.

//Semeser numbers:  Spring 2019: 20191; Fall 2019: 20192, etc. 

void add_student(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int id);
void remove_student(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int id);
void add_course(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int semester, int id, course c); //20171 Spring semester of 2017; 20172: Fall semester of 2017
																//All courses in the list should be sorted according to name (increasing order)
void drop_course(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int semester, int id, course c);
void print_student_semester_courses(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int semester, int id);
void print_student_all_courses(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int id);

//Implement additional functions such that you can do
//cout << DB << endl;

//You might need to implement some overloaded operators in the course class.

int main() {

	list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>  DB;



	add_student(DB, 11111);
	course C1("CIS554", 1, 3, "A-"), C2("CSE674", 1, 3, "B+"), C3("MAT296", 8, 4, "A"), C4("WRT205", 5, 3, "A");

	add_course(DB, 20171, 11111, C1);
	add_course(DB, 20171, 11111, C4);
	add_course(DB, 20171, 11111, C3);
	add_course(DB, 20171, 11111, C2);
	print_student_semester_courses(DB, 20171, 11111);

	drop_course(DB, 20171, 11111, C1);
	print_student_semester_courses(DB, 20171, 11111); //sorted according to course name

	course C5("CIS351", 2, 3, "A-"), C6("PSY205", 5, 3, "B+"), C7("MAT331", 2, 3, "A"), C8("ECN203", 4, 3, "A");
	add_course(DB, 20172, 11111, C5);
	add_course(DB, 20172, 11111, C6);
	add_course(DB, 20172, 11111, C7);
	add_course(DB, 20172, 11111, C8);
	add_course(DB, 20172, 11111, C3);
	print_student_all_courses(DB, 11111);//ID GPA

	add_student(DB, 11112);
	add_course(DB, 20171, 11112, C2);
	add_course(DB, 20171, 11112, C5);
	add_course(DB, 20171, 11112, C7);
	add_course(DB, 20171, 11112, C4);
	print_student_semester_courses(DB, 20171, 11112);

	add_course(DB, 20172, 11112, C8);
	add_course(DB, 20172, 11112, C3);
	add_course(DB, 20172, 11112, C5);
	add_course(DB, 20172, 11112, C1);
	print_student_semester_courses(DB, 20172, 11112);

	print_student_all_courses(DB, 11112);

	//cout << DB << endl;
	//remove_student(DB, 11111);
	//cout << DB << endl;
	//getchar();
	//getchar();
	return 0;
}

void add_student(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int id) {
	
	/*//Your code
	tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> tup_a;
	pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >* p2 ;
	p2->first = id;
	p2->second = tup_a;
	auto it1{ DB.begin() };
	while (it1 != DB.end()) {

		if ((*it1)->first == id){
		return;
			}
++it1;
	}
	DB.push_back(p2);*/
}

void remove_student(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int id) {
	//Your code
}


void add_course(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int semester, int id, course c) {

	//Your code
}

void drop_course(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int semester, int id, course c) {
	//Your code
}

void print_student_semester_courses(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int semester, int id) {
	//Your code
}
void print_student_all_courses(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int id) {
	//Your code
}


