#include "SwitchToPlay.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SwitchToPlay::SwitchToPlay(ApplicationManager * pApp) :Action(pApp) {}

bool SwitchToPlay::ReadActionParameters() {
	return true;
}

void SwitchToPlay::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	pManager->ClearSFigList();
	pOut->PrintMessage("Switch to Play Mode");
	UI.InterfaceMode = MODE_PLAY;
	pOut->CreatePlayToolBar();	
}