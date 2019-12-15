#include "AddCircAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircAction::AddCircAction(ApplicationManager * pApp) :Action(pApp)
{
	P1.x = 0;
	P1.y = 0;
	P2.x = 0;
	P2.y = 0;
}

bool AddCircAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at Cicrle Center");

	//Read Center and store in point P1
		pIn->GetPointClicked(P1.x, P1.y);
		if (!pIn->InDrawingArea(P1.x, P1.y))
		{
			pOut->PrintMessage("Invalid Point");
			return false;
		}

	

	pOut->PrintMessage("New Circle: Click at any point on Circumference");

	//Read circumference point and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	if (!pIn->InDrawingArea(P2.x, P2.y))
	{
		pOut->PrintMessage("Invalid Point");
		return false;
	}


	CircGfxInfo.isFilled = pOut->GetDefFILL();	//default is not filled
									                
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor(); //get drawing, filling colors and pen width from the interface
	CircGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
	return true;

}

//Execute the action
void AddCircAction::Execute()
{
	//This action needs to read some parameters first
	if (ReadActionParameters())
	{

		//Create a circle with the parameters read from the user
		CCircle *C = new CCircle(P1, P2, CircGfxInfo);

		//Add the rectangle to the list of figures
		pManager->AddFigure(C);

	}
}
