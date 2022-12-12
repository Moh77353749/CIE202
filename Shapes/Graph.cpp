#include<iostream>
#include "Graph.h"
#include "..\controller.h"
#include <vector>
#include "../GUI/GUI.h"
using namespace std;
Graph::Graph()
{
	Fc = 0;
}

Graph::~Graph()
{
}



//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pShp)
{

	//Add a new shape to the shapes vector
	shapesList.push_back(pShp);	
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	cout << "cleared";
	cout << shapesList.size() << endl;
	for (auto shapePointer : shapesList) {
		shapePointer->Draw(pUI);
		cout << "draw" << endl;
	}
}

void Graph::setshape(shape* sh)
{
	selectedShape = sh;
}

shape* Graph::Getshape(Point p)
{
	for (int i = 0; i < shapesList.size(); i++) {
		if ((shapesList[i]->checkInside(p)) == TRUE) {
			shapesList[i]->SetSelected(1);
			selectedShape = shapesList[i];
			return shapesList[i];
		}
		
	}
}

void Graph::Delshape()
{
	for (int i = 0; i < shapesList.size(); i++) {

		if ((shapesList[i]->IsSelected()) == TRUE) {
			shapesList.erase(shapesList.begin()+i);
			break;
		}	
	}
	cout << "after erase " << shapesList.size() <<endl;
	cont->UpdateInterface();
	
}










