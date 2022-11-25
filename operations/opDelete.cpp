#include "OpDelete.h"
#include "controller.h"
#include "GUI/GUI.h"

OpDelete::OpDelete(controller* pControl) : operation(pControl)
{

}

void OpDelete::Execute()
{
	GUI* P_out = pControl->GetUI();
	GUI* P_in= pControl->GetUI();
	
}
