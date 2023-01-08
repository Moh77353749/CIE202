#include "../Stick_image.h"
#include <iostream>
using namespace std;


Stick_image::Stick_image(Point, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
}

Stick_image::~Stick_image()
{
}

void Stick_image::Draw(GUI* pUI) const
{
	pUI->Draw_Image();
}
