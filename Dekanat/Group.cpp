#include "Group.h"

Group* Group::undefinedGroup = NULL;

Group::Group(string title) {
	this->title = title;
}

Group* Group::getUndefinedGroup()
{
	if (Group::undefinedGroup == NULL) {
		return Group::undefinedGroup = new Group("Группа неопределена");
	}
	else {
		return Group::undefinedGroup;
	}
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
