#include "opMulSel.h"

opMulSel::opMulSel(controller* pCont) : operation{ pCont }
{
}

void opMulSel::Execute()
{
	Point P1;
	Graph* g;
	GUI* P = pControl->GetUI();
	P->PrintMessage(" Multi-Select feature is Active: Click at figure");
	P->GetPointClicked(P1.x, P1.y);
	/*
		P->ClearStatusBar();
	g = pControl->getGraph();
	shape* s = g->GetMshape(P1);*/

	
	while (!(P1.x > 1020 && P1.x < 1135 && P1.y>0 && P1.y < 50))
	{
		P->GetPointClicked(P1.x, P1.y);
		P->ClearStatusBar();
		g = pControl->getGraph();
		g->GetMshape(P1);
	}
}

void opMulSel::Undo()
{
}

void opMulSel::Redo()
{
}
