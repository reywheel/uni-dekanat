#include "Report.h"

Report::Report(Dekanat* dekanat)
{
	this->dekanat = dekanat;
}

void Report::printAllStudents()
{
	cout << "---------- Список всех студентов ----------" << endl;
	cout << setw(10) << left << "Группа";
	cout << setw(15) << left << "Фамилия";
	cout << setw(15) << left << "Имя";
	cout << setw(15) << left << "Отчество";
	cout << setw(4) << left << "Возраст" << endl;

	for (auto student : this->dekanat->students) {
		cout << setw(10) << left << student->group->title;
		cout << setw(15) << left << student->lastName;
		cout << setw(15) << left << student->firstName;
		cout << setw(15) << left << student->secondName;
		cout << setw(4) << left << student->age << endl;
	}
	
	cout << endl;
}

void Report::printStudentMarks(string studentLastName)
{
	Student* student = this->dekanat->findStudent(studentLastName);

	cout << "---------- Оценки студента " << student->lastName << " " << student->firstName << " ----------" << endl;
	cout << setw(30) << left << "Предмет";
	cout << setw(4) << left << "Оценка" << endl;

	for (auto mark : student->markList) {
		cout << setw(30) << mark->subject->title;
		cout << setw(4) << mark->mark << endl;
	}

	cout << endl;
}

void Report::printMarksByGroupAndSubject(string groupTitle, string subjectTitle)
{
	Group* group = this->dekanat->findGroup(groupTitle);
	Subject* subject = this->dekanat->findSubject(subjectTitle);

	cout << "---------- Оценки группы " << group->title << " по предмету " << subject->title << " ----------" << endl;
	cout << setw(30) << left << "Фамилия";
	cout << setw(4) << left << "Оценка" << endl;

	for (auto student : group->studets) {
		cout << setw(30) << left << student->lastName;
		cout << setw(4) << left << "" << endl;

		for (auto mark : student->markList) {
			if (mark->subject->title == subjectTitle) {
				cout << setw(30) << left << "";
				cout << setw(4) << left << mark->mark << endl;
			}
		}
	}

	cout << endl;
}

void Report::printStatisticByGroup(string groupTitle, bool isLeaders)
{
	struct StudentAverageMark {
		Student* student;
		float average;

		StudentAverageMark(Student* student, float average) {
			this->student = student;
			this->average = average;
		}
	};

	vector<StudentAverageMark*> averageMarkList;

	Group* group = this->dekanat->findGroup(groupTitle);
	for (auto student : group->studets) {
		float sum = 0;
		int count = 0;

		for (auto mark : student->markList) {
			sum += mark->mark;
			count++;
		}

		float average = sum / count;
		averageMarkList.push_back(new StudentAverageMark(student, average));
	}

	sort(averageMarkList.begin(), averageMarkList.end(), [](const StudentAverageMark* a, const StudentAverageMark* b) -> bool { return a->average > b->average; });

	if (!isLeaders) reverse(averageMarkList.begin(), averageMarkList.end());
	averageMarkList.resize(3);

	if (isLeaders) cout << "---------- Средние баллы успевающих студентов группы - " << group->title << "----------" << endl;
	else cout << "---------- Средние баллы отстающих студентов группы - " << group->title << "----------" << endl;
	cout << setw(30) << left << "Фамилия";
	cout << setw(4) << left << "Средний балл" << endl;

	for (auto item : averageMarkList) {
		cout << setw(30) << left << item->student->lastName;
		cout << setw(4) << left << item->average << endl;
	}
	
	cout << endl;
}
