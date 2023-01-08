#include "hide.h"
#include "..\Shapes\Rect.h"

hide::hide(controller* pCont):operation(pCont)
{
}

void hide::sethide(bool h)
{
	hidden = h;
}

void hide::Execute()
{
	int x, y,
		w,z;
Point p1, p2;
GfxInfo shapeGfxInfo;
shapeGfxInfo.BkGrndColor = RED;
shapeGfxInfo.BorderWdth = 10;
shapeGfxInfo.DrawClr = BLACK;
shapeGfxInfo.FillClr = RED;
shapeGfxInfo.isFilled = TRUE;

Graph* gi;
//window* pWind=NULL;
GUI* pUI = pControl->GetUI();
pUI->PrintMessage("select point1 on shape");

pUI->GetPointClicked(p1.x, p1.y);
pUI->PrintMessage("select point2 on shape");
pUI->GetPointClicked(p2.x, p2.y);
//p1 = { x,y }; p2 = { w,z };
//color z = pUI->GetcolorClicked(x, y);


gi = pControl->getGraph();
gi->shide(TRUE);
//pUI->setCrntFillColor();
int a= abs(p1.y - p2.y),
b = abs(p1.x - p2.x), c=((p1.y + p2.y)/2), d = ((p1.y + p2.y) / 2);
//window* pW = new window(b,a, 5, 5);
//pW->DrawRectangle(d, c, b, a);

Rect* R = new Rect(p1, p2, shapeGfxInfo);

//Graph* pGr = pControl->getGraph();
gi->Addshape(R);
pControl->setFigList(R);
//pUI->Draw_Rect(p1, p2, shapeGfxInfo);
}

void hide::Undo()
{
}

void hide::Redo()
{
}
