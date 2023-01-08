#pragma once
#include "../operations/operation.h"
#include "../Shapes/Graph.h"
#include "../GUI/GUI.h"
class opSend2back : public operation
{
public: 

	opSend2back(controller* pCont);
	virtual ~opSend2back();

	//Add rectangle to the controller
	virtual void Execute();
	void Redo();
	void Undo();
};

