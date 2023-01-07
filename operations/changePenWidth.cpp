#include "changePenWidth.h"

changePenWidth::changePenWidth(controller* pCont) :operation(pCont)
{
}

void changePenWidth::Execute()
{
	Graph* gi;
	gi = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Enter the pen width:  ");

	penWid = pUI->GetSrting();
	pUI->ClearStatusBar();
	int wid = stoi(penWid);
	if (wid > 0) {
		pUI->setCrntPenWidth(wid);
		gi->bordw(wid);
	}
	else
	{
		pUI->PrintMessage("Put a correct number");
		
	}
}

void changePenWidth::Undo()
{
	Graph* gi;
	GUI* pUI = pControl->GetUI();
	gi = pControl->getGraph();
	gi->bordw(stoi(prev_col));
}

void changePenWidth::Redo()
{
	Graph* gi;
	GUI* pUI = pControl->GetUI();
	gi = pControl->getGraph();
	gi->bordw(stoi(penWid));
}
