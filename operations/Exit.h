#pragma once
#include "operation.h"
#include "..\DEFS.h"
#include"..\controller.h"
#include "..\opsave.h"

class Exit : public operation
{
public:
	Exit(controller* pCont);

	virtual ~Exit(void);

	virtual void Execute();
};