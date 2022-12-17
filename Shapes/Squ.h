#pragma once

#include "shape.h"

class Squ : public shape
{
private:
	Point Corner1;
	Point Corner2;
	int Id;
public:
	Squ(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Squ();
	virtual void Draw(GUI* pUI) const;
	bool checkInside(Point p) override;
	void Save(ofstream& OutFile) override;	
	virtual void Load(ifstream& Infile);


};
