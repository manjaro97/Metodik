#include "Person.h"



Person::Person(std::string name, double age) :
	name(name), age(age)
{
}

bool Person::operator==(const Person& rhs)
{
	if (name == rhs.name)
	{
		return true;
	}
	return false;
}

std::string Person::getName()
{
	return name;
}

double Person::getAge()
{
	return age;
}


Person::~Person()
{
}
