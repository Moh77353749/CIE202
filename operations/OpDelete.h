#pragma once
#include "..\controller.h"
#include "..\operations\operation.h"
#include "..\Shapes\Graph.h"
#include "..\GUI\GUI.h"

class opDelete : public operation
{
public:
	opDelete(controller* pCont);
	virtual void Execute();
	void Undo() override;
	void Redo()override;
};


