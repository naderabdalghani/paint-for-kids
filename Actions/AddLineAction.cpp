#include "AddLineAction.h"
#include "..\Figures\CLine.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddLineAction::AddLineAction(ApplicationManager * pApp) :Action(pApp)
{
	P1.x = 0;
	P1.y = 0;
	P2.x = 0;
	P2.y = 0;
}

bool AddLineAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at first Point");

	//Read 1st Point and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	if (!pIn->InDrawingArea(P1.x, P1.y))
	{
		pOut->PrintMessage("Invalid Point");
		return false;
	}


	pOut->PrintMessage("New Line: Click at second point");

	//Read 2nd Point and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	if (!pIn->InDrawingArea(P2.x, P2.y))
	{
		pOut->PrintMessage("Invalid Point");
		return false;
	}


	LineGfxInfo.isFilled = pOut->GetDefFILL();	//default is not filled
									//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
	return true;
}

//Execute the action
void AddLineAction::Execute()
{
	//This action needs to read some parameters first
	if (ReadActionParameters())
	{
	
		//Create a Line with the parameters read from the user
		CLine *L = new CLine(P1, P2, LineGfxInfo);

		//Add the Line to the list of figures
		pManager->AddFigure(L);

	}

}
