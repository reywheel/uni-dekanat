#include "Group.h"

Group::Group(string title) {
	this->title = title;
}

Group* Group::create(string title) {
	return new Group(title);
}

Group* Group::setDekanat(Dekanat* dekanat) {
	this->dekanat = dekanat;
	dekanat->groups.push_back(this);
	return this;
}

void Group::addStudent(Student* student) {
	this->studets.push_back(student);
	student->group = this;
}
