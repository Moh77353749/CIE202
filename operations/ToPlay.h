#pragma once
#include "operation.h"
#include "..\controller.h"
class ToPlay : public operation
{
public:
	ToPlay(controller* pCont);
	virtual void Execute();
	void Undo() override;
	void Redo()override;
};

