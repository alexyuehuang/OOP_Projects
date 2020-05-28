// Studio11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
class Student {
public :Student(unsigned int a, string b);
		int getId()const;
		string getName()const;
		void setId(int a);
		void setName(string b);
		bool operator<(const Student& p)const;
		bool operator==(const Student& p)const;
private:
	unsigned int id;
	string name;
};
void Student::setId(int a) {
	(*this).id = a;
}
void Student::setName(string b) {
	this->name = b;
}
int Student::getId() const{
	return this->id;
}
string Student::getName()const {
	return this->name;
}
bool Student::operator<(const Student& p)const {
	if ((*this).getId() < p.getId()) {
		return true;
	}
	return false;
}
bool Student::operator==(const Student& p)const {
	if ((*this).getId() == p.getId()) {
		return true;
	}
	return false;
}
Student::Student(unsigned int a, string b) :
	id(a), name(b){}
ostream& operator<<(ostream& o, const Student& p) {
	o << p.getId() << " and " << p.getName()<<" ";
	return o;
}
istringstream& operator>>(istringstream& o,  Student& p) {
	int a;
	string b;
	o >> a;
	o >> b;
	p.setId(a);
	p.setName(b);
	return o;
}
int main(int argc, char* argv[]) {
	Student a(12, "a");
	Student b(13, "b");
	Student c(14, "c");
	vector<Student> classroom;
	classroom.push_back(b);
	classroom.push_back(a);
	classroom.push_back(c);

	ifstream ifs("text.txt");
	string line;
	while (getline(ifs, line)) {
		int id;
		string name;
		istringstream iss(line);
		Student k(1,"sd");
		iss >> k;
		classroom.push_back(k);
	}
	sort(classroom.begin(), classroom.end());
	for (unsigned int i = 0; i < classroom.size(); ++i) {
		cout << classroom[i] << endl;;
	}
	return 0;
}
