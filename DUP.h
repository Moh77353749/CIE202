#pragma once
#include "controller.h"
#include "operations/operation.h"
#include "Shapes/Graph.h"
#include "GUI/GUI.h"
#include "Copy.h"
#include "Paste.h"

class DUP : public operation
{
public:
	DUP(controller* pCont);
	virtual void ReadParameter();
	virtual void Execute();
	void Undo() override;
	void Redo()override;
};





