#include "Paste.h"
#include"Copy.h"
Paste::Paste(controller* pCont) : operation(pCont)
{
}

void Paste::Execute()
{
	GUI* Po = pControl->GetUI();
	shape* shapeList[200]{};
	pControl->GetFigList(shapeList);
	if (pControl->GetFigCount() == 0 && pControl->getNumCopiedFiglist() != 0) {
		Po->PrintMessage("Click on the screen");
		int x, y = 0;
		Po->GetPointClicked(x, y);
		Point c;
		c.x = x; c.y = y;
		for (int i = 0; i < 200; i++) {

			if (pControl->CopiedFigList[i] != NULL) {
				shape* T1 = ((pControl->CopiedFigList[i]));
				pControl->AddFigure(T1);
				shape* T2 = (pControl->CopiedFigList[i]->Clone(c));
			}
		}
		Po->PrintMessage("Shape is done");
	}
}

void Paste::Undo()
{
}

void Paste::Redo()
{
}
