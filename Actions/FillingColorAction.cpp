#include "FillingColorAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

FillingColorAction::FillingColorAction(ApplicationManager * pApp) :Action(pApp)
{}

bool FillingColorAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Choose Filling Color");

	//Read Point Parameters

	
		FCOLOR = pIn->GetUserAction();
		if (!GetColor(FCOLOR))
		{
		  pOut->PrintMessage("Invalid Point");
		  return false;
		}
	

	pOut->ClearStatusBar();
	return true;
}

//Execute the action
void FillingColorAction::Execute()
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
				SList[i]->ChngFillClr(FColor);

			pOut->ClearDrawArea();
		}

		else                  //else change The default Drawing Color
		{
			pOut->SetDefFILL(true);
			pOut->SetCrntFillColor(FColor);
		}

		for (int i = 0;i < SCount;i++)
			if (SList[i]->IsLastSelected())
			{
				SList[i]->printinfo(pOut);
				break;
			}
	}
}

bool FillingColorAction::GetColor(ActionType C)      //Convert Actiontype to Color
{
	switch (C)
	{
	case CRED:
		FColor = RED;
		return true;
	case CBLUE:
		FColor = BLUE;
		return true;
	case CBLACK:
		FColor = BLACK;
		return true;
	case CWHITE:
		FColor = WHITE;
		return true;
	case CGREEN:
		FColor = GREEN;
		return true;
	case CDARKRED:
		FColor = DARKRED;
		return true;
	case CLIGHTBLUE:
		FColor = LIGHTBLUE;
		return true;
	case CPINK:
		FColor = PINK;
		return true;
	case CORANGE:
		FColor = ORANGE;
		return true;
	case CYELLOW:
		FColor = YELLOW;
		return true;
	default:
		return false;
	}
}
