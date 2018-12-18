// namn på uppgiften, kursens namn
// författare 
// filnamn, skapandedatum och datum för senaste redigering
// kortfattat vad filen innehåller

#include <iostream>
#include "MailBox.h"

template<typename T>
void Show(const T& mailbox) {
	std::for_each(mailbox.cbegin(), mailbox.cend(), [](const Email& email) { std::cout << " " << email << std::endl; });
	std::cout << std::endl;
}

int main()
{
	MailBox Brevlåda(0);
	Email A("Who", "Date", "Subject");
	Brevlåda.writevec(A);
	Email B("Jonas", "123", "Skola");
	Brevlåda.writevec(B);
	Email C("Herman", "321", "Gibba");
	Brevlåda.writevec(C);
	Email D("Anton", "222", "Va?");
	Brevlåda.writevec(D);
	Email E("Philip", "1224", "12Subject21");
	Brevlåda.writevec(E);
	Show(Brevlåda);
	
	Brevlåda.SortWho();
	Show(Brevlåda);

	Brevlåda.SortDate();
	Show(Brevlåda);

	Brevlåda.SortSubject();
	Show(Brevlåda);

	std::cin.get();
	return 0;
}
