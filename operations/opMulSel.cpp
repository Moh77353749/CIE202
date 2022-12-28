#include "opMulSel.h"

opMulSel::opMulSel(controller* pCont) : operation{ pCont }
{
}

void opMulSel::Execute()
{
	Point P1;
	Graph* g;
	GUI* P = pControl->GetUI();
	P->PrintMessage("Select feature is Active: Click at figure");
	P->GetPointClicked(P1.x, P1.y);
	P->ClearStatusBar();
	g = pControl->getGraph();
	shape* s = g->GetMshape(P1);

}
