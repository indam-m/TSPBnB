#include "Matrix.h"

#ifndef _TREE_H_
#define _TREE_H_

class Tree {

	struct Node {
		int lintas;
		int cost;
		int numparent;
		bool alive;
		Matrix* Ms;
	};

private:
	Matrix M;
	deque<int> solusi;
	deque<Node> nodes;
public:
	Tree();
	void CreateRoot();
	void AddNode(int p, int l);
	void Tracking();
	int LeastCostNode();
	void GenerateChildren(int isimp);
	void PrintSolution();
};

#endif