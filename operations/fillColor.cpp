#include "fillColor.h"
#include<iostream>
using namespace std;
fillColor::fillColor(controller* pCont):operation(pCont)
{

}



void fillColor::Execute()
{
	int x, y;
	Graph* gi;
	prev_col = WHITE;
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage(" fill color is active: click at your color");
	pUI->GetPointClicked(x, y);
	z=pUI->GetcolorClicked(x,y);
	pUI->ClearStatusBar();
	gi = pControl->getGraph();
	gi->fill(z);
	pUI->setCrntFillColor(z);
}

void fillColor::Undo()
{
	Graph* gi;
	GUI* pUI = pControl->GetUI();
	gi = pControl->getGraph();
	gi->fill(prev_col);
}

void fillColor::Redo()
{
	Graph* gi;
	GUI* pUI = pControl->GetUI();
	gi = pControl->getGraph();
	gi->fill(z);
}
