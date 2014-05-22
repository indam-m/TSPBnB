#include "Matrix.h"

Matrix::Matrix(){
	//inf = -1;
	size = CountNode();
	elmts = new int *[size];
	for (int i=0; i<size; i++)
		elmts[i] = new int[size];
	InputElement();
}

Matrix::Matrix(const Matrix& M){
	size = M.size;
	elmts = new int *[size];
	for (int i=0; i<size; i++)
		elmts[i] = new int[size];
	for (int i=0; i<size; i++){
		for (int j=0; j<size; j++)
			elmts[i][j] = M.elmts[i][j];
	}
}

int Matrix::getElmt(int i, int j){
	return elmts[i-1][j-1];
}

int Matrix::getNB(){
	return size;
}

int Matrix::CountNode(){
	ifstream file("input0.txt");
	string line;
	getline (file,line);
	file.close();

	int i=0, count=0;
	while(i < line.length()){
		do{
			i++;
		} while (line[i]!=' ' && i<line.length());
		count++;
	}
	return count;
}

void Matrix::InputElement(){
	ifstream file("input0.txt");
	string line; int i=0,j,k,l;
	while (getline (file,line)){
		j=0;
		stringstream stream(line);
		while (stream.good() && j<size){
			stream >> elmts[i][j];
			j++;
		}
		i++;
	}
	file.close();
}

int Matrix::SmallestNumRow(int row){
	int i=0;
	while (elmts[row-1][i]==inf && i<size-1)
		i++;
	if (i==size)
		return inf;
	else{
		int min = elmts[row-1][i];
		i++;
		while (i<size){
			if (elmts[row-1][i] < min && elmts[row-1][i]!=inf)
				min = elmts[row-1][i];
			i++;
		}
		return min;
	}
}

int Matrix::SmallestNumCol(int col){
	int i=0;
	while (elmts[i][col-1]==inf && i<size-1)
		i++;
	if (i==size)
		return inf;
	else{
		int min = elmts[i][col-1];
		i++;
		while (i<size){
			if (elmts[i][col-1] < min && elmts[i][col-1]!=inf)
				min = elmts[i][col-1];
			i++;
		}
		return min;
	}
}

void Matrix::SetInfinite(int i, int j){
	for (int k=0; k<size; k++){
		elmts[i-1][k] = inf;
		elmts[k][j-1] = inf;
	}
	elmts[j-1][0] = inf;
}

int Matrix::ReducedCostMatrix(){
	int min, cost=0;
	// reducing rows
	for (int i=1; i<=size; i++){
		min = SmallestNumRow(i);
		if (min != inf && min > 0){
			for (int j=0; j<size; j++){
				if (elmts[i-1][j]!=inf)
					elmts[i-1][j] -= min;
			}
			cost += min;
		}
	}
	// reducing columns
	for (int i=1; i<=size; i++){
		min = SmallestNumCol(i);
		if (min != inf && min > 0){
			for (int j=0; j<size; j++){
				if (elmts[j][i-1]!=inf)
					elmts[j][i-1] -= min;
			}
			cost += min;
		}
	}
	return cost;
}

void Matrix::PrintMatrix(){
	for (int i=0; i<size; i++){
		for (int j=0; j<size; j++){
			cout << elmts[i][j] << " ";
		}
		cout << endl;
	}
}