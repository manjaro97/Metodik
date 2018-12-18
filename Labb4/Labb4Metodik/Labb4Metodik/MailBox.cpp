#include "MailBox.h"


MailBox::MailBox(size_t n) :
	mail(n){}

void MailBox::readvec(int num)
{
	std::cout << mail[num];
}

void MailBox::writevec(Email e)
{
	mail.push_back(e);
}

void MailBox::SortWho()
{
	 std::sort(mail.begin(), mail.end(), CompWhoDateSubject());
}

void MailBox::SortDate()
{
	std::sort(mail.begin(), mail.end(), CompDateWhoSubject());
}

void MailBox::SortSubject()
{
	std::sort(mail.begin(), mail.end(), CompSubjectWhoDate());
}

std::size_t MailBox::size() const {
	return mail.size();
}
const Email * MailBox::cbegin() const {
	return &(*mail.cbegin());
}
const Email * MailBox::cend() const {
	return cbegin() + size();
}

MailBox::~MailBox()
{
}
