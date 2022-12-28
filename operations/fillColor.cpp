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
	GUI* pUI = pControl->GetUI();
	pUI->GetPointClicked(x, y);
	color z=pUI->GetcolorClicked(x,y);

	
	gi = pControl->getGraph();
	gi->fill(z);
	pUI->setCrntFillColor(z);
}

void fillColor::Undo()
{
}

void fillColor::Redo()
{
}
