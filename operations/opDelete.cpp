#include "opDelete.h"
class Graph;

opDelete::opDelete(controller* pCont) : operation{ pCont }
{

}

void opDelete::Execute()
{
	Graph* gi;
	GUI* Po = pControl->GetUI();
	Po->PrintMessage("Delete feature is Active and will delete the selected shape");
	gi = pControl->getGraph();
	gi->Delshape();
}

void opDelete::Undo()
{
	Graph* gi;
	GUI* Po = pControl->GetUI();
	gi = pControl->getGraph();
	gi->Redo_del();
	
}

void opDelete::Redo()
{

	Graph* gi;
	GUI* Po = pControl->GetUI();
	gi = pControl->getGraph();
	gi->Undo_Shape();
}
