#include "opMDel.h"

opMDel::opMDel(controller* pCont) : operation{ pCont }
{
}

void opMDel::Execute()
{
	Graph* gi;
	GUI* Po = pControl->GetUI();;
	Po->PrintMessage("Multi-Delete feature is Active and will delete the selected shapes");
	gi = pControl->getGraph();
	gi->DelMshape();
}
