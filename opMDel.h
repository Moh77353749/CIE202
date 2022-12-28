#pragma once
#include "controller.h"
#include "GUI/GUI.h"
#include "operations/operation.h"
#include "Shapes/Graph.h"

class opMDel : public operation
{
public:
	opMDel(controller* pCont);
	virtual void Execute();
};

