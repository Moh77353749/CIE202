#pragma once
#include "Shape.h"
#include <fstream>
#include "..\controller.h"
#include "../operations/operation.h"
#include <vector>
#include <stack>
using namespace std;

//forward decl
class GUI;	
class controller;
//A class that is responsible on everything related to shapes
class Graph
{
protected:
	controller* cont;
	GUI* Pin;
	stack<operation*> stackUndo;
	stack<operation*> stackRedo;
	color j;
private:
	vector <shape*> shapesList; //a container to hold all shapes	
	shape* selectedShape;
	shape* deleted;


public:
	
	Graph();
	~Graph();
	void setshape(shape* sh);
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	void Getshape(Point) ; //Search for a shape given a point inside the shape
	void GetMshape(Point);
	void DelMshape();
	void Delshape();
	void fill(color c);
	void bordc(color c);
	void bordw(int xx);
	void send2b();//send to back

	void add_stack(operation* o);
	void Undo_Actions();
	void Undo_Shape();
	void Redo_Actions();
	void Redo_shapes(shape* s);
	void Redo_del();




	//void stickImage(string st);
	void Save_shapes(ofstream& outfile);	//Save all shapes to a file
	void load(ifstream& inputfile);	//Load all shapes from a file
};
