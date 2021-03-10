#include "Archivator.h"

void Archivator::addGroup(string groupInfoString)
{
	vector<string> chunks = this->split(groupInfoString, ';');
	Group* newGroup = new Group(chunks[1]);
	if (chunks[2] == "1") newGroup->remove();
	this->dekanat->addGroup(newGroup);
}

void Archivator::addSubject(string subjectInfoString)
{
	vector<string> chunks = this->split(subjectInfoString, ';');
	Subject* newSubject = new Subject(chunks[1]);
	if (chunks[2] == "1") newSubject->remove();
	this->dekanat->addSubject(newSubject);
}

void Archivator::addStudent(string studentInfoString)
{
	vector<string> chunks = this->split(studentInfoString, ';');
	Student* newStudent = new Student(chunks[1], chunks[2], chunks[3], stoi(chunks[4]));
	if (chunks[5] == "1") newStudent->remove();
	this->dekanat->addStudent(newStudent);
}

void Archivator::addBindStudentToSubject(string bindInfoString)
{
	vector<string> chunks = this->split(bindInfoString, ';');
	Student* student = this->dekanat->findStudent(chunks[1]);
	Subject* subject = this->dekanat->findSubject(chunks[2]);
	student->addSubject(subject);
}

void Archivator::addBindStudentToGroup(string bindInfoString)
{
	vector<string> chunks = this->split(bindInfoString, ';');
	Student* student = this->dekanat->findStudent(chunks[1]);
	Group* group = this->dekanat->findGroup(chunks[2]);
	student->setGroup(group);
}

void Archivator::addBindStudentToMark(string bindInfoString)
{
	vector<string> chunks = this->split(bindInfoString, ';');
	Student* student = this->dekanat->findStudent(chunks[1]);
	Subject* subject = this->dekanat->findSubject(chunks[2]);
	student->addMark(subject, std::stof(chunks[3]));
}


vector<string> Archivator::split(string stroke, char separator)
{
	vector<string> vec;
	int position;
	string word;

	while (stroke.length()) {
		position = stroke.find(separator);
		word = stroke.substr(0, position);
		vec.push_back(word);
		stroke.erase(0, position + 1);
	}

	return vec;
}

void Archivator::serialize(Dekanat* dekanat, string filename) {
	ofstream fout(filename);

	if (fout.is_open()) {
		for (auto group : dekanat->groups) {
			fout << "group" << ";";
			fout << group->title << ";";
			fout << group->isDeleted << ";";
			fout << "%";
		}

		for (auto subject : dekanat->subjects) {
			fout << "subject" << ";";
			fout << subject->title << ";";
			fout << subject->isDeleted << ";";
			fout << "%";
		}

		for (auto student : dekanat->students) {
			fout << "student" << ";";
			fout << student->lastName << ";";
			fout << student->firstName << ";";
			fout << student->secondName << ";";
			fout << student->age << ";";
			fout << student->isDeleted << ";";
			fout << "%";
		}

		for (auto student : dekanat->students) {
			for (auto subject : student->subjects) {
				fout << "student-subject" << ";";
				fout << student->lastName << ";";
				fout << subject->title << ";";
				fout << "%";
			}

			for (auto mark : student->markList) {
				fout << "student-mark" << ";";
				fout << student->lastName << ";";
				fout << mark->subject->title << ";";
				fout << mark->mark << ";";
				fout << "%";
			}

			fout << "student-group" << ";";
			fout << student->lastName << ";";
			fout << student->group->title << ";";
			fout << "%";
		}
	}
}

Dekanat* Archivator::unserialize(string filename) {
	ifstream fin(filename);
	string buff;
	string type;
	string delim = "%";
	this->dekanat = new Dekanat("New dekanat");

	if (fin.is_open()) {
		while (getline(fin, buff, '%')) {
			type = buff.substr(0, buff.find(";"));

			if (type == "group") this->addGroup(buff);
			if (type == "subject") this->addSubject(buff);
			if (type == "student") this->addStudent(buff);
			if (type == "student-subject") this->addBindStudentToSubject(buff);
			if (type == "student-group") this->addBindStudentToGroup(buff);
			if (type == "student-mark") this->addBindStudentToMark(buff);
		}
	}

	return this->dekanat;
}

