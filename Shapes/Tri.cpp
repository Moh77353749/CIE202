#include "Tri.h"
#include "..\GUI\GUI.h"
Tri::Tri(Point P1, Point P2,Point P3, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	SetID(2);
}

bool Tri::checkInside(Point p)
{
	double dist01 = sqrt(pow((p.x - Corner1.x), 2) + pow((p.y - Corner1.y), 2));
	double dist02 = sqrt(pow((p.x - Corner2.x), 2) + pow((p.y - Corner2.y), 2));
	double dist03 = sqrt(pow((p.x - Corner3.x), 2) + pow((p.y - Corner3.y), 2));
	double dist12 = sqrt(pow((Corner2.x - Corner1.x), 2) + pow((Corner2.y - Corner1.y), 2));
	double dist13 = sqrt(pow((Corner3.x - Corner1.x), 2) + pow((Corner3.y - Corner1.y), 2));
	double dist23 = sqrt(pow((Corner2.x - Corner3.x), 2) + pow((Corner2.y - Corner3.y), 2));
	if (((p.x > Corner3.x) && (p.x < Corner2.x)) && ((p.y > Corner1.y) && (p.y < Corner3.y)))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}




void Tri::Save(ofstream& OutFile)
{
	string fill;
	string colo = save_colors(ShpGfxInfo.DrawClr);
	
	if (ShpGfxInfo.isFilled) {
		fill = save_colors(ShpGfxInfo.FillClr);
	}
	else
	{
		fill = "NO_FILL";
	}

	OutFile << "Tri " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << Corner3.x<<" "<<Corner3.y << " " << colo << " " << fill <<" " << " " << ShpGfxInfo.BorderWdth << endl;
}

void Tri::Load(ifstream& Infile)
{
	string drawColor, fillColor;
	Infile >> ID >> Corner1.x >> Corner1.y
		>> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y >> drawColor >> fillColor;

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

int Tri::Resize(double scale)
{
	int length = Corner2.x - Corner1.x;
	if (Corner1.x + length * scale >= 1300 || Corner3.y + length * scale >= 650 || Corner3.x + length * scale >= 650
		|| scale * length <= 20)
	{
		return 1;
	}
	else
	{
		length = scale * length;
		return 0;
	}
}
Tri::~Tri()
{}

void Tri::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->Draw_Tri(Corner1, Corner2, Corner3, ShpGfxInfo);
}
