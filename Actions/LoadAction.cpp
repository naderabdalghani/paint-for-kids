#include "LoadAction.h"

#include "..\Figures\CFigure.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


LoadAction::LoadAction(ApplicationManager * pApp) :Action(pApp)
{
	LFig = NULL;
}

bool LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Load: Enter file name");
	FileName = pIn->GetSrting(pOut);
	return true;
}


void LoadAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	File.open(FileName, ios::in);
	string DrawClr, FillClr;
	int Figcount;

	if (File.is_open())     //Check if There is a File with this Name or Not
		{
		pOut->ClearDrawArea();
		pManager->ClearFigList();
		pManager->ClearSFigList();

		//Load Drawing and Filling Color
		File >> DrawClr >> FillClr;
		pOut->getCrntDrawColor().String2Color(DrawClr);

		//Check if there was a Filling Color or Not
		if (FillClr != "False") {
			pOut->SetDefFILL(true);
			pOut->getCrntFillColor().String2Color(FillClr);
		}
		else
			pOut->SetDefFILL(false);
	
		string Fig;
		int FCount;

		//Load Figures Count	
		File >> FCount;

		while (File >> Fig)
		{
			if (Fig == "LINE")
				LFig = new CLine;

			else if (Fig == "CIRCLE")
				LFig = new CCircle;

			else if (Fig == "RECTANGLE")
				LFig = new CRectangle;

			else if (Fig == "TRIANGLE")
				LFig = new CTriangle;

			LFig->Load(File);
			pManager->AddFigure(LFig);
			LFig = NULL;

		}

		File.close();
		pOut->ClearStatusBar();
		pOut->PrintMessage("File is Loaded Successfully");
	}

	else
		pOut->PrintMessage("Error: Could not open the file!");
}