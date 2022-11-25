#pragma once

#include "operation.h"
class opSave : public operation
{
	string file_name;
	int Fc;

public:
	opSave(controller* pCont, int F_c);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

