#define order_H

#include<iostream>
#include "DessertItem.h"
#include"Cookie.h"
#include"IceCream.h"
#include"Sundae.h"
using namespace std;

class order {
private:
	DessertItemp** itemsList;
	int noOfItems;
public:
	order() {
		itemsList = NULL;
		noOfItems = 0;
	}
	order() {
		itemsList = nullptr;
		noOfItems = 0;
	}
	order(int o) {
		itemsList = new Desertitem*[o];
		noOfItems = o;
	}
	order(order & o) {
		noOfItems = o.noOfItems;
	}
	void placeOrder() {
		int items;
		int price;
		char name[36];
		char flavor[36];
		int userChoice;
		int i = 0, itemCount = 0;
		while (i < this->noOfItems)
		{
			cout << "Choose Item you want to add\n";
			cin >> userChoice;
			if (userChoice == 1) {
				
				cout << "\nHow many cokies you want to get : ";
				cin >> items;
				cout << "\n enter price of each cookie : ";
				cin >> price;
				cout << "\nEnter company name : ";
				cin >> name;
				itemsList[itemCount++] = new cookie(items, price, name);
					
				//making base class pointer //point cookie object
			}
			else if (userChoice == 2)
			{
				cout << "\nEnter Price of each piece : ";
				cin >> price;
				cout << "\nEnter flavor : ";
				cin >> flavor;
				cout << "\nEnter company name : ";
				cin >> name;
				itemsList[itemCount++] = new IceCream(price, flavor, name);
					//making base class pointer //point IceCream object
			}
			else if (userChoice == 3) {
				cout << "\nEnter Price of each piece : ";
				cin >> price;
				cout << "\nEnter flavor : ";
				cin >> flavor;
				cout << "\nEnter company name : ";
				cin >> name;
				itemsList[itemCount++] = new Sundae(40, price, flavor, name);
					//making base class pointer //point Sundae object
			}
			i++;
		}
	}

	~order() {
		for (int i = 0; i < noOfItems; i++) {
			delete []itemsList[i];
		}
		delete[]itemsList;
	}
};
