#include "opSend2back.h"

opSend2back::opSend2back(controller* pCont) : operation(pCont)
{
}

opSend2back::~opSend2back()
{
}

void opSend2back::Execute()
{
	Graph* gi;
	GUI* Po = pControl->GetUI();;
	Po->PrintMessage("send to back feature is Active ");
	gi = pControl->getGraph();
	gi->send2b();
}

void opSend2back::Redo()
{
}

void opSend2back::Undo()
{
}
