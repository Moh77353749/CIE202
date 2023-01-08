#include "opStick.h"

opStick::opStick(controller* pCont):operation{ pCont }
{
}

void opStick::Execute()
{
	Graph* gi;
	GUI* Po = pControl->GetUI();;
	Po->PrintMessage("stick feature is Active, Enter the picture name: ");
	pic_name = Po->GetSrting();
	Po->ClearStatusBar();
	gi = pControl->getGraph();
	gi->stickImage(pic_name);
	
}
