#pragma once
#include "Shape.h"
#include "..\GUI\GUI.h"
#include <cmath>

class Tri : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	Tri(Point, Point,Point, GfxInfo shapeGfxInfo);
	bool checkInside(Point p) override;
	virtual ~Tri();
	virtual void Draw(GUI* pUI) const;

};

