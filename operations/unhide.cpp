#include "unhide.h"

unhide::unhide(controller* pCont):operation (pCont)
{
}

void unhide::Execute()
{
	Point p1, p2;

	GUI* pUI = pControl->GetUI();
	Graph* gi;
	//gi->Getshape(p1);
	gi=pControl ->getGraph();
	gi->send2b();


}

void unhide::Undo()
{
}

void unhide::Redo()
{
}
