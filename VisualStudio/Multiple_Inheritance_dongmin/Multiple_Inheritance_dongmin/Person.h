#pragma once
#include<iostream>
#include<string>

class Person
{
private:
	std::string m_strSex;
	int m_iAge;
	std::string m_strName;
public:
	Person();
	~Person();

	void SetPerson();
	void PrintPerson();
};

