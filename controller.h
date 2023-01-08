#pragma once

#include "DEFS.h"
#include "Shapes\Graph.h"
#include "GUI\GUI.h"
#include <vector>
#include"CMUgraphicsLib/colors.h"

class operation; //forward declaration
class Graph;

//Main class that manages everything in the application.
class controller
{
	enum { MaxFigCount = 200 };
private:
	int FigCount;		//Actual number of figures
	Graph* pGraph;	//pointe to the grapg
	GUI* pGUI;		//Pointer to UI class
	GUI* pUI;
	shape* FigList[MaxFigCount];
	
	shape* SLObj = nullptr;
	int SFigCount;                         //Actual number of Selected figures
	shape** SFigList;

	//vector <shape*> FigList;

	

public:	
	controller(); 
	~controller();
	
	// -- operation-Related Functions
	//Reads the input command from the user and returns the corresponding operation type
	operationType GetUseroperation() const;
	
	operation* createOperation(operationType) ; //Creates an operation
	color ConvertToColor(string s);
	string ConvertToString(color c);
	void LoadFig();
	void AddFigure(shape* pFig);
	void Run();
	
	Graph* getGraph() const;
	shape* GetFigure(int x, int y) const;
	void SetObjSEL(shape* SEL);
	shape* GetObjSEL();
	string RandFig(int&Count)const; 
	string RandShp(int& Count)const;
	color RandClr(int& Count)const;
	string RandFigClr(int& Count, color& Color)const;
	void ShowAllFigures();
	void ClearSFigList();
	void SelectFig(shape* pFig);    
	void UnSelectedFig(shape* pFig);
	void DeleteFigure(shape* Fg);
	void setFigList(shape* Fg);

	// -- Interface Management Functions
	GUI* GetUI() const; //Return pointer to the UI

	void UpdateInterface() const;	//Redraws all the drawing window	


};

