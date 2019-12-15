#include "SaveAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


SaveAction::SaveAction(ApplicationManager * pApp) :Action(pApp) {}

bool SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Save: Enter file name");
	file_name = pIn->GetSrting(pOut);
	pOut->PrintMessage("File Saved Successfully");
	return true;
}


void SaveAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	file.open(file_name, ios::out);
	if (pOut->GetDefFILL() == false)
		file << (pOut->getCrntDrawColor()).Color2String() << "  " << "False" << endl;
	else 
	file << (pOut->getCrntDrawColor()).Color2String() << "  " << (pOut->getCrntFillColor()).Color2String() << endl;

	pManager->SaveAll(file);
	file.close();
}

