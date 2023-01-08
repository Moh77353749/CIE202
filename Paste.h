#pragma once
#include "operations/operation.h"
#include "controller.h"
#include"Shapes/Graph.h"
#include "GUI/GUI.h"

class Paste :
    public operation
{
public:
    Paste(controller* pCont);
    virtual void Execute();
    void Undo() override;
    void Redo()override;
};

