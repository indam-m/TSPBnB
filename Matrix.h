#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <deque>
using namespace std;

#ifndef _MATRIX_H_
#define _MATRIX_H_

class Matrix
{
private:
	int **elmts;
	int size;
	string input;
public:
	static const int inf = -1;
	Matrix();
	Matrix(const Matrix& M);
	int getElmt(int i, int j);
	int getNB();
	int CountNode();
	void InputElement();
	int SmallestNumRow(int row);
	int SmallestNumCol(int col);
	void SetInfinite(int i, int j);
	int ReducedCostMatrix();
	void PrintMatrix();
};

#endif