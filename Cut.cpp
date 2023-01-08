#include "Cut.h"

Cut::Cut(controller* pCont) : operation(pCont)
{
}

Cut::~Cut(void)
{
}

void Cut::ReadParameter() {
	for (int i = 0; i < 200; i++)
	{
		pControl->CopiedFigList[i] = NULL;
	}
	GUI* Po = pControl->GetUI();
	shape* shapeList[200]{};
	pControl->GetFigList(shapeList);
	for (int i = 0; i < 200; i++) {
		if (shapeList[i] == nullptr) {
			break;
		}
		bool f = 0;
		if (shapeList[i]->IsSelected())
		{
			pControl->CopiedFigList[i] = shapeList[i];
			pControl->setNumCopiedFiglist(pControl->CopiedFigList[i]);
			pControl->FigNull(shapeList[i]);
			f = 1;
		}
		else {
			if (f == 0) {
				Po->PrintMessage("No Figure Selected to Copy");
			}
		}
		for (int i = 0; i < 200; i++) {
			if (pControl->CopiedFigList[i] != NULL) {
				Po->PrintMessage("Figure has been copied");
			}

		}
	}
}

void Cut::Execute()
{
	ReadParameter();
}
