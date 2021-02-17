#include "Subject.h"

Subject::Subject(string title) {
	this->title = title;
}

Subject* Subject::create(string title) {
	return new Subject(title);
}

Subject* Subject::setDekanat(Dekanat* dekanat) {
	this->dekanat = dekanat;
	dekanat->subjects.push_back(this);
	return this;
}

void Subject::addStudent(Student* student) {
	this->students.push_back(student);
	student->subjects.push_back(this);
}

void Subject::addMark(Student* student, float mark) {
	Mark* newMark = new Mark(student, this, mark);
	markList.push_back(newMark);
	student->markList.push_back(newMark);
	dekanat->progressList.push_back(newMark);
}
