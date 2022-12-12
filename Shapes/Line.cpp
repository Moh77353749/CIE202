#include "Line.h"
#include "..\GUI\GUI.h"

Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
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

// ;
Line::~Line()
{}

void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->Draw_Line(Corner1, Corner2, ShpGfxInfo);
}