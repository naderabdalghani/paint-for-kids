#include "CutAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

CutAction::CutAction(ApplicationManager * pApp) :Action(pApp) {}

bool CutAction::ReadActionParameters() {
	return true;
}

void CutAction::Execute() {
	Output* pOut = pManager->GetOutput();
	int SCount = pManager->GetSFigCount();
	CFigure**SList = pManager->GetSelectedFig();
	CFigure**CList = pManager->GetClipBoardFig();
	CFigure **TempSList = new CFigure*[SCount];


	for (int i = 0; i < SCount; i++)
	{
		TempSList[i] = SList[i];
	}
	

	if (SList[0] != NULL) {
		if (CList[0] != NULL)
			pManager->ClearClipbord();

		for (int i = 0;i < SCount;i++)
		{
			pManager->AddClipboardFig(TempSList[i]->Copy());
			pManager->DeleteFigure(TempSList[i]);
		}
		pOut->ClearDrawArea();
		pOut->PrintMessage("Figure/s is Cut");
		
		delete[] TempSList;
	}

	else 
		pOut->PrintMessage("Select Figure at First");
}
