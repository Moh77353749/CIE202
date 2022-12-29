#include "opsave.h"
#include "Shapes/Shape.h"
#include "controller.h"
#include "Shapes/Graph.h"
using namespace std;
opsave::opsave(controller* pCont) : operation{ pCont }
{
	file_name = "screen 1";
}

void opsave::Execute()
{
	GUI* P = pControl->GetUI();
	P->PrintMessage("wite the file name");
	file_name = P->GetSrting();
	P->ClearStatusBar();
	ofstream Out_file;
	Out_file.open(file_name + ".txt");

	while (Out_file.fail())
	{
		P->PrintMessage("Please write a valid name then press ENTER");
		file_name = P->GetSrting();
		Out_file.open(file_name + ".txt");
		if (Out_file.good())
			break;
	}
	Graph* g;
	g=pControl->getGraph();
	g->Save_shapes(Out_file);
}
