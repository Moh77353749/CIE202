#include "opDelete.h"


class Graph;
opDelete::opDelete(controller* pCont) : operation{ pCont }
{

}

void opDelete::Execute()
{
	Point P;
	Graph* gi;
	GUI* Po = pControl->GetUI();;
	Po->PrintMessage("Delete feature is Active");
	Po->GetPointClicked(P.x, P.y);
	gi = pControl->getGraph();
	gi->Delshape();
	Po->ClearStatusBar();
	Po->PrintMessage("selected graph is deleted");
	

	
}
