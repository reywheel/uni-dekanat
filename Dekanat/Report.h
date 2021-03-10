#pragma once
#ifndef REPORT_H
#define	REPORT_H

#include "Dekanat.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

class Report {
private:
	Dekanat* dekanat;

public:
	Report(Dekanat* dekanat);
	void printAllStudents();
	void printStudentMarks(string studentLastName);
	void printMarksByGroupAndSubject(string groupTitle, string subjectTitle);
	void printStatisticByGroup(string groupTitle, bool isLeaders = true);
	
};

#endif // !REPORT_H

