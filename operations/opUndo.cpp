#include "opUndo.h"

opUndo::opUndo(controller* pCont) :operation(pCont)
{
}

opUndo::~opUndo()
{
}

void opUndo::Execute()
{
	
	Graph* g;
	GUI* P = pControl->GetUI();
	P->PrintMessage(" Undo feature is Active");
	
	
	g = pControl->getGraph();
	g->Undo_Actions();
}

void opUndo::Undo()
{
}

void opUndo::Redo()
{
}
