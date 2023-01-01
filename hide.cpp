#include "hide.h"

hide::hide(controller* pCont):operation(pCont)
{
}

void hide::Execute()
{
	GUI* pUI;
	int x, y;
	Graph* gi;
	Point p1, p2;
	GfxInfo rGfxInfo;


	///
	rGfxInfo.DrawClr = WHITE;
	rGfxInfo.FillClr = WHITE;
	rGfxInfo.BorderWdth = 16;
	rGfxInfo.isFilled = true;	
	rGfxInfo.isSelected = false;
	pUI = pControl->GetUI();
	pUI->GetPointClicked(x, y); 
	pUI->GetPointClicked(p1.x, p1.y);
	pUI->GetPointClicked(p2.x, p2.y);
	pUI->Draw_Rect(p1, p2, rGfxInfo);
	////
	color bgc = pUI->getcrntbackgndcolor();
	gi = pControl->getGraph();
	gi->fill(bgc);
	pUI->setCrntFillColor(bgc);
	pUI->setChngDrawClr(bgc);

	//pUI->setCrntFillColor(WHITE);
	//pUI->setChngDrawClr(WHITE);


}
