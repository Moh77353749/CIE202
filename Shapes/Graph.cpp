#include "Graph.h"
#include "Line.h"
#include "Tri.h"
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
	for (auto shapePointer : shapesList)
		shapePointer->Draw(pUI);
}

void Graph::setshape(shape* sh)
{
	selectedShape = sh;
}

shape* Graph::Getshape(int x, int y) 
{
	shape* baseptr;
	for (int i = 0; i < shapesList.size(); i++) {

		if (dynamic_cast<Line*>(shapesList[i]))
		{shape* baseptr = shapesList[i];
		Point A = static_cast<Line*>(baseptr)->getcor1();
		Point B = static_cast<Line*>(baseptr)->getcor2();
		double distance1 = sqrt(pow((x - A.x), 2) + pow((y - A.y), 2)); 
		double distance2 = sqrt(pow((x - B.x), 2) + pow((y - B.y), 2)); 
		double distance3 = sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2)); 
		if (distance1 + distance2 == distance3)
		{
			Pout->PrintMessage(" you have selected a line");
			if (selectedShape != nullptr)
			{
				Pout->PrintMessage("un selected");
				baseptr->SetSelected(false);
			}
			else {
				setshape(shapesList.at(i));
				Pout->PrintMessage("selected");
				baseptr->SetSelected(true);}
			    return shapesList.at(i);
		 }}
		else if (dynamic_cast<Tri*> (shapesList[i]))
		{
			shape* baseptr = shapesList[i];
			Point p1 = static_cast<Tri*>(baseptr)->getcorn1();
			Point p2 = static_cast<Tri*>(baseptr)->getcorn2();
			Point p3 = static_cast<Tri*>(baseptr)->getcorn3();
			float a = (((float)p2.y - (float)p3.y) * ((float)x - (float)p3.x) + ((float)p3.x - (float)p2.x) * ((float)y - (float)p3.y)) /
				(((float)p2.y - (float)p3.y) * ((float)p1.x - (float)p3.x) + ((float)p3.x - (float)p2.x) * ((float)p1.y - (float)p3.y));
			float b = (((float)p3.y - (float)p1.y) * ((float)x - (float)p3.x) + ((float)p1.x - (float)p3.x) * ((float)y - (float)p3.y)) /
				(((float)p2.y - (float)p3.y) * ((float)p1.x - (float)p3.x) + ((float)p3.x - (float)p2.x) * ((float)p1.y - (float)p3.y));
			float c = 1.0f - a - b;
			if (a > 0 && b > 0 && c > 0)
			{
				
				Pout->PrintMessage(" you have selected Triangle");
				if (selectedShape != nullptr)
				{
					
					Pout->PrintMessage("un selected");
					baseptr->SetSelected(false);

				}
				else  {
					setshape(shapesList.at(i));
					Pout->PrintMessage("selected");
					baseptr->SetSelected(true);
					return shapesList.at(i);

				}
			}
		}
	}	

	return nullptr;
}





