#include "controller.h"
#include "operations\opAddRect.h"
#include "operations\opAddLine.h"
#include "operations\opAddTri.h"
#include "operations\Exit.h"
#include "operations\ToPlay.h"
#include "operations\addSqu.h"
#include "operations\opAddOval.h"
#include "operations/opMulSel.h"
#include "operations/opMDel.h"
#include "operations/opsave.h"
#include "operations/opSend2back.h"
#include "operations/fillColor.h"
#include "operations/CHNG_PEN_COLOR.h"
#include "operations/changePenWidth.h"
#include "operations\opSel.h"
#include "operations/opAddCirc.h"
#include "operations/ActionChClr.h"
#include "operations/load.h"
#include "operations/opDelete.h"
#include "Shapes/Graph.h"
#include"Copy.h"
#include"Cut.h"
#include"Paste.h"



//Constructor
controller::controller()
{
	pGraph = new Graph;
	pGUI = new GUI;	//Create GUI object
	
	

}

//==================================================================================//
//								operations-Related Functions							//
//==================================================================================//
operationType controller::GetUseroperation() const
{
	//Ask the input to get the operation from the user.
	return pGUI->GetUseroperation();		
}




////////////////////////////////////////////////////////////////////////////////////
//Creates an operation and executes it
operation* controller::createOperation(operationType OpType)
{
	operation* pOp = nullptr;
	
	//According to operation Type, create the corresponding operation object
	switch (OpType)
	{
		case DRAW_RECT:
			pOp = new opAddRect(this);
			break;

		case DRAW_LINE:
			pOp = new opAddLine(this);///create AddLine operation here

			break;
		case DRAW_TRI:
			pOp = new opAddTri(this);///create Addtri operation here

			break;
		case DRAW_Squ:
			///create AddLineoperation here
			pOp = new addSqu(this);
			break;
		case SELECT:
			pOp =  new opSel(this);
			break;

		case DEL:
			pOp = new opDelete(this);
			break;
		case CHNG_FILL_CLR:
			pOp = new fillColor(this);
			break;
		case SAVE:
			pOp = new opsave(this); // do the save operation
			break;
		case DRAW_CIRC:
			pOp = new opAddCirc(this);
			break;
		case DRAW_OVAL:
			pOp = new opAddOval(this);
			break;
		case ccopy:
			pOp = new opCopy (this);
			break;
		case ccut:
			pOp = new Cut (this);
			break;
		case cpaste:
			pOp = new opPaste (this);
			break;
		case CHNG_PEN_WID:
			pOp = new changePenWidth(this);
			break;
		case CHNG_DRAW_CLR:
			pOp = new CHNG_PEN_COLOR(this);
			break;
		case LOAD:
			pOp = new LoAd(this);
			break;
		case actionch:
			pOp = new ActionChClr(this);
			break;
			break;
		case TO_PLAY:
			pOp = new ToPlay(this);
			break;
		case MSelect:
			pOp = new opMulSel(this);
			break;
		case MDelete:
			pOp = new opMDel(this);
			break;
		case EXIT:
			pOp = new Exit(this);
			///create Exitoperation here
			break;
		case SEND_BACK:
			pOp = new opSend2back(this);
		case STATUS:	//a click on the status bar ==> no operation
			break;
	}

	return pOp;
	
}
void controller::LoadFig()  //for each figure FigList, make it points to NULL 
{
	for (int i = 0; i < FigCount; ++i)
		FigList[i] = NULL;
	FigCount = 0;
}
void controller::AddFigure(shape* pFig)
{
	if (FigCount < 200)
		FigList[FigCount++] = pFig;
}
color controller::ConvertToColor(string s)
{
	if (s == "BLACK")
		return BLACK;
	if (s == "BLUE")
		return BLUE;
	if (s == "WHITE")
		return WHITE;
	if (s == "RED")
		return RED;
	if (s == "YELLOW")
		return YELLOW;
	if (s == "GREEN")
		return GREEN;
	if (s == "LIGHTGOLDENRODYELLOW")
		return LIGHTGOLDENRODYELLOW;
	return GREY;
}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all shapes on the user interface
void controller::UpdateInterface() const
{	
	pGraph->Draw(pGUI);

}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the UI
GUI *controller::GetUI() const
{	return pGUI; }


////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the Graph
Graph* controller::getGraph() const
{
	return pGraph;
}

shape* controller::GetObjSEL()
{
	return SLObj;
}
void controller::SetObjSEL(shape* SEL)
{
	SLObj = SEL;
}





//Destructor
controller::~controller()
{
	delete pGUI;
	delete pGraph;
	
}



//==================================================================================//
//							Run function											//
//==================================================================================//
void controller::Run()
{
	operationType OpType;
	do
	{
		//1. Ask the GUI to read the required operation from the user
		OpType = GetUseroperation();

		//2. Create an operation coresspondingly
		operation* pOpr = createOperation(OpType);
		 
		//3. Execute the created operation
		if (pOpr)
		{
			pOpr->Execute();//Execute
			
		}

		//Update the interface
		UpdateInterface();

	} while (OpType != EXIT);

}
int controller::GetFigCount()
{
	return FigCount;
}

void controller::GetFigList(shape* FigNewList[])
{
	for (int i = 0; i < 200; i++) {
		FigNewList[i] = FigList[i];
	}
}


void controller::setNumCopiedFiglist(shape* f1)
{
	for (int i = 0; i < 200; i++) {
		if (FigList[i] == f1)
			NumCopiedfig++;
	}
}

int controller::getNumCopiedFiglist()
{
	return NumCopiedfig;
}


void controller::FigNull(shape* pF)
{
	bool f = 0;
	for (int i = 0; i < 200; i++) {
		if (FigList[i] == pF) {
			FigList[i] = nullptr;
			f = 1;
		}
		if (f && i + 1 != 200) {
			FigList[i] = FigList[i + 1];
		}
	}
	FigCount--;
	pGUI->ClearDrawArea();
	UpdateInterface();
}

