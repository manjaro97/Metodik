#include "MyPrint.h"

void MyPrint::operator()(const Person & person)
{
	std::cout << person.name << " " << person.age << std::endl;
}
