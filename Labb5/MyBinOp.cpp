#include "MyBinOp.h"

MyBinOp::MyBinOp(size_t size) : 
	size(size)
{}

double MyBinOp::operator()(const Person & person)
{
	return person.age / size;
}
