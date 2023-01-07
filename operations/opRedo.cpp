#include "opRedo.h"

opRedo::opRedo(controller* pCont) :operation(pCont)
{
}

opRedo::~opRedo()
{
}

void opRedo::Execute()
{
	Graph* g;
	GUI* P = pControl->GetUI();
	P->PrintMessage(" Redo feature is Active");
	g = pControl->getGraph();
	g->Redo_Actions();
}

void opRedo::Undo()
{
}

void opRedo::Redo()
{
}
