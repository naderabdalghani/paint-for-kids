#include "ResizeAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ResizeAction::ResizeAction(ApplicationManager * pApp) :Action(pApp)
{
	P.x = 0;
	P.y = 0;
	Scale = 0.0;
}

bool ResizeAction::ReadActionParameters() {
	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	pOut->PrintMessage("Resize Figure : Choose The Scale");

	//Read Point Parameters

		SCALE = pIn->GetUserAction();
		if (!GetScale(SCALE))
		{
			pOut->PrintMessage("Invalid Point : Choose Scale Please");
			return false;
		}
	
	pOut->ClearStatusBar();
	return true;
}


//Execute the action
void ResizeAction::Execute()
{

	//This action needs to read some parameters first
	if (ReadActionParameters())
	{
		Output* pOut = pManager->GetOutput();
		int SCount = pManager->GetSFigCount();
		CFigure**SList = pManager->GetSelectedFig();

		if (SList[0] != NULL)    //if There was a Selected Figure Resize it 
		{
			for (int i = 0;i < SCount;i++)
				SList[i]->Resize(Scale);

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

bool ResizeAction::GetScale(ActionType S) {    //Convert ActionType to int
	switch (S)
	{
	case TWO:
		Scale = 2;
		return true;
	case FOUR:
		Scale = 4;
		return true;
	case HALF:
		Scale = 0.5;
		return true;
	case QUARTER:
		Scale = 0.25;
		return true;
	default:
		return false;
	}

}
