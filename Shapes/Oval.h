#pragma once
#include "shape.h"
#include "..\GUI\GUI.h"
using namespace std;
#include <iostream>
#include <fstream>
#include "..\controller.h"


class Oval : public shape
{
private:
	Point focal1;
	Point focal2;
	controller* cp;

public:
	Oval(Point, Point, GfxInfo shapeGfxInfo);
	bool checkInside(Point p) override;
	void Save(ofstream& OutFile) override;
	virtual ~Oval();
	virtual void Draw(GUI* pUI) const;
	virtual void Load(ifstream& Infile);
};



