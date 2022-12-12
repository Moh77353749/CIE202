#include "Rect.h"

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

bool Rect::checkInside(Point p)
{
	if (((p.x > Corner1.x) && (p.x < Corner2.x)) && ((p.y > Corner1.y) && (p.y < Corner2.y)))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->Draw_Rect(Corner1, Corner2, ShpGfxInfo);
}