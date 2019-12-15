#include "BackwardAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

BackwardAction::BackwardAction(ApplicationManager * pApp) :Action(pApp)
{}

bool BackwardAction::ReadActionParameters() {
	return true;
}


//Execute the action
void BackwardAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	int SCount = pManager->GetSFigCount();
	CFigure**SList = pManager->GetSelectedFig();
	CFigure **TempSList = new CFigure*[SCount];

	for (int i = 0; i < SCount; i++)
	{
		TempSList[i] = SList[i];
	}

	if (SList[0] != NULL)    //if There was a Selected Figure Backward it 
	{
		for (int i = SCount - 1;i >= 0;i--)
			pManager->BackwardFigure(TempSList[i]);

		pOut->ClearDrawArea();

		delete[] TempSList;
	}

	else 
		pOut->PrintMessage("Select Figure at First");
	
}
