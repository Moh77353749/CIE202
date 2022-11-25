#pragma once
#include "operation.h"
#include "Graph.h"

class opSelect : public operation
{
private: 
	Point P1;
	GfxInfo SelGfxInfo;

public:
	opSelect(controller* pControl) ;
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

