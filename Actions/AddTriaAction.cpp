#include "AddTriaAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriaAction::AddTriaAction(ApplicationManager * pApp) :Action(pApp)
{
	P1.x = 0;
	P1.y = 0;
	P2.x = 0;
	P2.y = 0;
	P3.x = 0;
	P3.y = 0;
	
}

bool AddTriaAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	if (!pIn->InDrawingArea(P1.x, P1.y))
	{
		pOut->PrintMessage("Invalid Point");
		return false;
	}


	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	if (!pIn->InDrawingArea(P2.x, P2.y))
	{
		pOut->PrintMessage("Invalid Point");
		return false;
	}


	pOut->PrintMessage("New Triangle: Click at third corner");

	//Read 3rd corner and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);
	if (!pIn->InDrawingArea(P3.x, P3.y))
	{
		pOut->PrintMessage("Invalid Point");
		return false;
	}


	TriaGfxInfo.isFilled = pOut->GetDefFILL();	//default is not filled
									                //get drawing, filling colors and pen width from the interface
	TriaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
	return true;
}

//Execute the action
void AddTriaAction::Execute()
{
	//This action needs to read some parameters first
	if (ReadActionParameters())
	{
		//Create a Triangle with the parameters read from the user
		CTriangle *T = new CTriangle(P1, P2, P3, TriaGfxInfo);

		//Add the Triangle to the list of figures
		pManager->AddFigure(T);

	}
}
