#pragma once

#include"operation.h"

class ActionChClr :public operation
{
private:
	Point P1, P2;
	GfxInfo RectGfxInfo;
public:
	ActionChClr(controller* pCont);




	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};
