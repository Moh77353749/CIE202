#include "DUP.h"
#include "Copy.h"
#include "Paste.h"




class Graph;

DUP::DUP(controller* pCont) : operation{ pCont }
{

}

void DUP::ReadParameter()
{
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
			f = 1;
		}
		else {
			if (f == 0) {
				Po->PrintMessage("No Figure Selected to Duplicate");
			}
		}
		for (int i = 0; i < 200; i++) {
			if (pControl->CopiedFigList[i] != NULL) {
			}

		}
	}

	if (pControl->GetFigCount() == 0 && pControl->getNumCopiedFiglist() != 0) {
		int x, y = 0;
		Po->GetPointClicked(x, y);
		Point c;
		c.x = x; c.y = y;
		for (int i = 0; i < 200; i++) {

			if (pControl->CopiedFigList[i] != NULL) {
				shape* T1 = ((pControl->CopiedFigList[i]));
				pControl->AddFigure(T1);
			}
		}
		Po->PrintMessage("Shape is done");
	}

}


void DUP::Execute()
{
	ReadParameter();
}

void DUP::Undo()
{
}

void DUP::Redo()
{
}