#include "ActionChClr.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include "..\Shapes\shape.h"


ActionChClr::ActionChClr(controller* pCont) :operation(pCont)
{
}

void ActionChClr::ReadActionParameters()
{
}
void ActionChClr::Execute()
{

	/////////////////////////// CHANGE DRAW COLOR/////////////////////////////////////////


	int x, y;
	Graph* gi;
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage(" Choose Color");

	pUI->GetPointClicked(x, y);
	color z = pUI->GetcolorClicked(x, y);
	//string colorOptions = pUI->GetSrting();

	gi = pControl->getGraph();
	color main = pUI->getCrntDrawColor();
	pUI->setChngDrawClr(z);

	gi->bordc(z);
	pUI->setChngDrawClr(main);


	pUI->ClearStatusBar();


	/////////////////////////////////////CHANGE FILL COLOR///////////////////////////

	//pOut->PrintMessage("Enter the fill color you want (red,blue,green,white,black,yellow):   ");
	//clrString = pIn->GetSrting(pOut);

	//if (clrString == "red")
	//	clr = color(255, 0, 0);
	//else if (clrString == "green")
	//	clr = color(0, 255, 0);
	//else if (clrString == "blue")
	//	clr = color(0, 0, 255);
	//else if (clrString == "yellow")
	//	clr = color(255, 255, 0);
	//else if (clrString == "white")
	//	clr = color(255, 255, 255);
	//else if (clrString == "black")
	//	clr = color(0, 0, 0);
	//else
	//{
	//	pOut->PrintMessage("Invalid color...");
	//	return;
	//}

	//selected->ChngFillClr(clr);
	//pOut->ClearStatusBar();
	//


////	///////////////////////////CHANGE PEN WEIDTH//////////////////////////////////

	pUI->PrintMessage("Enter border width:   ");
	string xx = pUI->GetSrting();
	int number = stoi(xx);

	if (number > 0) {
		int mainW = pUI->getCrntPenWidth();
		pUI->ChngBorderWidth(number);
		gi->bordw(number);
		pUI->ChngBorderWidth(mainW);
	}
		

	else
	{
		pUI->PrintMessage("Invalid number...");
		return;
	}
	pUI->ClearStatusBar();	
};
/*else
{
	pUI->PrintMessage("Please Select The Fig First.... ");
	return;
}
}*/




void ActionChClr::Undo()
{

}
void ActionChClr::Redo()
{

}