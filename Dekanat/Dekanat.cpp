#include "Dekanat.h"

void Dekanat::removeSubject(Subject* subject)
{
	auto removeIterator = find(this->subjects.begin(), this->subjects.end(), subject);
	if (removeIterator != this->subjects.end()) this->subjects.erase(removeIterator);

	for (auto student : this->students) {
		student->removeSubject(subject);
	}
}

void Dekanat::removeGroup(Group* group)
{
	auto removeIterator = find(this->groups.begin(), this->groups.end(), group);
	if (removeIterator != this->groups.end()) this->groups.erase(removeIterator);

	for (auto student : this->students) {
		student->removeGroup();
	}
}

Dekanat::Dekanat(string title) {
	this->title = title;
}

Dekanat* Dekanat::addStudent(Student* student) {
	this->students.push_back(student);
	student->dekanat = this;
	return this;
}

Dekanat* Dekanat::addGroup(Group* group) {
	this->groups.push_back(group);
	return this;
}

Dekanat* Dekanat::addSubject(Subject* subject) {
	this->subjects.push_back(subject);
	subject->dekanat = this;
	return this;
}

Dekanat* Dekanat::addMark(Student* student, Subject* subject, float mark) {
	Mark* newMark = new Mark(student, subject, mark);
	this->progressList.push_back(newMark);
	student->markList.push_back(newMark);
	subject->markList.push_back(newMark);
	return this;
}

Student* Dekanat::findStudent(string lastName) {
	vector<Student*>::iterator student = find_if(this->students.begin(), this->students.end(), [lastName](const Student* student) { return student->lastName == lastName; });
	return *student;
}

Group* Dekanat::findGroup(string title) {
	vector<Group*>::iterator group = find_if(this->groups.begin(), this->groups.end(), [title](const Group* group) { return group->title == title; });
	return *group;
}

Subject* Dekanat::findSubject(string title) {
	vector<Subject*>::iterator subject = find_if(this->subjects.begin(), this->subjects.end(), [title](const Subject* subject) { return subject->title == title; });
	return *subject;
}

void Dekanat::printStudents() {
	for (auto student : this->students) {
		cout << student->lastName << " " << student->firstName << " " << student->secondName << ": " << student->age << ": " << student->group->title << endl;
	}
	cout << endl;
}

void Dekanat::printGroups() {
	for (auto group : this->groups) {
		cout << group->title << endl;
	}
	cout << endl;
}

void Dekanat::printSubjects() {
	for (auto subject : this->subjects) {
		cout << subject->title << endl;
	}
	cout << endl;
}
