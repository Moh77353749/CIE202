#pragma once
#include "../operations/operation.h"

class opsave : public operation
{
private:
	string file_name;
public:
	opsave(controller* pCont);
	virtual void Execute();
	void Undo() ;
	void Redo();
};

