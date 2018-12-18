#include "Email.h"

Email::Email(std::string w, std::string d, std::string s) :
	who(w), date(d), subject(s){}

std::ostream& operator<<(std::ostream & out, const Email & print)
{
	out << print.who << " " << print.date << " " << print.subject;
	return out;
}

Email::~Email(){}