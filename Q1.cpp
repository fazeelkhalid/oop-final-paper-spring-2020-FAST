#include<iostream>
#include<fstream>
using namespace std;
class compactmatrix {
private:
	int rows;
	int coloum;
	int ** mat;
public:
	compactmatrix();
	compactmatrix(compactmatrix&c);
	compactmatrix(int ** array, int row, int colm);
	friend ostream & operator<<(ostream & out, compactmatrix & c);
	~compactmatrix();
};

compactmatrix::compactmatrix(compactmatrix&c) {
	rows = c.rows;
	coloum = c.coloum;
	int temp;
	mat = new int *[rows];
	int i = 0;
	while (i < rows) {
		int add = 0;
		int indicator = 1;
		int j = 0;
		while (j < coloum) {
			if (mat[i][j] != 0) {
				add++;
			}
			j++;
		}
		j = 0;
		temp = (add * 2) + 1;
		mat[i] = new int[temp];
		mat[i][0] = add;
		while (j < coloum) {
			if (mat[i][j] != 0) {
				mat[i][indicator] = j;
				indicator++;
				mat[i][indicator] = mat[i][j];
				indicator++;
			}
			j++;
		}
		i++;
	}

}

// default constructor
compactmatrix::compactmatrix() {
	rows = 0;
	coloum = 0;
	mat = nullptr;
}
// parameterized constructor
compactmatrix::compactmatrix(int ** array, int row, int colm) {
	rows = row;
	coloum = colm;
	int temp;
	mat = new int *[rows];
	int i = 0;
	while(i<row){
		int add = 0;
		int indicator = 1;
		int j = 0;
		while (j < colm) {
			if (array[i][j] != 0) {
				add++;
			}
			j++;
		}
		j = 0;
		temp = (add * 2) + 1;
		mat[i] = new int[temp];
		mat[i][0] = add;
		while (j < colm) {
			if (array[i][j] != 0) {
				mat[i][indicator] = j;
				indicator++;
				mat[i][indicator] = array[i][j];
				indicator++;
			}
			j++;
		}
		i++;
	}
}
compactmatrix::~compactmatrix() {
	for (int i = 0; i < rows; i++) {
		delete[] mat[i];
	}
	delete[]mat;
}

ostream & operator<<(ostream & out, compactmatrix & c) {
	int i = 0;
	while (i < c.rows) {
		out << "Row #  =  " << i + 1 << "\t\t";
		int j = 0;
		while (j < (1 + (c.mat[i][0] * 2))) {
			out << c.mat[i][j] << " ";
			j++;
		}
		out<< endl;
		j = 0;
		while (j < 60) {
			cout << "_";
			j++;
		}
		out << endl;
		i++;
	}
	return out;
}



void main() {
	const int rows = 3, cols = 7;
	int m1[rows][cols] = { {3,0,0,1,0,0,0},{0,0,9,0,0,0,0},{7,12,9,0,8,2,8} };
	int m2[rows][cols] = { {0,0,0,1,2,0,8},{ 0,0,0,0,0,0,0},{ 7,0,3,0,2,0,0} };
	int *matrix1[rows];
	int *matrix2[rows];  //array of pointers same as int*
	for (int i = 0; i < rows; i++)
	{
		matrix1[i] = m1[i];
		matrix2[i] = m2[i];
	}
	cout << " First Matrix is : " << endl;

	compactmatrix compactMatrix1(matrix1, rows, cols);

	cout << compactMatrix1 << endl;
	cout << "\n\n + \n\n";
	cout << " Second Matrix is : " << endl;

	compactmatrix compactMatrix2(matrix2, rows, cols);
	cout << compactMatrix2 << endl;
	cout << "\n\n = \n\n"; // in the given piece of code or in the given instruction. there was no mention that what we should need to print after = sign
	system("pause");
}