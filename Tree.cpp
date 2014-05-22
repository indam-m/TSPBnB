#include "Tree.h"

Tree::Tree(){
	if (M.getNB()>0)
		solusi.push_front(0);
}

void Tree::CreateRoot(){
	Node N;
	N.Ms = new Matrix();
	N.cost = N.Ms->ReducedCostMatrix();
	N.lintas = 1;
	N.numparent = -1;
	N.alive = true;
	nodes.push_front(N);
}

void Tree::AddNode(int p, int l){
	Node N;
	N.numparent = p;
	N.lintas = l;
	N.alive = true;
	N.Ms = new Matrix(*(nodes[p].Ms));
	N.Ms->SetInfinite(nodes.at(p).lintas, l);
	N.cost = N.Ms->ReducedCostMatrix() + nodes.at(p).cost + 
				nodes.at(p).Ms->getElmt(nodes.at(p).lintas, l);
	nodes.push_back(N);
}

void Tree::Tracking(){
	int i=0;
	CreateRoot();
	while (solusi.size()<M.getNB()){
		GenerateChildren(i);
		i = LeastCostNode();
		cout << solusi.back() << " "<< nodes[i].numparent << endl;
		//while (solusi.back()!=nodes[i].numparent)
		//	solusi.pop_back();
		solusi.push_back(i);
	}
	for (i=0; i<nodes.size(); i++){
		if (nodes[i].alive)
			nodes[i].alive = false;
	}
	solusi.push_back(0);
}

int Tree::LeastCostNode(){
	int i = 0;
	while (!nodes[i].alive && i<nodes.size())
		i++;
	if (i==nodes.size())
		return -1;
	else{
		int imin = i;
		i++;
		while (i<nodes.size()){
			if (nodes[i].alive && nodes[i].cost<nodes[imin].cost)
				imin = i;
			i++;
		}
		return imin;
	}
}

void Tree::GenerateChildren(int isimp){
	for (int i=1; i<=M.getNB(); i++){
		if (i!=nodes[isimp].lintas && nodes[isimp].Ms->getElmt(nodes[isimp].lintas, i)!=Matrix::inf){
			AddNode(isimp, i);
		}
	}
	nodes[isimp].alive = false;
}

void Tree::PrintSolution(){
	/*for (int i=0; i<nodes.size(); i++){
		cout << i << " :" << endl;
		nodes[i].Ms->PrintMatrix(); cout << endl;}*/
	for (int i=0; i<nodes.size();i++)
		cout << "Cost: " << nodes[i].cost << endl;
	cout << "Solusi: " << endl;
	for (int i=0; i<solusi.size(); i++)
		cout << nodes[solusi[i]].lintas << " ";
	cout << endl;
}