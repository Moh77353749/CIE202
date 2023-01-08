#pragma once
#include "operation.h"
#include "../controller.h"

#include "../GUI/GUI.h"
class changePenWidth :
    public operation
{
private:
	Point Point1, Point2;

public:
	changePenWidth(controller* pCont);


	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

