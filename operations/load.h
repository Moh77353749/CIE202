#pragma once
#include"operation.h"
class LoAd :public operation
{
private:
	string FileName;

public:
	LoAd(controller* pCont);


	virtual void ReadParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};