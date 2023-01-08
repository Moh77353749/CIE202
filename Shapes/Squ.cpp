#include "Squ.h"
#include "shape.h"

Squ::Squ(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	SetID(3);
}

Squ::~Squ()
{}

void Squ::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->Draw_Rect(Corner1, Corner2, ShpGfxInfo);
}

bool Squ::checkInside(Point p)
{
	if (((p.x > Corner1.x) && (p.x < Corner2.x)) && ((p.y > Corner1.y) && (p.y < Corner2.y)))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void Squ::Save(ofstream& OutFile)
{
	vector<string> propers;

	propers.push_back("RECT ");
	propers.push_back(to_string(ID));
	propers.push_back(to_string(Corner1.x));
	propers.push_back(to_string(Corner1.y));
	propers.push_back(to_string(Corner2.x));
	propers.push_back(to_string(Corner2.y));

	for (int i = 0; i < propers.size(); i++) {
		OutFile << propers[i];
		OutFile << " ";
	}
	OutFile << "\n";
	propers.clear();
}
void Squ::Load(ifstream& Infile)
{
	string drawColor, fillColor;
	Infile >> ID >> Corner1.x >> Corner1.y
		>> Corner2.x >> Corner2.y >> drawColor >> fillColor;

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
int Squ::Resize(double scale)
{
	int length = Corner2.x - Corner1.x;
	if (Corner1.x + length * scale >= 1300 || Corner1.y + length * scale >= 650
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


