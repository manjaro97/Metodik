#ifndef MYPRINT_H
#define MYPRINT_H

#include <iostream>
#include "Person.h"

class MyPrint
{
public:
	void operator()(const Person& person);
};

#endif