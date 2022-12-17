#include "Exit.h"

Exit::Exit(controller* pCont) : operation(pCont)
{
}

void Exit::Execute()
{
	GUI* pUI = pControl->GetUI();


	pUI->PrintMessage(" Press (s) if you want to save your project. if NOT, press (Enter) To Exit ");
	string sa = pUI->GetSrting();
	if (sa == "S" || sa == "s")
	{
		operationType pOp = SAVE;
		pUI->ClearDrawArea();
		Sleep(100);
		pUI->ClearStatusBar();
		Sleep(100);
		pUI->PrintMessage("SAVED successfully :) ");
		Sleep(250);
		pControl->createOperation(pOp);
	
	}
	else
	{
		pUI->PrintMessage("OK! -  NOT SAVED ");
		Sleep(550);
	}
}
Exit::~Exit(void)
{
}