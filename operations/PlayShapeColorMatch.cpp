#include "PlayShapeColorMatch.h"
#include <iomanip>

PlayShapeColorMatch::PlayShapeColorMatch(controller* pCont) : operation(pCont)
{
	Correct = 0;
	Wrong = 0;
	Score = 0;
}

void PlayShapeColorMatch::Execute()
{
	GUI* pUI = pControl->GetUI();
	int Count = 0;
	PlayingColor = pControl->RandClr(Count);
	//string s = pControl->ConvertToString(PlayingColor);
	Fig = pControl->RandFigClr(Count, PlayingColor);

	if (PlayingColor != Empty && Fig != "Empty")
	{
		pUI->PrintMessage("Select all " + PlayingColor.Color2String() + " " + Fig);

		while (Count)
		{
			pUI->GetPointClicked(P.x, P.y);
			shape* SFig = pControl->GetFigure(P.x,P.y);
			if (SFig)      
			{
				if (SFig->GetC() == PlayingColor && SFig->GetF() == Fig)
				{
					Correct++;                             
					Count--;                                
				}
				else
					Wrong++; 

				pUI->ClearDrawArea();                    
				SFig->Hide(true);                           
				pControl->UpdateInterface();
				pUI->PrintMessage("Correct Ans = " + to_string(Correct) + "           "
					+ "Wrong Ans = " + to_string(Wrong) + "                " + "Score = " + to_string((3 * Correct) - Wrong));
			}

			else if (pUI->InDrawingArea(P.x, P.y))       
				pUI->PrintMessage("Correct Ans = " + to_string(Correct) + "        "
					+ "Wrong Ans = " + to_string(Wrong) + "        " + "Score = " + to_string((3 * Correct) - Wrong) + "                  Select a Figure Please");

			else                                        
			{
				pUI->PrintMessage("Correct Ans = " + to_string(Correct) + "        "
					+ "Wrong Ans = " + to_string(Wrong) + " Score = " + to_string((3 * Correct) - Wrong) + "   Please select any icon from the tool bar");
				pUI->ClearDrawArea();
				pControl->ShowAllFigures();
				return;
			}
		}

		pUI->PrintMessage("Correct Ans = " + to_string(Correct) + +"              "
			+ "Wrong Ans = " + to_string(Wrong) + " Score = " + to_string((3 * Correct) - Wrong) + "       " +
			"Click any where to continue ...");

		if (Wrong == 0 && Count == 0) {
			string Image = "images\\MenuItems\\Congratulation.jpg";
			pUI->DrawImage(Image);
		}

		pUI->GetUseroperation();
		pUI->ClearDrawArea();
		pControl->ShowAllFigures();
		pUI->PrintMessage("It's Play Mode : Please select any icon from the tool bar");
	}
	else
	{
		pUI->PrintMessage("There aren't any Colored Figures , Select another icon from toolbar");
		return;
	}
}

void PlayShapeColorMatch::Undo()
{
}

void PlayShapeColorMatch::Redo()
{
}
