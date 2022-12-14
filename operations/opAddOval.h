#pragma once

#include "operation.h"

//Add Oval operation class
class opAddOval : public operation
{
public:
	opAddOval(controller* pCont);
	virtual ~opAddOval();

	//Add rectangle to the controller
	virtual void Execute();
	void Undo() override;
	void Redo()override;
};

