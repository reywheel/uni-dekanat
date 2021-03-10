#pragma once
#ifndef ARCHIVATOR_H
#define	ARCHIVATOR_H

#include "Dekanat.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Archivator {
private:
	Dekanat* dekanat;

	void addGroup(string groupInfoString);
	void addSubject(string subjectInfoString);
	void addStudent(string studentInfoString);
	void addBindStudentToSubject(string bindInfoString);
	void addBindStudentToGroup(string bindInfoString);
	void addBindStudentToMark(string bindInfoString);
	vector<string> split(string stroke, char separator);
public:
	void serialize(Dekanat* dekanat, string filename);
	Dekanat* unserialize(string filename);
};

#endif // !ARCHIVATOR_H

