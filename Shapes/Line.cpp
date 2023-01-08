#include "Line.h"
#include "..\GUI\GUI.h"
#include "../Shapes/Shape.h"
#include <iostream>
using namespace std;
Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	SetID(1);
}

bool Line::checkInside(Point p)
{
	double distance1 = sqrt(pow((p.x - Corner1.x), 2) + pow((p.y - Corner1.y), 2));
	double distance2 = sqrt(pow((p.x - Corner2.x), 2) + pow((p.y - Corner2.y), 2));
	double distance3 = sqrt(pow((Corner2.x - Corner1.x), 2) + pow((Corner2.y - Corner1.y), 2));
	if (distance1 + distance2 == distance3) {
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void Line::Save(ofstream& OutFile)
{
	string fill;
	string colo = save_colors(ShpGfxInfo.DrawClr);
	
	if (ShpGfxInfo.isFilled) {
		fill = save_colors(ShpGfxInfo.FillClr);
	}
	else
	{
		fill = "NON-FILLED";
	}

	OutFile << "Line " << ID << " " << Corner1.x << " " << Corner1.y  << " " << colo << " " << fill << " " << " " << ShpGfxInfo.BorderWdth <<endl;
	
}

shape* Line::Clone(Point c)
{
	Point NewC1, NewC2, midpoint;
	midpoint.x = ((Corner1.x + Corner2.x) / 2);
	midpoint.y = ((Corner1.y + Corner2.y) / 2);
	int xdistance, ydistance;
	xdistance = (midpoint.x - Corner1.x);
	ydistance = (midpoint.y - Corner1.y);
	NewC1.x = c.x - (xdistance);
	NewC1.y = c.y - (ydistance);
	NewC2.x = c.x + (xdistance);
	NewC2.y = c.y + (ydistance);


	shape* Temp = new Line(NewC1, NewC2, ShpGfxInfo);
	return Temp;
}

void Line::Load(ifstream& Infile)
{
	string drawColor, fillColor;
	Infile >> ID >> Corner1.x >> Corner1.y
		>> Corner2.x >> Corner2.y >> drawColor >> fillColor;

	ShpGfxInfo.DrawClr = GetStrinColor2(drawColor);

	if (fillColor == "NON-FILLED")
		ShpGfxInfo.isFilled = false;
	else
	{
		ShpGfxInfo.FillClr = GetStrinColor2(fillColor);
		ShpGfxInfo.isFilled = true;
	}
	ShpGfxInfo.isSelected = false;

}


Line::~Line()
{}

void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->Draw_Line(Corner1, Corner2, ShpGfxInfo);
}

