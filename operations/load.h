#pragma once
#include"operation.h"
class LoAd :public operation
{
private:
	string FileName;

public:
	LoAd(controller* pCont);


	
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};