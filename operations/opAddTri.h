#pragma once

#include "operation.h"

class opAddTri: public operation
	{
	protected:
		shape* shap;
	public:
		opAddTri(controller * pCont);
		virtual ~opAddTri();

		//Add rectangle to the controller
		virtual void Execute();
		void Undo() override;
		void Redo()override;
};

