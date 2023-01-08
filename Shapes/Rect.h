#pragma once

#include "shape.h"
#include "..\GUI\GUI.h"
#include <iostream>
using namespace std;
class Rect : public shape
{
private:
	Point Corner1;	
	Point Corner2;
	int Id;
public:
Rect(Point , Point, GfxInfo shapeGfxInfo );
	bool checkInside(Point p) override;
	void Save(ofstream& OutFile) override;
	virtual void Load(ifstream& Infile);
	virtual string GetF()const;


	virtual ~Rect();
	virtual void Draw(GUI* pUI) const;
};

