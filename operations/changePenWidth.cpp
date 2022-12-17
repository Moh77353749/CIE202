#include "changePenWidth.h"

changePenWidth::changePenWidth(controller* pCont) :operation(pCont)
{
}

void changePenWidth::Execute()
{
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Enter the pen width:  ");

	string penWid = pUI->GetSrting();

	int wid = stoi(penWid);
	if (wid > 0)
		pUI->setCrntPenWidth(wid);
	else
	{
		pUI->PrintMessage("Put a correct number");
		return;
	}
}

void changePenWidth::Undo()
{
}

void changePenWidth::Redo()
{
}
