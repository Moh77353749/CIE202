#pragma once
#include"../Shapes/Shape.h"
#include "../controller.h"
class Circ :public shape
{
private:
	Point center;
	Point radius;
	controller* cp;
public:
	Circ(Point, Point, GfxInfo shapeGfxInfo);
	bool checkInside(Point p) override;
	void Save(ofstream& OutFile) override;
	virtual void Load(ifstream& Infile);
	virtual string GetF()const;

	virtual ~Circ();
	virtual void Draw(GUI* pUI) const;
};

