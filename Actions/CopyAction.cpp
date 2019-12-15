#include "CopyAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

CopyAction::CopyAction(ApplicationManager * pApp) :Action(pApp){}

bool CopyAction::ReadActionParameters(){
	return true;
}

void CopyAction::Execute() {

	Output* pOut = pManager->GetOutput();
	int SCount = pManager->GetSFigCount();
	CFigure**SList = pManager->GetSelectedFig();
	CFigure**CList = pManager->GetClipBoardFig();

	if (SList[0] != NULL) {
		if(CList[0] != NULL)
			pManager->ClearClipbord();

		for (int i = 0;i < SCount;i++)
			pManager->AddClipboardFig(SList[i]->Copy());
	}
	else
		pOut->PrintMessage("Select Figure at first");
	
}

