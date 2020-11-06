#define DessertItemp_H

#include<iostream>

using namespace std;

class DessertItemp {
private:
	char* name; // not mention in the paper that what is name so i consider that its a company name

public:
	DessertItemp() {
		name = NULL;
	}
	DessertItemp(char* n) {
		int size = strlen(n);
		name = new char[size + 1];
		strcpy_s(name, size, n);
		name[size] = '\0';
	}
	DessertItemp(const DessertItemp& d) {
		int size = strlen(d.name);
		name = new char[size + 1];
		strcpy_s(name, size, d.name);
		name[size] = '\0';
	}

	void getName(const char*n) {
		int size = strlen(n);
		name = new char[size + 1];
		strcpy_s(name, size, n);
		name[size] = '\0';
	}
	char* getName() {
		return name;
	}
	virtual int getCost() {
		return 0;
	}
	virtual int getTex() {
		return 0;
	}

	~DessertItemp() {
		delete[] name;
		name = NULL;
	}
};
