#ifndef MYUNOP_H
#define MYUNOP_H

#include "Person.h"

class MyUnOp
{
public:
	double operator()(const Person& person) {
		return person.age;
	}
};

#endif