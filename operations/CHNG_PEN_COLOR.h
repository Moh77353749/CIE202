#pragma once
#include "operation.h"
#include "../controller.h"

#include "../GUI/GUI.h"
class CHNG_PEN_COLOR : public operation
{
private:
	Point Point1, Point2;
	color prev_col;
	color z;

public:
	CHNG_PEN_COLOR(controller* pCont);


	virtual void Execute();
	virtual void Undo();
	virtual void Redo();

};

