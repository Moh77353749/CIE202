#include "opAddOval.h"
#include "..\shapes\Oval.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddOval::opAddOval(controller* pCont) :operation(pCont)
{}
opAddOval::~opAddOval()
{}

//Execute the operation
void opAddOval::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Oval : Click at first focal ");
	//Read 1st focal and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First focal is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second focal";
	pUI->PrintMessage(msg);
	//Read 2nd focal and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all rectangle parameters
	GfxInfo OvGfxInfo;

	//get drawing, filling colors and pen width from the interface
	OvGfxInfo.DrawClr = pUI->getCrntDrawColor();
	OvGfxInfo.FillClr = pUI->getCrntFillColor();
	OvGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	OvGfxInfo.isFilled = false;	//default is not filled
	OvGfxInfo.isSelected = false;	//defualt is not selected


	//Create an oval with the above parameters
	Oval* O = new Oval(P1, P2, OvGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Addshape(O);

}
