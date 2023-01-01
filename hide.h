#pragma once
#include "operation.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include "..\Shapes\Graph.h"
#include "..\Shapes\Shape.h"
class hide : public operation
{
public:
	hide(controller* pCont);
	virtual void Execute();
};

