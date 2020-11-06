#define IceCream_H
#ifndef IceCream_H
#include<iostream>
#include"DessertItem.h"

using namespace std;

class IceCream :public DessertItem {
private:
	int price;
	char* flavor;

public:
	IceCream() {
		price = 0;
		flavor = NULL;
	}
	IceCream(int p, char*n, char *f) : DessertItem(f) {
		int size = strlen(n);
		flavor = new char[size + 1];
		strcpy_s(flavor, size, n);
		flavor[size] = '\0';

		price = p;
	}
	IceCream(const IceCream&c, const DessertItem& n) :DessertItem(n) {
		int size = strlen(c.flavor);
		flavor = new char[size + 1];
		strcpy_s(flavor, size, c.flavor);
		flavor[size] = '\0';

		price = c.price;
	}
	void setFlavor() {
		flavor = new char[36];
		cout << "Enter flavor : ";
		cin >> flavor;
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


	~IceCream() {
		delete[]flavor;
		flavor = NULL;
		price = 0;
	}
};

#endif // !IceCream_H
