#include "addSqu.h"
#include "..\shapes\Squ.h"
#include <math.h>

#include "..\controller.h"

#include "..\GUI\GUI.h"

addSqu::addSqu(controller * pCont) :operation(pCont)
{}
addSqu::~addSqu()
{}


//Execute the operation
void addSqu::Execute()
{
	Point P1, P2;
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Square: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();
	double L = max(abs(P1.x - P2.x), abs(P1.x - P2.x));
	Point topLeft;
	topLeft.x = P1.x < P2.x ? P1.x : P2.x;
	topLeft.y = P1.y < P2.y ? P1.y : P2.y;
	P2.x = P1.x + L;
	P2.y = P1.y + L;
	//Preapre all Square parameters

	GfxInfo SquGfxInfo;

	//get drawing, filling colors and pen width from the interface
	SquGfxInfo.DrawClr = pUI->getCrntDrawColor();
	SquGfxInfo.FillClr = pUI->getCrntFillColor();
	SquGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	SquGfxInfo.isFilled = false;	//default is not filled
	SquGfxInfo.isSelected = false;	//defualt is not selected


	//Create a Square with the above parameters
	Squ* R = new Squ(topLeft, P2, SquGfxInfo);


	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the Square to the list of shapes
	pGr->Addshape(R);

}
void Squ::zooom(double px, double py, double scale) {
	Corner1.x = (Corner1.x * scale) - (scale * px) + px;
	Corner2.x = (Corner2.x * scale) - (scale * px) + px;
	Corner1.y = (Corner1.y * scale) - (scale * px) + px;
	Corner2.y = (Corner2.y * scale) - (scale * px) + px;
}
	
