#include "Person.h"

Person::Person()
{}

Person::~Person()
{}

void Person::SetPerson()
{
	std::cout << "���� �Է� : ";
	std::cin >> m_iAge;
	std::cout << "�̸� �Է� : ";
	std::cin >> m_strName;
	std::cout << "���� �Է� : ";
	std::cin >> m_strSex;
}

void Person::PrintPerson()
{
	std::cout << "���� : " << m_iAge << std::endl << "�̸� : " << m_strName << std::endl << "���� : " << m_strSex << std::endl;
}