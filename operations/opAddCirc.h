#pragma once

#include"operations/operation.h"
class opAddCirc :
    public operation
{
protected:
	shape* shap;
public:
	opAddCirc(controller* pCont);
	virtual ~opAddCirc();

	//Add rectangle to the controller
	virtual void Execute();
	void Undo() override;
	void Redo()override;
};

