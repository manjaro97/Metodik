#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
public:
	Person(std::string name = "", double age = 0);
	bool operator== (const Person& rhs);
	std::string getName();
	double getAge();
	~Person();
private:
	size_t size;
	std::string name;
	double age;
	friend class MyPrint;
	friend class functor;
	friend class MyBinOp;
	friend class MyUnOp;
};

#endif