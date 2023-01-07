#pragma once
#include "operation.h"
#include "../controller.h"

#include "../GUI/GUI.h"

class fillColor : public operation
{
	Point P1;
	color FillClr;
	color prev_col;
	color z;
	shape** ptrfigurelist;
public:
	fillColor(controller* pCont);


	

	//Changes current/selected figure draw color
	virtual void Execute();


	virtual void Undo();
	virtual void Redo();
};

