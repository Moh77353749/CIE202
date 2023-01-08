#include "opDelete.h"
class Graph;

opDelete::opDelete(controller* pCont) : operation{ pCont }
{

}

void opDelete::Execute()
{
	Graph* gi;
	GUI* Po = pControl->GetUI();;
	Po->PrintMessage("Delete feature is Active and will delete the selected shape");
	gi = pControl->getGraph();
	gi->Delshape();
}

void opDelete::Undo()
{
}

void opDelete::Redo()
{
}
