#include "Student.h"

Student::Student()
{}

Student::~Student()
{}

void Student::Setting()
{
	SetSchool();
	SetPerson();
}

void Student::PrintInfo()
{
	system("cls");

	PrintSchool();
	PrintPerson();
}
