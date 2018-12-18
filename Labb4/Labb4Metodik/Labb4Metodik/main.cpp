// namn p� uppgiften, kursens namn
// f�rfattare 
// filnamn, skapandedatum och datum f�r senaste redigering
// kortfattat vad filen inneh�ller

#include <iostream>
#include "MailBox.h"

template<typename T>
void Show(const T& mailbox) {
	std::for_each(mailbox.cbegin(), mailbox.cend(), [](const Email& email) { std::cout << " " << email << std::endl; });
	std::cout << std::endl;
}

int main()
{
	MailBox Brevl�da(0);
	Email A("Who", "Date", "Subject");
	Brevl�da.writevec(A);
	Email B("Jonas", "123", "Skola");
	Brevl�da.writevec(B);
	Email C("Herman", "321", "Gibba");
	Brevl�da.writevec(C);
	Email D("Anton", "222", "Va?");
	Brevl�da.writevec(D);
	Email E("Philip", "1224", "12Subject21");
	Brevl�da.writevec(E);
	Show(Brevl�da);
	
	Brevl�da.SortWho();
	Show(Brevl�da);

	Brevl�da.SortDate();
	Show(Brevl�da);

	Brevl�da.SortSubject();
	Show(Brevl�da);

	std::cin.get();
	return 0;
}
