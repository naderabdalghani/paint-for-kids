#include "SelectAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager * pApp) :Action(pApp)
{
	P.x = 0;
	P.y = 0;
}

bool SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select Figure : Click at any Figure");

	//Read Point Parameters
	pIn->GetPointClicked(P.x, P.y);
	if (!pIn->InDrawingArea(P.x, P.y))
	{
		pOut->PrintMessage("Invalid Point");
		return false;
	}

	pOut->ClearStatusBar();
	return true;
}

//Execute the action
void SelectAction::Execute()
{
	//This action needs to read some parameters first
	if (ReadActionParameters())
	{
		Output* pOut = pManager->GetOutput();
		int SCount = pManager->GetSFigCount();
		CFigure**SList = pManager->GetSelectedFig();
		CFigure *SFig = pManager->GetFigure(P.x, P.y);


		if (SFig)
		{

			if (SList[0] != NULL)        //if There is any Previous Selected Figure 
			{
				//Clicked at the same Figure ,, Unselect it 
				for (int i = 0;i < SCount;i++)
				{
					if (SFig == SList[i])
					{
						pManager->UnSelectedFig(SFig);
						pOut->ClearStatusBar();
						SFig = NULL;
						return;
					}
				}
			}
			pManager->SelectFig(SFig);
			SFig->printinfo(pOut);
			SFig = NULL;
		}
		else                                                    //if User Clicked in empty Area
		{
			pOut->PrintMessage("Select Figure Please");
			return;
		}
	}

}
