#include<iostream>
#include "opSel.h"
#include "../Shapes/Shape.h"
using namespace std;
opSel::opSel(controller* pCont) : operation{ pCont }
{
}
void opSel::Execute()
{
	Point P1;
	Graph* g;
	GUI* P = pControl->GetUI();
	P->PrintMessage("Select feature is Active: Click at figure");
	P->GetPointClicked(P1.x, P1.y);
	P->ClearStatusBar();
	g = pControl->getGraph();
	shape* s = g->Getshape(P1);
	

}
