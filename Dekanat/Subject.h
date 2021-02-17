#pragma once
#ifndef SUBJECT_H
#define SUBJECT_H

#include "Dekanat.h"
#include "Student.h"
#include "Mark.h"

#include <string>
#include <vector>
using namespace std;

class Dekanat;
class Student;
class Mark;

class Subject {
public:
	string title;
	vector<Student*> students;
	vector<Mark*> markList;
	Dekanat* dekanat;

	Subject(string title);

	static Subject* create(string title);

	Subject* setDekanat(Dekanat* dekanat);

	void addStudent(Student* student);

	void addMark(Student* student, float mark);
};

#endif