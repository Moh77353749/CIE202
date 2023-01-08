#pragma once



#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"
#include "../CMUgraphicsLib/image.h"
#include <windows.h>
#include <string>
using namespace std;

struct Point	//To be used for shapes points
{
	int x, y;
};

struct GfxInfo	//Graphical info common for all shapes (you may add more members)
{
	color DrawClr;	//Draw color of the shape
	color FillClr;
	color BkGrndColor;	//Fill color of the shape
	bool isFilled;	//shape Filled or not
	int BorderWdth;	//Width of shape borders
	bool isSelected;
	
	//true if the shape is selected.
};



class shape;
class GUI 
{
	enum GUI_MODE	//Graphical user interface mode
	{
		MODE_DRAW,	//Drawing mode (startup mode)
		MODE_Resize,	//
		MODE_PLAY	//Playing mode
	};


	enum DrawMenuIcon //The icons of the Draw menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_LINE,		//Line icon in menu
		ICON_TRI,		//Triangel Icon
		ICON_RECT,		//Recangle icon in menu
		ICON_SQU,
		ICON_CIRC,	//Circle icon in menu
		ICON_OVAL,
		ICON_PLAY,
		ICON_SEL, 
		ICON_LOAD,
		ICON_SAVE,
		ICON_resize,
		ICON_brod,
		ICON_DELETE,
		ICON_ZOOMin,
		ICON_ZOOMout,
		//TODO: Add more icons names here
		ICON_CHNG_FILL_CLR,
		ICON_CHNG_PEN_WID,
		ICON_EXIT,		//Exit icon
		ICON_CHNG_PEN_CLR,
		DRAW_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};
	enum DrawResizeItems
	{
		ICON_QUARTER,
		ICON_HALF,
		ICON_DOUBLE,
		ICON_QUADRUPLE,
		/*ICON_RESIZEBACK*/

		ICON_COUNT
	};


	enum PlayMenuIcon //The icons of the Play menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_HIDE,

		//TODO: Add more icons names here

		PLAY_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};


	GUI_MODE InterfaceMode;

	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuIconWidth;		//Width of each icon in toolbar menu
	float scalingFactor;

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes
	bool selec;

	/// Add more members if needed


protected:
	window* pWind;

public:

	GUI();

	// Input Functions  ---------------------------
	void GetPointClicked(int& x, int& y) const;
	color GetcolorClicked(int x, int y) const;
	//Get coordinate where user clicks
	string GetSrting() const;	 //Returns a string entered by the user
	operationType GetUseroperation() const; //Read the user click and map to an operation

	// Output Functions  ---------------------------
	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar();
	void CreateResizeToolBar();
	//creates Draw mode toolbar & menu
	void CreatePlayToolBar();	//creates Play mode toolbar & menu
	void CreateStatusBar() const;
	void ClearToolBar() const;
	void drawcolor();
	//create the status bar
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- shapes Drawing functions
	void Draw_Rect(Point P1, Point P2, GfxInfo RectGfxInfo) const;  //Draw a rectangle
	void Draw_Line(Point P1, Point P2, GfxInfo LineGfxInfo) const; //Draw Line
	void Draw_Tri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo) const; //Draw Rectangle
	void DrawSqu(Point P1, Point P2, GfxInfo SquGfxInfo) const;
	void Draw_Circ(Point P1, Point P2, GfxInfo CircGfxInfo)const;
	void DrawOval(Point focal1, Point focal2, GfxInfo OvGfxInfo) const;
	///Make similar functions for drawing all other shapes.
	void setCrntDrawColor(color BLUE); // set drawing color of shapes
	void setCrntPenWidth(int width);
	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	void setCrntFillColor(color RED);
	void ChngBorderWidth(int xx);
	color ChngDrawClr() const;
	void setChngDrawClr(color c);
	float zoomIn()const;
	float zoomOut()const;
	void worldToScreen(Point& point);
	void screenToWorld(Point& point);
	int getCrntPenWidth() const;
	string ReadFileName(string msg);
	//void Draw_Image(string name, Point P, int W, int H);

	void PrintMessage(string msg) const;	//Print a message on Status bar

	//void SetSelected(bool s);
	
	~GUI();
};


