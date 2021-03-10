//Задача 1. Деканат.
//Необходимо реализовать класс, объект которого должен хранить данные об успеваемости студентов.Должна храниться следующая информация : 
// ФИО, возраст, учебная группа, оценки по предметам.
//Функции : добавления и удаления студента, добавление и удаление оценки, предмета, группы. Необходимы функции сериализации и десериализации.
//Функции с отчётами : общий список студентов(либо всех, либо по группам), все оценки указанного студента, все оценки заданной группы по заданному предмету,
// поиск успевающих или отстающих в указанной группе, либо по указанному предмету, либо вообще.

// TODO:
// Решить с точкой запятой в конце строки при архивации
// Сделать удобнее работу с индексами разбитой строки при разархивации (через массив со строковыми ключами)
// Сделать перенос связей при unzipe
// Передача имени нового деканата при unzipe

#include "Student.h"
#include "Group.h"
#include "Subject.h"
#include "Dekanat.h"
#include "Archivator.h"
#include "Report.h"

#include <iostream>
using namespace std;

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
	Zolotchenko->setGroup(IS1);

	Kolesnikov->addSubject(informationSystems);
	Zolotchenko->addSubject(unix);
	unix->addStudent(Kolesnikov);
	physics->addStudent(Zolotchenko);

	Kolesnikov->addMark(unix, 5);
	Kolesnikov->addMark(unix, 5);
	Zolotchenko->addMark(physics, 3);
	informationSystems->addMark(Kolesnikov, 5);
	unix->addMark(Zolotchenko, 3);
	PhysTech->addMark(Kolesnikov, physics, 4);
	PhysTech->addMark(Zolotchenko, informationSystems, 4);

	Student* Kudryashov = Student::create("Кудряшов", "Алексей", "Алексеевич", 20)->setDekanat(PhysTech);
	Kudryashov->setGroup(IS1);
	Kudryashov->addSubject(unix);
	Kudryashov->addSubject(informationSystems);
	Kudryashov->addSubject(physics);
	Kudryashov->addMark(unix, 4);
	Kudryashov->addMark(informationSystems, 5);
	Kudryashov->addMark(physics, 3);



	/*PhysTech->printGroups();
	IS1->remove();
	PhysTech->printGroups();

	PhysTech->printStudents();
	Kolesnikov->remove();
	PhysTech->printStudents();

	PhysTech->printSubjects();
	unix->remove();
	PhysTech->printSubjects();*/

	Archivator* archivator = new Archivator();
	archivator->serialize(PhysTech, "archive.txt");
	Dekanat* newDekanat = archivator->unserialize("archive.txt");
	newDekanat->printGroups(true);
	newDekanat->printSubjects(true);
	newDekanat->printStudents(true);
	Kolesnikov = newDekanat->findStudent("Колесников");
	Zolotchenko = newDekanat->findStudent("Золотченко");
	cout << Kolesnikov->subjects[1]->title << endl;
	cout << Zolotchenko->subjects[1]->title << endl;
	cout << Kolesnikov->group->title << endl;
	cout << Zolotchenko->group->title << endl;
	cout << Kolesnikov->markList[0]->mark << endl;
	cout << Zolotchenko->markList[0]->mark << endl << endl;

	Report* report = new Report(PhysTech);
	report->printAllStudents();
	report->printStudentMarks("Колесников");
	report->printMarksByGroupAndSubject("ИС-1", "Unix");
	report->printStatisticByGroup("ИС-1", true);
	report->printStatisticByGroup("ИС-1", false);

	return 1;
}
