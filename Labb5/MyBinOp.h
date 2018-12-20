#ifndef MYBINOP_H
#define MYBINOP_H

#include <algorithm>
#include "Person.h"

class MyBinOp
{
public:
	MyBinOp(size_t size = 0);
	double operator()(const Person& person);
private:
	size_t size;
};

#endif