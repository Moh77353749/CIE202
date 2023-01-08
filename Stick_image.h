#pragma once
#include "Shapes/Shape.h"
#include "GUI/GUI.h"
#include <iostream>
using namespace std;
class Stick_image : public shape
{
private:
	Point Corner1;
public:
	Stick_image(Point,GfxInfo shapeGfxInfo);

	virtual ~Stick_image();
	virtual void Draw(GUI* pUI) const;
};

