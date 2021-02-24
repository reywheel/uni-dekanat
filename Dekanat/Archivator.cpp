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

void Archivator::archive(Dekanat* dekanat, string filename) {
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
	}
}

Dekanat* Archivator::unzip(string filename) {
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
		}
	}

	return this->dekanat;
}

