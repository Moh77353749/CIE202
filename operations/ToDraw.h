#pragma once
#include "operation.h"
#include"..\GUI\GUI.h"
#include "..\controller.h"
	class ToDraw : public operation
	{

	public:
		ToDraw(controller* pCont);
		virtual void Execute();
		void Undo() override;
		void Redo()override;
	};
	

