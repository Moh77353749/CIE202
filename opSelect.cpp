#include "opSelect.h"
#include "GUI/GUI.h"
#include "controller.h"
#include "operation.h"


opSelect::opSelect(controller* pControl):operation(pControl)
{
}

void opSelect::Execute()
{
	GUI* Pout = pControl->GetUI();
	GUI* Pin= pControl->GetUI();
	Pout->PrintMessage("Select Active: Click at figure");
	Pin->GetPointClicked(P1.x, P1.y); 
	pControl->Getshape(P1.x, P1.y);
}

void opSelect::Undo()
{
}

void opSelect::Redo()
{
}

