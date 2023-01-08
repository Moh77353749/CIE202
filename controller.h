#pragma once

#include "DEFS.h"
#include "Shapes\Graph.h"
#include "GUI\GUI.h"
#include <vector>
class operation; //forward declaration
class Graph;

//Main class that manages everything in the application.
class controller
{

	int FigCount;		//Actual number of figures
	Graph* pGraph;	//pointe to the grapg
	GUI* pGUI;		//Pointer to UI class
	GUI* pUI;
	shape* FigList[200];
	shape* SLObj = nullptr;
	int NumCopiedfig = 0;


	

public:	
	controller(); 
	~controller();
	
	// -- operation-Related Functions
	//Reads the input command from the user and returns the corresponding operation type
	operationType GetUseroperation() const;
	
	operation* createOperation(operationType) ; //Creates an operation
	color ConvertToColor(string s);
	void LoadFig();
	void AddFigure(shape* pFig);
	void Run();
	
	Graph* getGraph() const;
	void SetObjSEL(shape* SEL);
	shape* GetObjSEL();



	void FigNull(shape* pF);
	int GetFigCount();
	shape* CopiedFigList[200];
	void GetFigList(shape* FigNewList[]);
	void setNumCopiedFiglist(shape* f1);
	int getNumCopiedFiglist();

	
	// -- Interface Management Functions
	GUI* GetUI() const; //Return pointer to the UI

	void UpdateInterface() const;	//Redraws all the drawing window	

	GUI* GetInput() const;

	GUI* GetOutput() const;

};

