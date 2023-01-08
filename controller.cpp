#include "controller.h"
#include "operations\opAddRect.h"
#include "operations\opAddLine.h"
#include "operations\opAddTri.h"
#include "operations\Exit.h"
#include "operations\ToPlay.h"
#include "operations\ToDraw.h"
#include "operations\addSqu.h"
#include "operations\opAddOval.h"
#include "operations/opMulSel.h"
#include"CMUgraphicsLib/colors.h"
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
#include "Shapes\Shape.h"
#include <stdlib.h>     
#include <time.h>
#include<cstdlib>
#include <iomanip>
#include "Shapes/Circ.h"
#include "Shapes/Line.h"
#include"Shapes/Squ.h"
#include"Shapes/Oval.h"
#include"Shapes/Rect.h"
#include"operations/PlayColorMatch.h"
#include"operations/PlayShapeColorMatch.h"
#include"operations/PlayShapeMatch.h"
#include"operations/hide.h"
#include "operations/unhide.h"





//Constructor
controller::controller()
{
	pGraph = new Graph;
	pGUI = new GUI;	//Create GUI object
	
	FigCount = 0;
	for (int i = 0; i < MaxFigCount; i++)
	{
		FigList[i] = NULL;
	}

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
		case TO_PLAY: pOp = new ToPlay(this);
			break;
		case TO_DRAW: pOp = new ToDraw(this);
			break;
		case MSelect: pOp = new opMulSel(this);
			break;
		case MDelete:
			pOp = new opMDel(this);
			break;
		case EXIT:
			pOp = new Exit(this);
			break;
		case SEND_BACK:
			pOp = new opSend2back(this);
			break;
		case COLORMATCH: pOp = new PlayColorMatch(this);
			break;
		case SAHPEMATCH: pOp = new PlayShapeMatch(this);
			break;
		case COLORSHAPEMATCH: pOp = new PlayShapeColorMatch(this);
			break;
		case HIDE: pOp = new hide(this);
			break;
		case UNHIDE: pOp = new unhide(this);
			break;
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

string controller::ConvertToString(color c)
{
	c = pUI->getCrntDrawColor();
	if (c == RED) return "RED";
	if (c == BLUE) return "BLUE";
	if (c == BLACK) return "BLACK";
	if (c == WHITE) return "WHITE";
	if (c == GREEN) return "GREEN";
	if (c == DARKRED) return "DARKRED";
	if (c == LIGHTBLUE) return "LIGHTBLUE";
	if (c == PINK) return "PINK";
	if (c == ORANGE) return "ORANGE";
	if (c == YELLOW) return "YELLOW";
	return "InValid";
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

shape* controller::GetFigure(int x, int y) const
{
	Point P={x,y};
	P.x = x; P.y = y;
	for (int i = FigCount - 1; i >= 0; i--)
		if (FigList[i]->checkInside(P) && !FigList[i]->IsHidden())
			return FigList[i];
	return NULL;
}
shape* controller::GetObjSEL()
{
	return SLObj;
}
string controller::RandFig(int& Count) const
{
	Count = 0;
	int Rand;
	string Figure;

	if (FigCount != 0)
	{
		if (FigCount != 1)
		{
			//Randomly choose The Figure
			Rand = rand() % FigCount;
			Figure = FigList[Rand]->GetF();
			for (int i = 0; i < FigCount; i++)
			{
				if (FigList[Rand]->GetF() == FigList[i]->GetF())
				{
					Count++;
				}
			}
		}
		else
		{
			Figure = FigList[0]->GetF();
			Count = 1;
		}
		return Figure;
	}
	return "Empty";
}

string controller::RandShp(int& Count) const
{
	return string();
}

color controller::RandClr(int& Count) const
{
	Count = 0;
	int Rand;
	color Color;

	if (FigCount != 0)
	{
		//Check if There are any Figure That have a Filling Color or There Any Line
		for (int i = 0; i < FigCount; i++)
		{
			if (FigList[i]->IsFilled() || dynamic_cast<Line*>(FigList[i]))
				break;
			else if (i == FigCount - 1)
				return Empty;
		}


		//Randomly choose The Figure
		if (FigCount != 1)
		{
			do {
				Rand = rand() % FigCount;
			} while (!FigList[Rand]->IsFilled() && !dynamic_cast<Line*>(FigList[Rand]));

			Color = FigList[Rand]->GetC();
			for (int i = 0; i < FigCount; i++)
			{
				if (FigList[Rand]->GetC() == FigList[i]->GetC())
				{
					Count++;
				}
			}
		}
		else
		{
			Color = FigList[0]->GetC();
			Count = 1;
		}
		return Color;
	}
	return Empty;
}

string controller::RandFigClr(int& Count, color& Color) const
{
	if (FigCount != 0)
	{
		Count = 0;
		int Rand;
		string Figure;

		//Check if There are any Figure That have a Filling Color or There Any Line
		for (int i = 0; i < FigCount; i++)
		{
			if (FigList[i]->IsFilled() || dynamic_cast<Line*>(FigList[i]))
				break;
			else if (i == FigCount - 1)
				return "Empty";
		}

		//Randomly choose The Figure
		if (FigCount != 1)
		{
			do {
				Rand = rand() % FigCount;
			} while (!FigList[Rand]->IsFilled() && !dynamic_cast<Line*>(FigList[Rand]));

			Color = FigList[Rand]->GetC();
			Figure = FigList[Rand]->GetF();
			for (int i = 0; i < FigCount; i++)
			{
				if (FigList[Rand]->GetC() == FigList[i]->GetC() && FigList[Rand]->GetF() == FigList[i]->GetF())
				{
					Count++;
				}
			}
		}
		else
		{
			Color = FigList[0]->GetC();
			Figure = FigList[0]->GetF();
			Count = 1;
		}
		return Figure;
	}
	return "Empty";
}

void controller::ShowAllFigures()
{
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->IsHidden())
			FigList[i]->Hide(false);
}

void controller::ClearSFigList()
{
	for (int i = 0; i < SFigCount; i++)
	{
		SFigList[i]->SetSelected(false);
		SFigList[i] = NULL;
	}

	SFigCount = 0;
}
void  controller::SelectFig(shape* pFig) {

	if (SFigCount < MaxFigCount)
	{
		for (int i = 0; i < SFigCount; i++)
			if (SFigList[i]->IsSelected())
				SFigList[i]->SetSelected(false);

		SFigList[SFigCount++] = pFig;
		SFigList[SFigCount - 1]->SetSelected(true);
		SFigList[SFigCount - 1]->SetSelected(true);
	}

	//Arrange The Selected Figure List Base On The Figure List
	if (SFigCount > 1)
	{
		int NewFigIndex, OldIndex;
		int Flag1 = SFigCount - 1;
		int Flag2 = SFigCount - 2;
		shape* Temp;
		while (Flag2 >= 0)
		{
			for (int j = 0; j < FigCount; j++)
			{
				if (SFigList[Flag1] == FigList[j])
					NewFigIndex = j;
				if (SFigList[Flag2] == FigList[j])
					OldIndex = j;
			}
			if (NewFigIndex < OldIndex)
			{
				Temp = SFigList[Flag2];
				SFigList[Flag2] = SFigList[Flag1];
				SFigList[Flag1] = Temp;
				Flag1 = Flag2;
			}
			Flag2--;
		}
	}
}

void controller::UnSelectedFig(shape* pFig)
{
	bool Flag = false;

	for (int i = 0; i < SFigCount; i++)
	{
		if (SFigList[i] == pFig) {
			Flag = true;
			SFigList[i]->SetSelected(false);
			SFigList[i]->SetSelected(false);
			SFigList[i] = NULL;
			SFigCount--;
		}

		if (Flag)
		{
			SFigList[i] = SFigList[i + 1];
		}
	}
	SFigList[SFigCount] = NULL;

}

void controller::DeleteFigure(shape* Fg)
{
	bool Flag = false;
	UnSelectedFig(Fg);
	for (int i = 0; i < FigCount; i++) {
		if (Fg == FigList[i]) {
			Flag = true;
			delete FigList[i];
			FigList[i] = NULL;
			FigCount--;
		}
		if (Flag) {
			FigList[i] = FigList[i + 1];
		}
	}
	FigList[FigCount] = NULL;
}
void controller::setFigList(shape* Fg)
{
	if (FigCount < MaxFigCount && Fg != NULL)
		FigList[FigCount++] = Fg;
	if (FigCount == 1)
		Fg->SetID(1);
	else
		Fg->SetID(FigList[FigCount - 2]->GetID() + 1);
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
			delete pOpr;	//operation is not needed any more ==> delete it
			pOpr = nullptr;
		}

		//Update the interface
		UpdateInterface();

	} while (OpType != EXIT);

}