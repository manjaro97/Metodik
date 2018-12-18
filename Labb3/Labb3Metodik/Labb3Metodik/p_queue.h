#ifndef P_QUEUE_H  //Används för att funktionerna inte ska definieras flera gånger
#define P_QUEUE_H
#include <vector>
#include <algorithm>
#include <functional> 
#include <iostream>
#include <string>

template<typename T>
class p_queue
{
	std::vector<T> prio;
	std::string name;
public:
	p_queue() :
		p_queue("") {}
	p_queue(std::string name) :
		name(name) {}

	T pop()
	{
		if (!empty())
		{
			auto a = prio.front();
			prio.erase(prio.begin()); //Pop_front för vector
			return a;
		}
	}

	void push(T e)
	{
		prio.push_back(e);
		std::sort(prio.begin(), prio.end(), std::less<T>());
	}

	int size() const
	{
		return prio.size();
	}

	bool empty() const
	{
		if (prio.size() > 0)
		{
			return 0;
		} 
		else
		{
			return 1;
		}
	}

	~p_queue()
	{
		while(!empty())
		{
			pop();
		}
	}
};

#endif