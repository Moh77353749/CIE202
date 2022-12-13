#pragma once
#include"Shapes/Shape.h"
#include "GUI/GUI.h"


class Circ :public shape
{
private:
	Point center;
	Point radius;
public:
	Circ(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Circ();
	virtual void Draw(GUI* pUI) const;
};

