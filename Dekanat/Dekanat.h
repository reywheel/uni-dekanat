#pragma once
#ifndef DEKANAT_H
#define DEKANAT_H

#include "Student.h"
#include "Subject.h"
#include "Group.h"
#include "Mark.h"

#include <string>
#include <vector>
using namespace std;

class Student;
class Subject;
class Group;
class Mark;

class Dekanat {
private:
	string title;
	vector<Student*> students;
	vector<Subject*> subjects;
	vector<Group*> groups;
	vector<Mark*> progressList;

public:
	friend class Student;
	friend class Group;
	friend class Subject;

	Dekanat(string title);

	// Функции добавления сущностей

	Dekanat* addStudent(Student* student);

	Dekanat* addGroup(Group* group);

	Dekanat* addSubject(Subject* subject);

	Dekanat* addMark(Student* student, Subject* subject, float mark);

	// Функции удаления сущностей

	void removeSubject(Subject* subject);

	void removeGroup(Group* group);

	// Функции поиска сущностей

	Student* findStudent(string lastName);

	Group* findGroup(string title);

	Subject* findSubject(string title);

	// Функции вывода сущностей

	void printStudents();

	void printGroups();

	void printSubjects();
};

#endif