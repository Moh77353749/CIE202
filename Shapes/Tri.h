#pragma once
#include "Shape.h"

class Tri : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	Tri(Point, Point,Point, GfxInfo shapeGfxInfo);
	Point getcorn1();
	Point getcorn2();
	Point getcorn3();
	virtual ~Tri();
	virtual void Draw(GUI* pUI) const;

};

