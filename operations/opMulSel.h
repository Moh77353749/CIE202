#pragma once
#include "../controller.h"
#include "..\GUI\GUI.h"
#include "../operations/operation.h"
#include "..\Shapes\Graph.h"

class opMulSel : public operation
{
public:
	opMulSel(controller* pCont);
	virtual void Execute();
	void Undo() override;
	void Redo()override;
};

