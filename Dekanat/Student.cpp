#include "Student.h"

Student::Student(string lastName, string firstName, string secondName, int age) {
	this->lastName = lastName;
	this->firstName = firstName;
	this->secondName = secondName;
	this->age = age;
	this->dekanat = dekanat;
}

Student* Student::create(string lastName, string firstName, string secondName, int age) {
	return new Student(lastName, firstName, secondName, age);
}

Student* Student::setDekanat(Dekanat* dekanat) {
	this->dekanat = dekanat;
	dekanat->students.push_back(this);
	return this;
}

void Student::setGroup(Group* group) {
	this->group = group;
	group->studets.push_back(this);
}

void Student::addSubject(Subject* subject) {
	this->subjects.push_back(subject);
	subject->students.push_back(this);
}

void Student::addMark(Subject* subject, float mark) {
	Mark* newMark = new Mark(this, subject, mark);
	this->markList.push_back(newMark);
	subject->markList.push_back(newMark);
	this->dekanat->progressList.push_back(newMark);
}
