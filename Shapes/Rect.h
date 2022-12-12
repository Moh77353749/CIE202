#pragma once

#include "shape.h"
#include "..\GUI\GUI.h"
class Rect : public shape
{
private:
	Point Corner1;	
	Point Corner2;
public:
	Rect(Point , Point, GfxInfo shapeGfxInfo );
	bool checkInside(Point p) override;
	virtual ~Rect();
	virtual void Draw(GUI* pUI) const;
};

