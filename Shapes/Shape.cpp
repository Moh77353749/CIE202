#include "shape.h"

void shape::SetID(int id)
{
	ID = id;
}



shape::shape(GfxInfo shapeGfxInfo)
{ 
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
}
 
void shape::SetSelected(bool s)
{	ShpGfxInfo.isSelected = s; }

bool shape::IsSelected() const
{	return ShpGfxInfo.isSelected; }

string shape::save_colors(color c)
{

	if (c== RED) return "RED";
	if (c==BLUE) return "BLUE";
	if (c== WHITE) return "WHITE";
	if (c== GREEN) return "GREEN";
	if (c==BLACK) return "BLACK";
	if (c==YELLOW) return "YELLOW";
	if (c == LIGHTGOLDENRODYELLOW)return "LIGHTGOLDENRODYELLOW";
	if (c == MAGENTA)return "MAGENTA";
	if (c == TURQUOISE) return "TURQUOISE";
}

//string shape::ConvertToString2(color cc)
//{
//	if (cc == BLACK) return "BLACK";
//	else if (cc == WHITE) return "WHITE";
//	else if (cc == BLUE) return "BLUE";
//	else if (cc == RED) return "RED";
//	else if (cc == YELLOW) return "YELLOW";
//	else if (cc == GREEN) return "GREEN";
//	else if (cc == GREY) return "GREY";
//	else if (cc == LIGHTGOLDENRODYELLOW) return "LIGHTGOLDENRODYELLOW";
//	return "COLOR";
//}
color shape::GetStrinColor2(string s) const
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
	if (s == "MAGENTA")
		return MAGENTA;
	if (s == "TURQUOISE")
		return TURQUOISE;
	return BLACK;
}
void shape::ChngDrawClr(color Dclr)
{	ShpGfxInfo.DrawClr = Dclr; }

void shape::ChngFillClr(color Fclr)
{	
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr; 
}

void shape::ChngBorderWidth(int xx)
{
	ShpGfxInfo.BorderWdth = xx;
}

