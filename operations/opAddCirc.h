#pragma once

#include"../operations/operation.h"
class opAddCirc :
    public operation
{
public:
	opAddCirc(controller* pCont);
	virtual ~opAddCirc();

	//Add rectangle to the controller
	virtual void Execute();
	void Undo() override;
	void Redo()override;
};

