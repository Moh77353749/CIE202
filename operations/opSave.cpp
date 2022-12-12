#include "opSave.h"
#include <iostream>
#include <fstream>
#include "..\controller.h"
#include "..\GUI\GUI.h"



opSave::opSave(controller* pCont, int F_c) :operation(pCont)
{
	file_name = "Screen";
	Fc = F_c;
}


void opSave::Execute()
{
	GUI* P_OUT = pControl->GetUI();
	P_OUT->PrintMessage("the file name: ");

	ofstream outPut_file;
	while (outPut_file.fail())
	{
		P_OUT->PrintMessage("reenter the file nem");
		file_name = P_OUT->GetSrting();
		outPut_file.open(file_name + ".txt");
		if (outPut_file.good())
			break;


	}


}


void opSave::Undo()
{
}

void opSave::Redo()
{
}


