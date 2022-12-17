#include "Oval.h"

Oval::Oval(Point p1, Point p2, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)

{
	focal1 = p1;
	focal2 = p2;
	SetID(6);

}

bool Oval::checkInside(Point p)
{
	double dist;
	dist = pow(p.x - focal1.x, 2) + pow(p.y - focal2.y, 2);
	double dist2 = pow(focal1.x - focal2.x, 2) + pow(focal1.y - focal2.y, 2);
	if (dist < dist2)return true;

	
	else
	{
		return false;
	}
}

void Oval::Save(ofstream& OutFile)
{
	string fill;
	string colo = save_colors(ShpGfxInfo.DrawClr);

	if (ShpGfxInfo.isFilled) fill = save_colors(ShpGfxInfo.FillClr);
	else fill = "NO_FILL";
	OutFile << "Oval " << ID << " " << focal1.x << " " << focal1.y << " " << focal2.x << " " << focal2.y << " " << colo << " " << fill << " " << ShpGfxInfo.BorderWdth << endl;

}

Oval::~Oval() {}

void Oval::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawOval(focal1, focal2, ShpGfxInfo);
}

void Oval::Load(ifstream& Infile)
{
	string drawColor, fillColor;
	Infile >> ID >> focal1.x >> focal1.y
		>> focal2.x >> focal2.y >> drawColor >> fillColor;

	ShpGfxInfo.DrawClr = GetStrinColor2(drawColor);

	if (fillColor == "NON-FILLED")
		ShpGfxInfo.isFilled = false;
	else
	{
		ShpGfxInfo.FillClr = GetStrinColor2(fillColor);
		ShpGfxInfo.isFilled = true;
	}
	ShpGfxInfo.isSelected = false;

}

