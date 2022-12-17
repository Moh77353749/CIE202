#pragma once
#include "..\defs.h"
#include "..\GUI\GUI.h"
#include <fstream>
#include <vector>
using namespace std;


//Base class for all shapes
class shape
{
protected:
	int ID;		//Each shape has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo ShpGfxInfo;	//shape graphis info
	vector<string> propers;
	/// Add more parameters if needed.

public:
	void SetID(int id);
	virtual bool checkInside(Point p) = 0;
	
	
	shape(GfxInfo shapeGfxInfo);
	virtual ~shape() {}
	void SetSelected(bool s);	//select/unselect the shape
	bool IsSelected() const;	//check whether fig is selected
	string save_colors(color c);
	string shape::ConvertToString2(color cc)
	{
		if (cc == BLACK) return "BLACK";
		else if (cc == WHITE) return "WHITE";
		else if (cc == BLUE) return "BLUE";
		else if (cc == RED) return "RED";
		else if (cc == YELLOW) return "YELLOW";
		else if (cc == GREEN) return "GREEN";
		else if (cc == GREY) return "GREY";
		else if (cc == LIGHTGOLDENRODYELLOW) return "LIGHTGOLDENRODYELLOW";
		return "COLOR";
	}	color GetStrinColor2(string s) const;
	virtual void Draw(GUI* pUI) const  = 0 ;		//Draw the shape
	
	void ChngDrawClr(color Dclr);	//changes the shape's drawing color
	void ChngFillClr(color Fclr);	//changes the shape's filling color

	void ChngBorderWidth(int xx);

	///The following functions should be supported by the shape class
	///It should be overridden by each inherited shape

	///Decide the parameters that you should pass to each function	

	//virtual void Rotate() = 0;	//Rotate the shape
	//virtual void Resize() = 0;	//Resize the shape
	//virtual void Move() = 0;		//Move the shape

	virtual void Save(ofstream& OutFile) = 0;	//Save the shape parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the shape parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all shape info on the status bar
};

