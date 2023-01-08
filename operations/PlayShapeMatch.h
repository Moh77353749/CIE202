#pragma once
#include "operation.h"
#include "..\GUI\GUI.h"
#include "..\controller.h"
#include "..\Shapes\Graph.h"
#include "..\Shapes\Shape.h"
class PlayShapeMatch :
    public operation
{
	Point P;
	int Correct;
	int Wrong;
	int Score;
	string Fig;
	Graph* pGf;

public:
	PlayShapeMatch(controller* pCont);

	virtual void Execute();
	void Undo() override;
	void Redo()override;

};

