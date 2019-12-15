#include "DeleteAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteAction::DeleteAction(ApplicationManager * pApp) :Action(pApp) {}


bool DeleteAction::ReadActionParameters() {
	return true;
}


//Execute the action
void DeleteAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	int SCount = pManager->GetSFigCount();
	CFigure**SList = pManager->GetSelectedFig();
	CFigure **TempSList = new CFigure*[SCount];

	for (int i = 0; i < SCount; i++)
	{
		TempSList[i] = SList[i];
	}

	if (SList[0] != NULL) {   //if There was a Selected Figure Delete it  
		for (int i = 0;i < SCount;i++)
		{
			pManager->DeleteFigure(TempSList[i]);
		}

		pOut->ClearDrawArea();
		pOut->PrintMessage("Figure/s is Deleted");

		delete[] TempSList;
	}
	else
		pOut->PrintMessage("Select Figure at First");
	
}
