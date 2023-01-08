#include "PlayShapeMatch.h"
#include <iomanip>

PlayShapeMatch::PlayShapeMatch(controller* pCont):operation(pCont)
{
	Correct = 0; 
	Wrong = 0;
	Score = 0;
	
}

void PlayShapeMatch::Execute()
{
	GUI* pUI = pControl->GetUI();

	int Count = 0;
	Fig = pControl->RandFig(Count);

	if (Fig != "Empty")
	{
		pUI->PrintMessage("Select all " + Fig);

		while (Count)
		{
			pGf = pControl->getGraph();
			pGf->Getshape(P);
			pUI->GetPointClicked(P.x, P.y);
			shape* SFig = pControl->GetFigure(P.x,P.y);
			
			if (SFig)                                            
			{
				if (SFig->GetF() == Fig)
				{
					Correct++;                                 
					Count--;                                   
				}
				else
					Wrong++;                                 

				pUI->ClearDrawArea();                      
				SFig->Hide(true);                           
				pControl->UpdateInterface();
				pUI->PrintMessage("Correct Ans = " + to_string(Correct) + "                            "
					+ "Wrong Ans = " + to_string(Wrong) + "                "+  "Score = " + to_string((3*Correct)-Wrong));
			}

			
			else if (pUI->InDrawingArea(P.x, P.y))       
				pUI->PrintMessage("Correct Ans = " + to_string(Correct) + "                            "
					+ "Wrong Ans = " + to_string(Wrong) + "                " + "Score = " + to_string((3 * Correct) - Wrong) + "          Select a Figure Please");
			
			else                                         
			{
				pUI->PrintMessage("Correct Ans = " + to_string(Correct) + "        "
					+ "Wrong Ans = " + to_string(Wrong) + " Score = " + to_string((3 * Correct) - Wrong) + "     Please select icon from the tool bar");
				pUI->ClearDrawArea();
				pControl->ShowAllFigures();
				return;
			}

		}

		pUI->PrintMessage("Correct Ans = " + to_string(Correct) + "                            "
			+ "Wrong Ans = " + to_string(Wrong) + "                " + "Score = " + to_string((3 * Correct) - Wrong) +
			"            click any where to continue ...");

		if (Wrong == 0 && Count == 0) {
			string Image = "images\\MenuItems\\Congratulation.jpg";
			pUI->DrawImage(Image);
		}

		pUI->GetUseroperation();
		pUI->ClearDrawArea();
		pControl->ShowAllFigures();
		pUI->PrintMessage("Play Mode: Please select any icon from the tool bar");
	}
	
	else
	{
		pUI->PrintMessage("Empty Drawing Area , You can back to \"Draw Mode\" ");
		return;
	}
}

void PlayShapeMatch::Undo()
{
}

void PlayShapeMatch::Redo()
{
}
