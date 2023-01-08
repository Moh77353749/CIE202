#pragma once
#include "operations/operation.h"
#include "controller.h"
#include"Shapes/Graph.h"
#include "GUI/GUI.h"
class Copy :
    public operation
{
public:
    Copy(controller* pCont);
    virtual ~Copy(void);
    virtual void ReadParameter();
    virtual void Execute();
    void Undo() override;
    void Redo()override;
};

