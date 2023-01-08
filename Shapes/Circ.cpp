#include "Circ.h"

Circ::Circ(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	center = P1;
	radius = P2;
	SetID(4);
}

bool Circ::checkInside(Point p)
{
	//GUI* pUI = cp->GetUI();
	double dist;
	dist = pow(p.x - center.x, 2) + pow(p.y - center.y, 2);
	double dist2= pow(radius.x - center.x, 2) + pow(radius.y - center.y, 2);
	if (dist< dist2)return true;
	
		//string msg = "The Center is at (" + to_string(center.x) + ", " + to_string(center.y) + " )";
		//msg += "The radius is at (" + to_string(radius.x) + ", " + to_string(radius.y);
		//pUI->PrintMessage(msg);
		//pUI->PrintMessage("sdv");
	
	else
	{
		return false;
	}
	
}

shape* Circ::Clone(Point c)
{

	Point C2;
	C2.y = c.y;
	C2.x = c.x + abs(center.x - radius.x);
	shape* Temp = new Circ(c, C2, ShpGfxInfo);
	return Temp;

}

void Circ::Save(ofstream& OutFile)
{
	string fill;
	string colo = save_colors(ShpGfxInfo.DrawClr);

	if (ShpGfxInfo.isFilled) fill = save_colors(ShpGfxInfo.FillClr);
	else fill = "NON-FILLED";
	OutFile << "Circle " << ID << " " << center.x << " " << center.y << " " << radius.x << " " << radius.y << " " << colo << " " << fill << " " << ShpGfxInfo.BorderWdth << endl;
}

void Circ::Load(ifstream& Infile)
{
	string drawColor, fillColor;
	Infile >> ID >> center.x >> center.y
		>> radius.x >> radius.y >> drawColor >> fillColor;

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


Circ::~Circ()
{

}

void Circ::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->Draw_Circ(center, radius, ShpGfxInfo);
}