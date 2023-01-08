#pragma once

#include "operation.h"

//Add Rectangle operation class
class opAddRect: public operation
{
protected:
	shape* shap;
public:
	opAddRect(controller *pCont);
	virtual ~opAddRect();
	// virtual bool checkInside(Point p);
	//Add rectangle to the controller
	virtual void Execute() ;
	void Undo() override;
	void Redo()override;
};

