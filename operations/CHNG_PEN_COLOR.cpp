#include "CHNG_PEN_COLOR.h"

#include<iostream>
using namespace std;

CHNG_PEN_COLOR::CHNG_PEN_COLOR(controller* pCont): operation(pCont)
{
	
}

void CHNG_PEN_COLOR::Execute()
{
	int x, y;

	GUI* pUI = pControl->GetUI();
	pUI->GetPointClicked(x, y);
	color z = pUI->GetcolorClicked(x, y);
	pUI->setCrntDrawColor(z);


	pUI->ClearStatusBar();
}

void CHNG_PEN_COLOR::Undo()
{
}

void CHNG_PEN_COLOR::Redo()
{
}
