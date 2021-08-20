//HW2 Shoaib Sheikh
//SU NetId: ssheikh SUID: 631608148

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
	float num_grade();
	//You might need to implement some overloaded operators here.
};

float course::num_grade()
{
	map<string, float> M{ {"A",4.0000},{"A-",3.667},{"B+",3.3300},{"B",3.000},{"B-",2.700}, {"C+",2.300  },{"C",2.000}, {"C-", 1.700},
		{"D+", 1.300}, {"D", 1.000}, {"D-", 0.700 }, {"F", 0.000} };
	return M[this->grade];
}
ostream& operator<<(ostream& str, const list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*> DB) {
	//str << "(" << t.ht << ", " << t.wid << ", " << t.dep << ")";
	auto itt2 = DB.begin();
	while (itt2 != DB.end()) {

		str << endl;
		str << "Student ID: " << (*itt2)->first << endl;
		str << "Overall GPA: " << setprecision(2) << fixed << (get<1>((*itt2)->second)) << endl;
		str << "Overall Credits " << (get<0>((*itt2)->second)) << endl;

		auto& M2 = (*(get<2>((*itt2)->second)));
		auto itM = M2.begin();
		while (itM != M2.end()) {
			str << "semester: " << itM->first << endl;
			str << "GPA: " << setprecision(2) << fixed << get<1>(itM->second) << endl;
			str << "Credits: " << get<0>(itM->second) << endl;
			auto vect = get<2>(itM->second);
			auto newVect = vect->begin();
			while (newVect != vect->end()) {
				str << "(" << (*newVect)->name << " " << (*newVect)->section << " " << (*newVect)->credits << " " << (*newVect)->grade << ") ";
				newVect++;
			}

			itM++;
		}

		itt2++;
	}
	return str;
}

void add_course(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int semester, int id, course c);
void add_student(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int id);
void print_student_all_courses(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int id);
void print_student_semester_courses(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int semester, int id);
void drop_course(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int semester, int id, course c);
void remove_student(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int id);

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

	cout << DB << endl;
	remove_student(DB, 11111);
	cout << DB << endl;
	getchar();
	getchar();
	return 0;

}


void add_course(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int semester, int id, course c) {
	bool student = false;
	auto iter = DB.begin();
	for (auto it = DB.begin(); it != DB.end(); ++it)
	{
		if ((*it)->first == id)
		{
			student = true;
			iter = it;
		}
	}

	if (!student)
	{
		return;
	}

	if (!(get<2>((*iter)->second)))
	{
		map<int, tuple<int, float, vector<course* >*> >* M1 = new map<int, tuple<int, float, vector<course* >*> >();
		get<2>((*iter)->second) = M1;
		(*M1)[semester] = make_tuple(0, 0.00, nullptr);
	}

	if ((get<2>((*iter)->second))->find(semester) == (get<2>((*iter)->second))->end())
	{
		(*(get<2>((*iter)->second)))[semester] = make_tuple(0, 0.00, nullptr);
	}

	if (!get <2>((*(get<2>((*iter)->second)))[semester]))
	{
		get <2>((*(get<2>((*iter)->second)))[semester]) = new vector<course*>();


	}
	auto& M2 = (*(get<2>((*iter)->second)));
	auto itM = M2.begin();
	while (itM != M2.end()) {
		auto vect = get<2>(itM->second);
		auto newVect = vect->begin();
		while (newVect != vect->end()) {
			if ((*newVect)->name == c.name) {
				return;
			}
			newVect++;
		}

		itM++;
	}

	auto courseVector = get <2>((*(get<2>((*iter)->second)))[semester]);
	auto beginVect = courseVector->begin();

	while (beginVect != courseVector->end()) {
		if (c.name < (*beginVect)->name) {
			break;
		}

		beginVect++;
	}
	course* cNew = new course(c);
	(*courseVector).insert(beginVect, cNew);

	auto cV = get <2>((*(get<2>((*iter)->second)))[semester]);
	auto bV = cV->begin();
	int totalSemCredits = 0;
	float totalSemGpa;
	float weightedGpa = 0;
	float weightedCal = 0;
	while (bV != cV->end()) {
		totalSemCredits += (*bV)->credits;

		bV++;
	}

	auto bV2 = cV->begin();
	while (bV2 != cV->end()) {
		weightedCal += ((*bV2)->credits * (*bV2)->num_grade());
		bV2++;
	}
	weightedGpa = weightedCal / totalSemCredits;

	get <0>((*(get<2>((*iter)->second)))[semester]) = totalSemCredits;
	get <1>((*(get<2>((*iter)->second)))[semester]) = weightedGpa;


	auto& M3 = (*(get<2>((*iter)->second)));
	auto itCal = M3.begin();
	float overallGpa;
	float overallCal = 0;
	int overallCredits = 0;
	while (itCal != M2.end()) {
		overallCredits += get<0>(itCal->second);
		itCal++;
	}


	auto itCal2 = M3.begin();
	while (itCal2 != M3.end()) {
		overallCal += (get<0>(itCal2->second)) * get<1>(itCal2->second);
		itCal2++;
	}
	overallGpa = overallCal / overallCredits;

	(get<0>((*iter)->second)) = overallCredits;
	(get <1>((*iter)->second)) = overallGpa;


}

void add_student(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int id)
{
	auto iter = DB.begin();
	while (iter != DB.end()) {
		if ((*iter)->first == id)
		{
			return;
		}
		iter++;
	}
	pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >* p1 =
		new pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >();

	p1->first = id;
	p1->second = make_tuple(0, 0.00, nullptr);

	DB.push_back(p1);
}

void print_student_semester_courses(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int semester, int id) {


	auto itt2 = DB.begin();
	while (itt2 != DB.end()) {
		if ((*itt2)->first == id) {

			auto& M2 = (*(get<2>((*itt2)->second)));
			auto itM = M2.begin();
			while (itM != M2.end()) {
				if (itM->first == semester) {
					cout << endl;
					cout << "Student ID: " << (*itt2)->first << endl;
					cout << "semester: " << itM->first << endl;
					cout << "GPA: " << setprecision(2) << fixed << get<1>(itM->second) << endl;
					cout << "Credits: " << get<0>(itM->second) << endl;
					auto vect = get<2>(itM->second);
					auto newVect = vect->begin();
					while (newVect != vect->end()) {
						cout << "(" << (*newVect)->name << " " << (*newVect)->section << " " << (*newVect)->credits << " " << (*newVect)->grade << ") ";
						newVect++;
					}
					cout << endl;

				}
				itM++;
			}

		}
		itt2++;
	}
}


void print_student_all_courses(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int id)
{


	auto itt2 = DB.begin();
	while (itt2 != DB.end()) {
		if ((*itt2)->first == id) {
			cout << endl;
			cout << "Student ID: " << id << endl;
			cout << "Overall GPA: " << setprecision(2) << fixed << (get<1>((*itt2)->second)) << endl;
			cout << "Overall Credits " << (get<0>((*itt2)->second)) << endl;

			auto& M2 = (*(get<2>((*itt2)->second)));
			auto itM = M2.begin();
			while (itM != M2.end()) {
				cout << "semester: " << itM->first << endl;
				cout << "GPA: " << setprecision(2) << fixed << get<1>(itM->second) << endl;
				cout << "Credits: " << get<0>(itM->second) << endl;
				auto vect = get<2>(itM->second);
				auto newVect = vect->begin();
				while (newVect != vect->end()) {
					cout << "(" << (*newVect)->name << " " << (*newVect)->section << " " << (*newVect)->credits << " " << (*newVect)->grade << ") ";
					newVect++;
				}
				cout << endl;
				itM++;
			}
		}
		itt2++;
	}

}


void drop_course(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int semester, int id, course c) {

	for (auto itt = DB.begin(); itt != DB.end(); itt++) {
		if ((*itt)->first == id) {
			map<int, tuple<int, float, vector<course* >*> > ::iterator iter = get<2>((*itt)->second)->begin();
			while (iter != get<2>((*itt)->second)->end()) {
				vector <course*>* v2 = get<2>(iter->second);
				for (auto i = v2->begin(); i != v2->end(); i++) {
					if ((*i)->name == c.name) {
						delete(*i);
						v2->erase(i);
						get<0>((*(get<2>)((*itt)->second))[semester]) = get<0>((*(get<2>)((*itt)->second))[semester]) - c.credits;
						break;
					}

				}
				iter++;
			}
			int totalCred = 0;
			float totalGpa = 0.00;
			map<int, tuple<int, float, vector<course* >*> > ::iterator iter2 = get<2>((*itt)->second)->begin();
			while (iter2 != get<2>((*itt)->second)->end()) {
				vector <course*>* v2 = get<2>(iter2->second);
				for (auto i = v2->begin(); i != v2->end(); i++) {
					totalCred += (*i)->credits;
					totalGpa += (*i)->num_grade() * (*i)->credits;
				}
				iter2++;
			}
			get<1>((*(get<2>)((*itt)->second))[semester]) = totalGpa / totalCred;
		}

	}
}


void remove_student(list<pair<int, tuple<int, float, map<int, tuple<int, float, vector<course* >*> >*> >*>& DB, int id) {

	auto it2 = DB.begin();
	while (it2 != DB.end()) {
		if ((*it2)->first == id) {
			auto& M2 = (*(get<2>((*it2)->second)));
			auto itM = M2.begin();
			if (&M2) {
				while (itM != M2.end()) {
					if (get<2>(itM->second)) {
						vector<course*>* V = get <2>(itM->second);
						auto iter = V->begin();
						while (iter != V->end()) {
							delete(*iter);
							iter++;
						}
						delete V;
					}
					itM++;
				}
				delete& M2;

			}
			delete(*it2);
			DB.remove(*it2);
			break;
		}
		it2++;
	}
}
