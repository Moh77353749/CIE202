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

	int FigCount=0;		//Actual number of figures
	Graph* pGraph;	//pointe to the grapg
	GUI* pGUI;		//Pointer to UI class
	GUI* pUI;
	shape* FigList[200];
	shape* SLObj = nullptr;


	

public:	
	controller(); 
	~controller();
	
	// -- operation-Related Functions
	//Reads the input command from the user and returns the corresponding operation type
	operationType GetUseroperation() const;
	
	operation* createOperation(operationType) ; //Creates an operation
	color ConvertToColor(string s);
	void LoadFig();
	shape* getFigByIndex(int i);
	void AddFigure(shape* pFig);
	int GetFigCount();
	void Run();
	
	Graph* getGraph() const;
	void SetObjSEL(shape* SEL);
	shape* GetObjSEL();
	//void DeleteObj();
	// -- Interface Management Functions
	GUI* GetUI() const; //Return pointer to the UI

	void UpdateInterface() const;	//Redraws all the drawing window	

	GUI* GetInput() const;

	GUI* GetOutput() const;

};

