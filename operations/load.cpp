#include "LoAd.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include "../Shapes/Rect.h"
#include "../Shapes/Oval.h"
#include "../Shapes/Line.h"
#include "../Shapes/Circ.h"
#include "../Shapes/Tri.h"
#include "../Shapes/Squ.h"
#include"../Shapes/Shape.h"
#include"../opsave.h"




LoAd::LoAd(controller* pCont) :operation(pCont)
{

}





//Execute the action
void LoAd::Execute()
{
	ifstream InFile;         //object of ifstream class
	string name, DrawClr, FillClr;
	int Cnt;
	GfxInfo Info;
	shape* figure;
	GUI* n = pControl->GetUI();
	n->PrintMessage("wite the file name");
	
	
	
	FileName = n->GetSrting();     //get the file name

	InFile.open(FileName + ".txt"); //open the file on the disk with FileName name and .txt exetension
	n->ClearDrawArea();    //Clear current graph

	if (InFile.fail())       //Check if the FileName is a valid name
	{
		n->PrintMessage("Invalid Name");
		return;
	}
	string drawColor, fillColor, bgColor, figType;
	int figsNum;
	ifstream Infile;

	string fileName= n->ReadFileName("Load: Enter file name to load from...");
	Infile.open("Saves\\" + fileName + ".txt");
	if (Infile.fail())
	{
		n->PrintMessage("File '" + fileName + "' does not exist!");
	}
	else
	{
		//reading window colors
		Infile >> drawColor >> fillColor >> bgColor;

		//using coloring actions to apply new colors
		//changing window drawing color
		n->getCrntDrawColor() = pControl->ConvertToColor(DrawClr);  //Convert them
		n->getCrntFillColor() = pControl->ConvertToColor(FillClr);  //To Colo
		

		if (fillColor != "NO_FILL")
		{
			n->setCrntFillColor(true);
			//changing window filling color if it was set
			n->getCrntFillColor() = pControl->ConvertToColor(FillClr);  //To Colo
			
		}
	

		Infile >> figsNum;
		Point X, Y,Z;
		//loading figures
		while (figsNum > 0)
		{
			shape* fig;
			Infile >> figType;
			if (figType == "RECT") fig = new Rect(X, Y, Info);
			if (figType == "OVAL") fig = new Oval(X, Y, Info);
			if (figType == "SQU") fig = new Squ(X, Y, Info);
			if (figType == "LINE") fig = new Line(X, Y, Info);
			if (figType == "TRI") fig = new Tri(X, Y,Z ,Info);
			if (figType == "CRIC") fig = new Circ(X, Y, Info);

			//calling load function for each figure
			fig->Load(Infile);
			pControl->AddFigure(fig);
			figsNum--;
		}
		//update drawing area with loaded figures
		pControl->UpdateInterface();
		//cofirmation message
		n->PrintMessage("file loaded successfully!");
	}
}
	
void LoAd::Undo()
{

}

void LoAd::Redo()
{

}