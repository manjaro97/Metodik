#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "Person.h"
#include "MyPrint.h"
#include "functor.h"
#include "MyBinOp.h"

int main()
{
	std::cout << "------------Task 1------------" << std::endl;
	//Creating objects of designed class
	Person A("Jonas", 21);
	Person B("Herman", 25);
	Person C("William", 20);
	Person D("Anton", 40);
	Person E("Filip", 15);
	Person F("Filip", 27);
	Person G("Kristoffer", 46);
	Person H("Herman", 26);
	//Creating Array of objects of designed class
	Person PersonArray[] = { A, B, C, D, E, F, G, H };
	//Creating Vector with objects of designed class
	std::vector<Person> PersonVector (std::begin(PersonArray), std::end(PersonArray));
	//Task 1, Print Vector contents
	std::for_each(PersonVector.begin(), PersonVector.end(), MyPrint()); 
	
	std::cout << std::endl << "------------Task 2------------" << std::endl;
	functor IsGreater;
	int age = 30;
	auto foundvalue = std::find_if(PersonVector.begin(), PersonVector.end(), [&](auto& e) {return IsGreater(e, age); });
	//Task 2, print Person older than a certain age 
	std::cout << "First Person older than " << age << ": " << foundvalue->getName() << " (" << foundvalue->getAge() << " y/o)" << std::endl;
	
	std::cout << std::endl << "------------Task 3------------" << std::endl;
	auto pairnames = std::adjacent_find(PersonVector.begin(), PersonVector.end());
	if (pairnames == PersonVector.end()) {
		std::cout << "no matching adjacent elements\n";
	}
	else {
		std::cout << "The first adjacent pair of equal elements at: " << std::distance(PersonVector.begin(), pairnames) << '\n';
		std::cout << "Named: " << pairnames->getName() << std::endl;
	}	

	std::cout << std::endl << "------------Task 4------------" << std::endl;
	if (std::equal(PersonVector.begin(), PersonVector.end(), PersonArray))
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";
	

	std::cout << std::endl << "------------Task 5------------" << std::endl;
	auto SubsequenceFound = std::search(PersonVector.begin(), PersonVector.end(), std::begin(PersonArray), std::end(PersonArray));

	if (SubsequenceFound != PersonVector.end()) {
		std::cout << "Subsequence found at position " << (SubsequenceFound - PersonVector.begin()) << '\n';
		while (SubsequenceFound != PersonVector.end()) {
			std::cout << SubsequenceFound->getName() << std::endl;
			SubsequenceFound++;
		}
	}
	else
		std::cout << "Subsequence not found\n";

	std::cout << std::endl << "------------Task 6------------" << std::endl;
	MyBinOp BinOp(PersonVector.size());
	auto sum = std::accumulate(PersonVector.begin(), PersonVector.end(), 0, [&](double x, Person& e) {return x + BinOp(e);});
	std::cout << "The average age is: " << sum << std::endl;

	std::cout << std::endl << "------------Task 7------------" << std::endl;
	std::vector<Person> v2(PersonVector.size());
	MyUnOp UnOp();
	std::transform(PersonVector.begin(), PersonVector.end(), v2.begin(), [&](Person& e) {return UnOp(e); });


	std::cin.get();
	return 0;
}