#include "RotateAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

RotateAction::RotateAction(ApplicationManager * pApp) :Action(pApp)
{
	P.x = 0;
	P.y = 0;
	Angle = 0.0;
}

bool RotateAction::ReadActionParameters() {

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("RotateAction Figure : Choose The angle");

	//Read Point Parameters

	ANGLE = pIn->GetUserAction();
	if (!GetDegree(ANGLE))
	{
		pOut->PrintMessage("Invalid Point : Choose angle Please");
		return false;
	}
	
	pOut->ClearStatusBar();
	return true;
}


//Execute the action
void RotateAction::Execute()
{
	//This action needs to read some parameters first
	if (ReadActionParameters())
	{
		Output* pOut = pManager->GetOutput();
		int SCount = pManager->GetSFigCount();
		CFigure**SList = pManager->GetSelectedFig();

		if (SList[0] != NULL)    //if There was a Selected Figure Rotate it 
		{
			for (int i = 0;i < SCount;i++)
				SList[i]->Rotate(Angle);

			pOut->ClearDrawArea();

			for (int i = 0;i < SCount;i++)
				if (SList[i]->IsLastSelected())
				{
					SList[i]->printinfo(pOut);
					break;
				}
		}

		else
			pOut->PrintMessage("Select Figure at First");
	}
}

bool RotateAction::GetDegree(ActionType A) {    //Convert ActionType to int
	switch (A)
	{
	case ROTATE90:
		Angle = 90;
		return true;
	case ROTATE180:
		Angle = 180;
		return true;
	case ROTATE270:
		Angle = 270;
		return true;
	default:
		return false;
	}

}
