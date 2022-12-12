#pragma once
#include "Shape.h"
#include <fstream>
#include "..\controller.h"
#include <vector>
using namespace std;

//forward decl
class GUI;	
class controller;
//A class that is responsible on everything related to shapes
class Graph
{
	controller* cont;
	GUI* Pin;
private:
	vector <shape*> shapesList; //a container to hold all shapes							   
	shape* selectedShape;	//pointer to the currently selected shape
	int Fc;
public:										
	Graph();
	~Graph();
	void setshape(shape* sh);
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	shape* Getshape(Point) ; //Search for a shape given a point inside the shape
	void Delshape();
	//void Save(ofstream& outfile);	//Save all shapes to a file
	// void load(ifstream& inputfile);	//Load all shapes from a file
};
