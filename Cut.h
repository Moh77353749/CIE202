#pragma once
#include "operations/operation.h"
#include "controller.h"
#include"Shapes/Graph.h"
#include "GUI/GUI.h"

class Cut :
    public operation
{
public:
    Cut(controller* pCont);
    virtual ~Cut(void);
    virtual void ReadParameter();
    virtual void Execute();
    void Undo() override;
    void Redo()override;
};

