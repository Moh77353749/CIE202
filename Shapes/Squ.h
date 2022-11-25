#pragma once

#include "shape.h"

class Squ : public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	Squ(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Squ();
	virtual void Draw(GUI* pUI) const;
};
