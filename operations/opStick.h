#pragma once

#include "controller.h"
#include "operations/operation.h"
#include "GUI/GUI.h"
#include "Shapes/Graph.h"
class opStick : public operation
{
private:
	string pic_name;
public:
	opStick(controller* pCont);
	virtual void Execute();
};

