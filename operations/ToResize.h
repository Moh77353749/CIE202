#pragma once
#include "operation.h"
#include "..\controller.h"
class ToResize : public operation
{
public:
	ToResize(controller* pCont);
	virtual void Execute();
};

