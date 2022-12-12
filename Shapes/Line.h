#pragma once

#include "shape.h"
#include "..\GUI\GUI.h"
class Line : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point p;
public:
	Line(Point, Point, GfxInfo shapeGfxInfo);
	bool checkInside(Point p) override;
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
	
};

