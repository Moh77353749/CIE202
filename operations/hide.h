#include "operation.h"
#include "..\controller.h"
#include "..\Shapes\Shape.h"
#include "..\Shapes\Graph.h"
#include <Windows.h>

class hide : public operation
{
protected:
	bool hidden;
	
public:
	hide(controller* pCont);
	void sethide(bool h);
	virtual void Execute();
	void Undo() override;
	void Redo()override;

};