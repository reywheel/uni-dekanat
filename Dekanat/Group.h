#pragma once
#ifndef GROUP_H
#define GROUP_H

#include "Student.h"
#include "Dekanat.h"

#include <string>
#include <vector>
using namespace std;

class Student;
class Dekanat;

class Group {
private:
	static Group* undefinedGroup;
public:
	string title;
	vector<Student*> studets;
	Dekanat* dekanat;
	friend class Dekanat;

	Group(string title);

	static Group* getUndefinedGroup();

	static Group* create(string title);

	Group* setDekanat(Dekanat* dekanat);

	void addStudent(Student* student);
};

#endif