#pragma once

#include "operation.h"

//Add Square operation class
class addSqu : public operation
{
protected:
	shape* shap;
public:
	addSqu(controller *pCont);
	virtual ~addSqu();

	//Add Square to the controller
	virtual void Execute();
	void Undo() ;
	void Redo();

};
