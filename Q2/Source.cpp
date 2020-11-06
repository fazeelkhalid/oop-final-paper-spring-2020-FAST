#include<iostream>
#include "order.h"
#include"DessertItem.h"
using namespace std;

void main() {
	int totalOrders;
	cout << "How many orders you want to place: ?";
	cin >> totalOrders;
	DessertItemp *d;
	//order ** ordersList = new order*[totalOrders];
	for (int i = 0; i < totalOrders; i++)
	{
		int itemsCount;
		cout << "How many items you want: ?";
		cin >> itemsCount;
		//ordersList[i] = new order[itemsCount];
		//ordersList[i]->placeOrder();
	}
	//diplay all the orders here
	int TotalCost;
	//Find totalCost (sum of costs of all items in list without tax) and print it.
	int TotalTax;
	//Find totalCost (sum of taxes of all items in list) and print it.
	//delete the dynamially allocated memory.
}