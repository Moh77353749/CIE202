#pragma once

#include "operation.h"

class OpDelete : public operation
{
private:
	Point P1, P2;
	GfxInfo RectGfxInfo;
public:
	OpDelete(controller* pCont);
	virtual ~OpDelete();

	//Add rectangle to the controller
	virtual void Execute();
};


