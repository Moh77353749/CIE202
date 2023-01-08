#include "zoom.h"
#include "..\GUI\GUI.h"




zoom::zoom(controller* pCont):operation(pCont)
{
	

}

void zoom::Execute()
{
	GUI* pUI = pControl->GetUI();
	int figuresCount = pControl->GetFigCount();
	int number;

	for (int i = 0; i < figuresCount; i++) {
		if (pControl->getFigByIndex(i)->IsSelected()) {
			number = pControl->getFigByIndex(i)->Resize(Scale);
		}
		pUI->ClearDrawArea();
	}
}
