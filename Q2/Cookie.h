#define Cookie_H
#include<iostream>
#include"DessertItem.h"

using namespace std;

class cookie:public DessertItemp {
private:
	int item;
	int price;

public:
	cookie() {
		item = 0;
		price = 130;
	}
	cookie(int i, int p,char *n): DessertItemp(n){
		item = i;
		price = p;
	}
	cookie(const cookie&c, const DessertItemp& n) :DessertItemp(n) {
		item = c.item;
		price = c.price;
	}
	void setItemp(int numberOfItem) {
		item = numberOfItem;
	}
	void setPrice(int p) {
		price = p;
	}
	int getCost() {
		return price;
	}
	int getTex() {
	//	return p*
	}

	~cookie() {
		item = 0;
		price = 0;
	}
};
