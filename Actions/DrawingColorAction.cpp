#include "DrawingColorAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DrawingColorAction::DrawingColorAction(ApplicationManager * pApp) :Action(pApp)
{}

bool DrawingColorAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Choose Drawing Color");

	//Read Point Parameters

	DCOLOR = pIn->GetUserAction();
	if (!GetColor(DCOLOR))
	{
		pOut->PrintMessage("Invalid Point");
		return false;
	}


	pOut->ClearStatusBar();
	return true;

}

//Execute the action
void DrawingColorAction::Execute()
{
	//This action needs to read some parameters first
	if (ReadActionParameters())
	{
		Output* pOut = pManager->GetOutput();
		int SCount = pManager->GetSFigCount();
		CFigure**SList = pManager->GetSelectedFig();

		if (SList[0] != NULL)    //if There was a Selected Figure Change its drawing Color
		{
			for (int i = 0;i < SCount;i++)
				SList[i]->ChngDrawClr(DColor);
			pOut->ClearDrawArea();
		}

		else                  //else change The default Drawing Color
			pOut->SetCrntDrawColor(DColor);

		for (int i = 0;i < SCount;i++)
			if (SList[i]->IsLastSelected())
			{
				SList[i]->printinfo(pOut);
				break;
			}
	}
}

bool DrawingColorAction::GetColor(ActionType C)   //Convert Actiontype to Color
{
	switch (C)
	{
	case CRED:
		DColor = RED;
		return true;
	case CBLUE:
		DColor = BLUE;
		return true;
	case CBLACK:
		DColor = BLACK;
		return true;
	case CWHITE:
		DColor = WHITE;
		return true;
	case CGREEN:
		DColor = GREEN;
		return true;
	case CDARKRED:
		DColor = DARKRED;
		return true;
	case CLIGHTBLUE:
		DColor = LIGHTBLUE;
		return true;
	case CPINK:
		DColor = PINK;
		return true;
	case CORANGE:
		DColor = ORANGE;
		return true;
	case CYELLOW:
		DColor = YELLOW;
		return true;
	default:
		return false;
	}
}

