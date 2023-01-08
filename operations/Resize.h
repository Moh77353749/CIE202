#pragma once
#include "operation.h"
#include "..\Shapes\Shape.h"
#include "..\GUI\GUI.h"

class Resize :public operation
{
	double Scale;
	bool anyFigSelected;

public:
	
	Resize(controller* pCont, double _Scale);
	virtual void Execute();

};