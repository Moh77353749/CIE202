#pragma once
#include "../controller.h"
#include "..\GUI\GUI.h"
#include "../operations/operation.h"
#include "..\Shapes\Graph.h"
class opSel : public operation
{

public:
	opSel(controller* pCont);
	virtual void Execute();

};

