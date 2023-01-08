#include "ToDraw.h"

ToDraw::ToDraw(controller* pCont) :operation(pCont)
{
}

void ToDraw::Execute()
{
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Switched to Draw Mode ");
	pUI->setguimodedraw();
	pUI->CreateDrawToolBar();
}

void ToDraw::Undo()
{
}

void ToDraw::Redo()
{
}
