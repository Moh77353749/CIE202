#pragma once

#include "shape.h"

class Line : public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	Line(Point, Point, GfxInfo shapeGfxInfo);
	Point getcor1();
	Point getcor2();
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
	
};

