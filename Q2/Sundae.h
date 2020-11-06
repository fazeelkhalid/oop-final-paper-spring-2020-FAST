#define Sundae_H
#ifndef Sundae_H
#include<iostream>
#include"DessertItem.h"
#include"IceCream.h"
using namespace std;

class Sundae :public IceCream {
private:
	int Topoing;
public:
	Sundae() {
		Topoing = 40;
	}
	Sundae(int t,int p, char*f,char *n) : IceCream(p, f, n) {
		Topoing = t
	}
	Sundae(const Sundae&c, const IceCream& n, const DessertItemp & d) : IceCream(n,d) {
		Topoing = c.Topoing;
		
	}
	int getCost() {
		return (price + Topoing);
	}
	int getText() {
		//return ();
	}
	~Sundae() {
		delete[]flavor;
		flavor = NULL;
		price = 0;
	}
};

#endif // !IceCream_H
