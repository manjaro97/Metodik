#include "p_queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct node {
	int price;
	std::string name;
	node(int price, std::string name) :price(price), name(name) {}
	void setPrice(int price) {
		this->price = price;
	}
	int getPrice() {
		return this->price;
	}
	void setName(std::string name) {
		this->name = name;
	}
	std::string getName() {
		return this->name;
	}   
	friend bool operator<(const node &a, const node&b)
	{
		return (a.price < b.price) ? true : false;
	}
};

int main()
{
	p_queue<node> sell;
	p_queue<node> buy; 
	
	srand(time(NULL));
	for (int i = 0; i < 21; i++)
	{
		if(i < 7){
			sell.push({ rand() % 16 + 15, "Erik Pendel" });
			buy.push({ rand() % 16 + 15, "Erik Pendel" });
		}
		else if(i > 13){
			sell.push({ rand() % 16 + 15, "Jarl Wallenburg" });
			buy.push({ rand() % 16 + 15, "Jarl Wallenburg" });
		}
		else{
			sell.push({ rand() % 16 + 15, "Joakim von Anka" });
			buy.push({ rand() % 16 + 15, "Joakim von Anka" });
		}
	}

	int numbuff = 0;
	for (int i = 0; i < 21; i++)
	{
		if (buy.empty()) { break; }
		int num = 0;
		node seller = sell.pop();
		std::cout << "Seller: " << seller.getName() << " " << seller.getPrice() << std::endl;
		while (num == 0) {
			node buyer = buy.pop();
			if (seller.getPrice() <= buyer.getPrice())
			{
				if (buyer.getName() == seller.getName()) {
					std::cout<< "-----------Error-----------" <<std::endl;
				}
				num = 1;
				numbuff++;
				std::cout << "Buyer: " << buyer.getName() << " " << buyer.getPrice() << std::endl << std::endl;
			}
		}
	}
	std::cout << std::endl << "Antal byten: " << numbuff << std::endl << std::endl;

	system("pause");
}
