#pragma once
#include "operation.h"
#include "../controller.h"

#include "../GUI/GUI.h"
class zoom :
    public operation
{
private:
	double Scale;
	bool anyFigSelected;
public:
	 zoom(controller* pCont);


	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

