#ifndef FUNCTOR_H
#define FUNCTOR_H

class functor
{
public:
	//Predicate function object: Bool Functor
	bool operator()(const Person& person, double age) {
		return person.age > age;
	}
};

#endif