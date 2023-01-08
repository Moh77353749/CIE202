#pragma once

#include "operation.h"

//Add Square operation class
class addSqu : public operation
{
public:
	addSqu(controller *pCont);
	virtual ~addSqu();

	//Add Square to the controller
	virtual void Execute();
	void Undo() override;
	void Redo()override;

};
