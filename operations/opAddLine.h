
#pragma once

#include "operation.h"

class opAddLine : public operation
{
	Point p1, p2;
	GfxInfo LGfxInfo;
protected:
	shape* shap;
public:
	opAddLine(controller* pCont);
	virtual ~opAddLine();

	//Add rectangle to the controller
	virtual void Execute();
	void Undo() override;
	void Redo()override;
};

