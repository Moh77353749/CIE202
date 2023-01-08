#pragma once
#include "../operations/operation.h"
#include "../controller.h"
class opAddTri: public operation
	{
	public:
		opAddTri(controller * pCont);
		virtual ~opAddTri();

		//Add tri to the controller
		virtual void Execute();
};

