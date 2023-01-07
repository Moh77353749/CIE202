#pragma once
#include "operation.h"
#include "../Shapes/Graph.h"
#include "../GUI/GUI.h"
#include "../controller.h"
#include <iostream>
using namespace std;
class opUndo: public operation
{
public:
	opUndo(controller* pCont);
	~opUndo();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

