#include "Resize.h"
#include "operation.h"

#include "..\controller.h"


Resize::Resize(controller* pCont, double _Scale) :operation(pCont)
{
	Scale = _Scale;
	anyFigSelected = false;

}

void Resize::Execute()
{
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Resize mode");
	int figuresCount = pControl->GetFigCount();
	int resized;

	for (int i = 0; i < figuresCount; i++) {
		if (pControl->getFigByIndex(i)->IsSelected()) {
			resized = pControl->getFigByIndex(i)->Resize(Scale);

			if (resized == 0) {
				pUI->PrintMessage("Figure Resized :" + pControl->getFigByIndex(i)->FigureName());
			}
			else {
				pUI->PrintMessage("Can't Resize :" + pControl->getFigByIndex(i)->FigureName());
			}
			anyFigSelected = true;
		}
	}
	if (!anyFigSelected) {
		pUI->PrintMessage("No figure selected");
	}

	pUI->ClearDrawArea();
}
