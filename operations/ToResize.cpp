#include "ToResize.h"

ToResize::ToResize(controller* pCont) :operation(pCont)
{
}

void ToResize::Execute()
{
	GUI* pUI = pControl->GetUI();
	pUI->ClearToolBar();
	pUI->CreateResizeToolBar();
	pUI->PrintMessage("Switched to Resize Mode ");
}
