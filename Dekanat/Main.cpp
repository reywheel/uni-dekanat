//Задача 1. Деканат.
//Необходимо реализовать класс, объект которого должен хранить данные об успеваемости студентов.Должна храниться следующая информация : 
// ФИО, возраст, учебная группа, оценки по предметам.
//Функции : добавления и удаления студента, добавление и удаление оценки, предмета, группы. Необходимы функции сериализации и десериализации.
//Функции с отчётами : общий список студентов(либо всех, либо по группам), все оценки указанного студента, все оценки заданной группы по заданному предмету,
// поиск успевающих или отстающих в указанной группе, либо по указанному предмету, либо вообще.

#include "Student.h"
#include "Group.h"
#include "Subject.h"
#include "Dekanat.h"

#include <iostream>
using namespace std;

class Report {

};

int main() {
	setlocale(0, "");

	Dekanat* PhysTech = new Dekanat("PhysTech");

	Student* Kolesnikov = Student::create("Колесников", "Андрей", "Олегович", 21)->setDekanat(PhysTech);
	Student* Zolotchenko = Student::create("Золотченко", "Николай", "Андреевич", 19);
	PhysTech->addStudent(Zolotchenko);

	Group* IS1 = Group::create("ИС-1")->setDekanat(PhysTech);
	Group* IS2 = Group::create("ИС-2");
	PhysTech->addGroup(IS2);

	Subject* informationSystems = Subject::create("Информационные системы")->setDekanat(PhysTech);
	Subject* physics = Subject::create("Физика")->setDekanat(PhysTech);
	Subject* unix = Subject::create("Unix");
	PhysTech->addSubject(unix);

	IS1->addStudent(Kolesnikov);
	Zolotchenko->setGroup(IS2);

	Kolesnikov->addSubject(informationSystems);
	Zolotchenko->addSubject(unix);
	unix->addStudent(Kolesnikov);
	physics->addStudent(Zolotchenko);

	Kolesnikov->addMark(unix, 5);
	Zolotchenko->addMark(physics, 5);
	informationSystems->addMark(Kolesnikov, 5);
	unix->addMark(Zolotchenko, 5);
	PhysTech->addMark(Kolesnikov, physics, 4);
	PhysTech->addMark(Zolotchenko, informationSystems, 4);

	PhysTech->printGroups();
	PhysTech->printStudents();
	PhysTech->printSubjects();

	return 1;
}
