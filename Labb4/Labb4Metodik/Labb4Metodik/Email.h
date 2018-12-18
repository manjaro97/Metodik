#ifndef EMAIL_H
#define EMAIL_H

#include <string>

class Email
{
public:
	Email(std::string w = "", std::string d = "", std::string s = "");
	friend std::ostream& operator<< (std::ostream& out, const Email& print);
	friend struct CompWhoDateSubject;
	friend struct CompDateWhoSubject;
	friend struct CompSubjectWhoDate;
	~Email();
private:
	std::string who;
	std::string date;
	std::string subject;
};

struct CompWhoDateSubject
{
	bool operator() (const Email& lhs, const Email& rhs)
	{
		if(lhs.who < rhs.who)
		{
			return true;
		}
		else if (lhs.who == rhs.who) {
			if (lhs.date < rhs.date)
			{
				return true;
			}
			else if (lhs.date == rhs.date)
			{
				if (lhs.subject < rhs.subject)
				{
					return true;
				}
			}
		}
		return false;
	}
};

struct CompDateWhoSubject
{
	bool operator() (const Email& lhs, const Email& rhs)
	{
		if (lhs.date < rhs.date)
		{
			return true;
		}
		else if (lhs.date == rhs.date)
		{
			if (lhs.who < rhs.who)
			{
				return true;
			}
			else if (lhs.who == rhs.who)
			{
				if (lhs.subject < rhs.subject)
				{
					return true;
				}
			}
		}
		return false;
	}
};

struct CompSubjectWhoDate
{
	bool operator() (const Email& lhs, const Email& rhs)
	{
		if (lhs.subject < rhs.subject)
		{
			return true;
		}
		else if (lhs.subject == rhs.subject)
		{
			if (lhs.who < rhs.who)
			{
				return true;
			}
			else if (lhs.who == rhs.who)
			{
				if (lhs.date < rhs.date)
				{
					return true;
				}
			}
		}
		return false;
	}
};

#endif