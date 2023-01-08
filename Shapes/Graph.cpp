#include<iostream>
#include "Graph.h"
#include "..\controller.h"
#include <vector>
#include "../GUI/GUI.h"
using namespace std;
Graph::Graph()
{	
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
	pUI->drawcolor();

	for (auto shapePointer : shapesList) {
		shapePointer->Draw(pUI);
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
			if (shapesList[i]->IsSelected() == FALSE)
			{
				shapesList[i]->SetSelected(1);
				selectedShape = shapesList[i];
				return shapesList[i];
			}
			else
			{
				shapesList[i]->SetSelected(0);
			}
		}
		else
		{
			shapesList[i]->SetSelected(0);
		}

	}
}

void Graph::Delshape()
{
	for (int i = 0; i < shapesList.size(); i++) {
		if ((shapesList[i]->IsSelected()) == TRUE) {
			shapesList.erase(shapesList.begin()+i);
		}
	}
}

void Graph::fill(color c)
{
	for (int i = 0; i < shapesList.size(); i++) {
		if ((shapesList[i]->IsSelected() ==TRUE )) {
			shapesList[i]->ChngFillClr(c);
		}
	}
}

void Graph::bordc(color c)
{
	for (int i = 0; i < shapesList.size(); i++) {
		if ((shapesList[i]->IsSelected() == TRUE)) {
			shapesList[i]->ChngDrawClr(c);
		}
	}
}

void Graph::bordw(int xx)
{
	for (int i = 0; i < shapesList.size(); i++) {
		if ((shapesList[i]->IsSelected() == TRUE)) {
			shapesList[i]->ChngBorderWidth(xx);
		}
	}
}


void Graph::Save_shapes(ofstream& outfile)
{
	for (int i = 0; i < shapesList.size(); i++) {
		shapesList[i]->Save(outfile);
	}
}

void Graph::load(ifstream& inputfile)
{
	for (int i = 0; i < shapesList.size(); i++) {
		shapesList[i]->Load(inputfile);
	}
}










