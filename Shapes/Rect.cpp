#include "Rect.h"
#include "shape.h"

#include <iostream>

using namespace std;



Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	SetID(3);
}

bool Rect::checkInside(Point p)
{
	if ((Corner1.x < Corner2.x) && (Corner1.y < Corner2.y))
	{
		if (((p.x > Corner1.x) && (p.x < Corner2.x)) && ((p.y > Corner1.y) && (p.y < Corner2.y)))return TRUE;
		else return FALSE;
	}
	else
	{
		if (((p.x > Corner2.x) && (p.x < Corner1.x)) && ((p.y < Corner1.y) && (p.y > Corner2.y)))return TRUE;
		else return FALSE;
	}
	
	
}



/* order of the save, 
shape type,id,P1.x, P1.y,P2.x,P2.y, boarder width,draw color, fill color*/
void Rect::Save(ofstream& OutFile)
{
	string fill;
	color j = ShpGfxInfo.FillClr;
	string colo= save_colors(ShpGfxInfo.DrawClr);
	
	if (ShpGfxInfo.isFilled) fill = save_colors(ShpGfxInfo.FillClr);
	else fill = "NON-FILLED";
	OutFile << "RECT " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << colo << " " << fill << " " << ShpGfxInfo.BorderWdth<<endl;
}

void Rect::Load(ifstream& Infile)
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

string Rect::GetF() const
{
	return "Rectangle";
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{	
	pUI->Draw_Rect(Corner1, Corner2, ShpGfxInfo);
}