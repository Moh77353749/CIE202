#include "GUI.h"
#include "..\controller.h"

GUI::GUI()
{
	//Initialize user interface parameters
	InterfaceMode = MODE_DRAW;

	width = 1600;
	height = 700;
	wx = 5;
	wy = 5;


	StatusBarHeight = 50;
	ToolBarHeight = 50;
	MenuIconWidth = 80;

	DrawColor = BLUE;	//default Drawing color
	FillColor = GREEN;	//default Filling color
	MsgColor = BLACK;		//Messages color
	BkGrndColor = WHITE;	//Background color
	HighlightColor = MAGENTA;	//This color should NOT be used to draw shapes. use if for highlight only
	StatusBarColor = LIGHTSEAGREEN;
	PenWidth = 3;	//default width of the shapes frames


	//Create the output window
	pWind = CreateWind(width, height, wx, wy);
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - PAINT ^ ^ PLAY - - - - - - - - - -");

	CreateDrawToolBar();
	drawcolor();
	CreateStatusBar();
}






//======================================================================================//
//								Input Functions										//
//======================================================================================//
void GUI::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click

}
color GUI::GetcolorClicked(int x, int y) const
{
		//Wait for mouse click
	return pWind->GetColor(x, y);
}

string GUI::GetSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if( Label.size() > 0)	
				Label.resize(Label.size() - 1);
			else
				Key = '\0';		
		else
			Label += Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired operation
operationType GUI::GetUseroperation() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder)
			{
			case ICON_LINE: return DRAW_LINE;
			case ICON_TRI:  return DRAW_TRI;
			case ICON_RECT: return DRAW_RECT;
			case ICON_CIRC: return DRAW_CIRC;
			case ICON_SQU: return  DRAW_Squ;
			case ICON_OVAL: return DRAW_OVAL;
			case ICON_PLAY: return TO_PLAY;
			case ICON_LOAD:  return LOAD;
			case ICON_SEL:  return SELECT;
			case ICON_CHNG_PEN_WID: return CHNG_PEN_WID;
			case ICON_CHNG_PEN_CLR: return CHNG_DRAW_CLR;
			case ICON_SAVE: return SAVE;
			case ICON_brod: return actionch;
			case ICON_DELETE: return DEL;
			case ICON_EXIT: return EXIT;
			case ICON_CHNG_FILL_CLR: return CHNG_FILL_CLR;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding operation
		return TO_PLAY;	//just for now. This should be updated
	}

}
////////////////////////////////////////////////////



//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(BkGrndColor);
	pW->SetPen(BkGrndColor, 1);
	pW->DrawRectangle(0, ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}

void GUI::ClearToolBar() const
{
	pWind->SetPen(DrawColor, 1);
	pWind->SetBrush(DrawColor);
	pWind->DrawRectangle(0, 0, width, ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::drawcolor()
{
	pWind->DrawImage("images\\MenuIcons\\Colours.jpg", 1350, 50, 1500, 600);

}
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() 
{
	InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu icon
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuIcon
	string MenuIconImages[DRAW_ICON_COUNT];
	MenuIconImages[ICON_LINE] = "images\\MenuIcons\\Menu_Line.JPEG";
	MenuIconImages[ICON_TRI]  = "images\\MenuIcons\\Menu_Tri.JPEG";
	MenuIconImages[ICON_RECT] = "images\\MenuIcons\\Menu_Rect.JPEG";
	MenuIconImages[ICON_SQU] = "images\\MenuIcons\\Menu_Squ.jpg";
	MenuIconImages[ICON_CIRC] = "images\\MenuIcons\\Menu_Circ.JPEG";
	MenuIconImages[ICON_SEL]  = "images\\MenuIcons\\Menu_Sel.JPEG";
	MenuIconImages[ICON_DELETE] = "images\\MenuIcons\\Menu_Del.JPEG";
	MenuIconImages[ICON_brod] = "images\\MenuIcons\\pen.JPG";
	MenuIconImages[ICON_LOAD] = "images\\MenuIcons\\Menu_Download.JPG";
	MenuIconImages[ICON_SAVE] = "images\\MenuIcons\\Menu_Save.JPEG";
	MenuIconImages[ICON_EXIT] = "images\\MenuIcons\\Menu_Exit.JPEG";
	MenuIconImages[ICON_OVAL] = "images\\MenuIcons\\Menu_OVAL.jpg";
	MenuIconImages[ICON_PLAY] = "images\\MenuIcons\\Menu_Play.jpg";
	MenuIconImages[ICON_CHNG_PEN_WID] = "images\\MenuIcons\\Menu_CHNG_PEN_WID.JPEG";
	MenuIconImages[ICON_CHNG_PEN_CLR] = "images\\MenuIcons\\Menu_CHNG_PEN_CLR.JPEG";
	MenuIconImages[ICON_CHNG_FILL_CLR] = "images\\MenuIcons\\Menu_CHNG_FILL_CLR.JPEG";
	//Draw menu icon one image at a time
	for (int i = 0; i < DRAW_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);
	pWind->DrawImage("images\\MenuIcons\\Colours.jpg", 1350, 50, 1500, 600);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////


void GUI::CreatePlayToolBar() 
{
	InterfaceMode = MODE_PLAY;

	string MenuIconImages[PLAY_ICON_COUNT];
	MenuIconImages[ICON_HIDE] = "images\\MenuIcons\\Play_hide.jpg";


	for (int i = 0; i < DRAW_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);
	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearDrawArea() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight - 3);
	

}
//////////////////////////////////////////////////////////////////////////////////////////

/*
void GUI::Draw_Image( string name, Point P, int W, int H)
{

	pWind->DrawImage(name, P.x, P.y, W, H);
}
*/


void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, height - (int)(0.75 * StatusBarHeight), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::setCrntDrawColor(color BLUE)
{
	DrawColor = BLUE;

}

void GUI::setCrntPenWidth(int width)
{
	
	PenWidth = width;
	
}

color GUI::getCrntDrawColor() const	//get current drwawing color
{
	return DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

//Return a pointer to the output
GUI* controller::GetOutput() const
{
	return pUI;
}


color GUI::getCrntFillColor() const	//get current filling color
{
	return FillColor;
}
void GUI::setCrntFillColor(color c)
{
	FillColor = c;

}
//int GUI::ChngBorderWidth() const	//get current filling color
//{
//	return PenWidth;
//}
//void GUI::ChngBorderWidth(int xx)
//{
//	
//
//}

void GUI::ChngBorderWidth(int xx)
{
	PenWidth = xx;
}

color GUI::ChngDrawClr() const	//get current filling color
{
	return DrawColor;
}
void GUI::setChngDrawClr(color c)
{
	DrawColor = c;

}
//////////////////////////////////////////////////////////////////////////////////////////

int GUI::getCrntPenWidth() const		//get current pen width
{
	return PenWidth;
}

string GUI::ReadFileName(string msg)       //read file name to save or load
{
	PrintMessage(msg);
	return GetSrting();
}

//======================================================================================//
//								shapes Drawing Functions								//
//======================================================================================//

void GUI::Draw_Rect(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void GUI::Draw_Line(Point P1, Point P2, GfxInfo LineGfxInfo) const
{
	color DrawingClr;
	if (LineGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, LineGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (LineGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(LineGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);

}
void GUI::Draw_Tri(Point P1, Point P2,Point P3, GfxInfo TriGfxInfo) const
{
	color DrawingClr;
	if (TriGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TriGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}

void GUI::DrawSqu(Point P1, Point P2, GfxInfo SquGfxInfo) const
{
	color DrawingClr, FillClr;
	if (SquGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = SquGfxInfo.DrawClr;


	pWind->SetPen(DrawingClr, SquGfxInfo.BorderWdth);	//Set Drawing color & width

	pWind->SetPen(FillClr, SquGfxInfo.isSelected);

	drawstyle style;
	if (SquGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}


void GUI::Draw_Circ(Point P1, Point P2, GfxInfo CircGfxInfo) const
{
	color DrawingClr;
	if (CircGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, CircGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawCircle(P1.x, P1.y, pow(pow((P2.x - P1.x), 2) + pow((P2.y - P1.y), 2), 0.5), style);

}

void GUI::DrawOval(Point focal1, Point focal2, GfxInfo OvGfxInfo) const
{
	color DrawingClr;
	if (OvGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = OvGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, OvGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (OvGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(OvGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawEllipse(focal1.x, focal1.y, focal2.x, focal2.y, style);

}

//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}

