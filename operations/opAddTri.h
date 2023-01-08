#pragma once
#include "../operations/operation.h"
#include "../controller.h"
class opAddTri: public operation
	{
	protected:
		shape* shap;
	public:
		opAddTri(controller * pCont);
		virtual ~opAddTri();

		//Add tri to the controller
		virtual void Execute();
		void Undo() override;
		void Redo()override;
};

