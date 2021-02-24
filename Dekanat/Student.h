#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "Group.h"
#include "Dekanat.h"
#include "Subject.h"
#include "Mark.h"

#include <string>
#include <vector>

class Student {
public:
	string firstName;
	string lastName;
	string secondName;
	int age;
	Group* group;
	vector<Subject*> subjects;
	Dekanat* dekanat;
	vector<Mark*> markList;
	bool isDeleted = false;

	Student(string lastName, string firstName, string secondName, int age);

	static Student* create(string lastName, string firstName, string secondName, int age);
	
	void remove();

	// Добавление сущностей

	Student* setDekanat(Dekanat* dekanat);

	void setGroup(Group* group);

	void addSubject(Subject* subject);

	void addMark(Subject* subject, float mark);

	// Удаление сущностей

	void removeSubject(Subject* subject);

	void removeGroup();

};

#endif
