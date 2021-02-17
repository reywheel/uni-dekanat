#pragma once
#ifndef MARK_H
#define MARK_H

#include "Student.h"
#include "Subject.h"

class Student;
class Subject;

class Mark {
public:
	Student* student;
	Subject* subject;
	float mark;

	Mark(Student* student, Subject* subject, float mark);
};

#endif