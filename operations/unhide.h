#pragma once
#include "operation.h"
#include "..\controller.h"
#include "..\Shapes\Shape.h"
#include "..\Shapes\Graph.h"
class unhide :
    public operation
{
public:
	unhide(controller* pCont);
	virtual void Execute();


	virtual void Undo();
	virtual void Redo();
};

