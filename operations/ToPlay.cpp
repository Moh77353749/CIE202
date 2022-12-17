#include "ToPlay.h"

ToPlay::ToPlay(controller* pCont) :operation(pCont)
{
}

void ToPlay::Execute()
{
	GUI* pUI = pControl->GetUI();
	pUI->ClearToolBar();
	pUI->CreatePlayToolBar();
	pUI->PrintMessage("Switched to Play Mode ");
}
