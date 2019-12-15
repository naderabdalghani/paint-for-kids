#include "SwitchToDraw.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SwitchToDraw::SwitchToDraw(ApplicationManager * pApp) :Action(pApp)
{}

bool SwitchToDraw::ReadActionParameters() {
	return true;
}

void SwitchToDraw::Execute()
{
	Output* pOut = pManager->GetOutput();
	UI.InterfaceMode = MODE_DRAW;
	pOut->PrintMessage("Switch to draw mode");
    pOut->CreateDrawToolBar();
}