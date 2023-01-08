#pragma once

#include "../Shapes/Shape.h"
#include "../GUI/GUI.h"
class Line : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point p;
	
public:
	Line(Point, Point, GfxInfo shapeGfxInfo);
	bool checkInside(Point p) override;
	void Save(ofstream& OutFile) override;
	virtual void Load(ifstream& Infile);
	int Resize(double scale);
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
	
};

