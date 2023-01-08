#pragma once
#include "operation.h"
#include "operation.h"
#include "..\GUI\GUI.h"
#include "..\controller.h"
#include "..\Shapes\Graph.h"
#include "..\Shapes\Shape.h"
#include "..\CMUgraphicsLib\colors.h"

class PlayShapeColorMatch :
    public operation

{
	Point P;
	int Correct;
	int Wrong;
	int Score;
	color PlayingColor;
	string Fig;

public:
	PlayShapeColorMatch(controller* pCont);

	virtual void Execute();
	void Undo() override;
	void Redo()override;
};

