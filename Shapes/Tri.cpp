#include "Tri.h"
#include "Tri.h"

Tri::Tri(Point P1, Point P2,Point P3, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}

Point Tri::getcorn1()
{
	return Corner1;
}

Point Tri::getcorn2()
{
	return Corner2;
}

Point Tri::getcorn3()
{
	return Corner3;
}

Tri::~Tri()
{}

void Tri::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->Draw_Tri(Corner1, Corner2, Corner3, ShpGfxInfo);
}
