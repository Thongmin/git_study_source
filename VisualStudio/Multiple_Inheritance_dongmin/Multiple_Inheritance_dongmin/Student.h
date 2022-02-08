#pragma once
#include "Person.h"
#include "School.h"

class Student : public Person, public School
{
public:
	Student();
	~Student();
	void Setting();
	void PrintInfo();
};

