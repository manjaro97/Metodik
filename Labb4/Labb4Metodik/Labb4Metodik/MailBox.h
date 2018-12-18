#ifndef MAILBOX_H
#define MAILBOX_H

#include <iostream>
#include <vector>
#include "Email.h"
#include <algorithm>

class MailBox
{
public:
	MailBox(size_t n = 0);
	void readvec(int num);
	void writevec(Email e);
	void SortWho();
	void SortDate();
	void SortSubject();
	std::size_t size() const;
	const Email * cbegin() const;
	const Email * cend() const;
	~MailBox();
private:
	std::vector<Email> mail;
};

#endif


