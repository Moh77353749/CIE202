#include "CHNG_PEN_COLOR.h"

#include<iostream>
using namespace std;

CHNG_PEN_COLOR::CHNG_PEN_COLOR(controller* pCont): operation(pCont)
{
	
}

void CHNG_PEN_COLOR::Execute()
{
	int x, y;
	Graph* gi;
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage(" pen color is active: click at your color");
	pUI->GetPointClicked(x, y);
	z = pUI->GetcolorClicked(x, y);
	pUI->ClearStatusBar();
	pUI->setCrntDrawColor(z);
	gi = pControl->getGraph();
	gi->bordc(z);

	pUI->ClearStatusBar();
}

void CHNG_PEN_COLOR::Undo()
{
	Graph* gi;
	GUI* pUI = pControl->GetUI();
	gi = pControl->getGraph();
	gi->bordc(prev_col);
	
}

void CHNG_PEN_COLOR::Redo()
{
	Graph* gi;
	GUI* pUI = pControl->GetUI();
	gi = pControl->getGraph();
	gi->bordc(z);
}
