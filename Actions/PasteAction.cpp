#include "PasteAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

PasteAction::PasteAction(ApplicationManager * pApp) :Action(pApp)
{
	P.x = 0;
	P.y = 0;
	F = NULL;
}

bool PasteAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click anywhere to Paste the copied/cut Figure");
	

	pIn->GetPointClicked(P.x, P.y);
	if (!pIn->InDrawingArea(P.x, P.y))
	{
		pOut->PrintMessage("Invalid Point");
		return false;
	}

	pOut->ClearStatusBar();
	return true;
}

void PasteAction::Execute() {
	
	//This action needs to read some parameters first
	if (ReadActionParameters())
	{

		Output* pOut = pManager->GetOutput();
		int CCount = pManager->GetCFigCount();
		CFigure**CList = pManager->GetClipBoardFig();
		Point Mid = FiguresMid(CList, CCount);

		if (CList[0] != NULL)
		{
			for (int i = 0;i < CCount;i++)
			{
				F = CList[i]->Copy();
				F->Paste(P, Mid);
				if (F->OutsideInterface())
				{
					delete F;
					F = NULL;
				}
				else
				pManager->AddFigure(F);
			}
		}

		else
			pOut->PrintMessage("Clipboard is empty");
	}
}

Point PasteAction::FiguresMid(CFigure ** C, int CCount)
{
	Point Mid;
	Mid.x = 0; Mid.y = 0;
	for (int i = 0; i < CCount; i++)
	{
		Mid.x += C[i]->GetMid().x;
		Mid.y += C[i]->GetMid().y;
	}
	Mid.x = Mid.x / CCount;
	Mid.y = Mid.y / CCount;
	return Mid;
}



