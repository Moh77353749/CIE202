#pragma once
#include "operation.h"
#include "../Shapes/Graph.h"
#include "../GUI/GUI.h"
#include "../controller.h"

class opRedo : public operation
{
public:
	opRedo(controller* pCont);
	~opRedo();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};



