#include "Person.h"

Person::Person()
{}

Person::~Person()
{}

void Person::SetPerson()
{
	std::cout << "나이 입력 : ";
	std::cin >> m_iAge;
	std::cout << "이름 입력 : ";
	std::cin >> m_strName;
	std::cout << "성별 입력 : ";
	std::cin >> m_strSex;
}

void Person::PrintPerson()
{
	std::cout << "나이 : " << m_iAge << std::endl << "이름 : " << m_strName << std::endl << "성별 : " << m_strSex << std::endl;
}