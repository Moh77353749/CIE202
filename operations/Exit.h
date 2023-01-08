#pragma once
#include "operation.h"
#include "..\DEFS.h"
#include"..\controller.h"
#include"../operations/opsave.h"

class Exit : public operation
{
public:
	Exit(controller* pCont);

	virtual ~Exit(void);
	void Undo() override;
	void Redo()override;
	virtual void Execute();
};