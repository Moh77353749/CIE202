#include "ToPlay.h"

ToPlay::ToPlay(controller* pCont) :operation(pCont)
{
}

void ToPlay::Execute()
{
	GUI* pUI = pControl->GetUI();
	pControl->ClearSFigList();
	pUI->PrintMessage("Switched to Play Mode ");
	pUI->setguimodeplay();
	pUI->ClearToolBar();
	pUI->CreatePlayToolBar();
}

void ToPlay::Undo()
{
}

void ToPlay::Redo()
{
}
