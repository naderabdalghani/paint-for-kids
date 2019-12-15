#include "PlayWithType.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"


PlayWithType::PlayWithType(ApplicationManager * pApp) :Action(pApp)
{
	Correct = 0;
	Wrong = 0;
}

bool PlayWithType::ReadActionParameters() {
	return true;
}

//Execute the action
void PlayWithType::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	int Count = 0;
	Fig = pManager->RandFig(Count);
	
	if (Fig != "Empty")
	{
		pOut->PrintMessage("Select all " + Fig);

		while (Count)
		{
			pIn->GetPointClicked(P.x, P.y);
			CFigure* SFig = pManager->GetFigure(P.x, P.y);
			if (SFig)                                            //to check if user clicked on a figure or not
			{
				if (SFig->GetF() == Fig)
				{
					Correct++;                                 //if user clicked on the required figure correct ans is increased by 1
					Count--;                                   //the required figures is decreased by 1
				}
				else
					Wrong++;                                 //if user clicked on another figure wrong ans is increased by 1

				pOut->ClearDrawArea();                      //to clear drawing area;
				SFig->Hide(true);                          //calling the function to hide the selected figure 
				pManager->UpdateInterface();
				pOut->PrintMessage("Correct Ans = " + to_string(Correct) + "                                              "
					+ "Wrong Ans = " + to_string(Wrong));
			}

			else if (pIn->InDrawingArea(P.x, P.y))       //if user Click in The Drawing Area
				pOut->PrintMessage("Correct Ans = " + to_string(Correct) + "                                              "
					+ "Wrong Ans = " + to_string(Wrong) + "                  Select a Figure Please");

			else                                         //if user Click in The Tool or Status Bar
			{
				pOut->PrintMessage("Correct Ans = " + to_string(Correct) + "        "
					+ "Wrong Ans = " + to_string(Wrong) + "        It's Play Mode : Please select any icon from the tool bar");
				pOut->ClearDrawArea();
				pManager->ShowAllFigures();
				return;
			}

		}

		pOut->PrintMessage("Correct Ans = " + to_string(Correct) + "                                                                          " 
			+ "Wrong Ans = " + to_string(Wrong) +
			"                                                                 click any where to continue ...");

		if (Wrong == 0 && Count == 0) {
			string Image = "images\\MenuItems\\Congratulation.jpg";
			pOut->DrawImage(Image);
		}

		pIn->GetUserAction();
		pOut->ClearDrawArea();
		pManager->ShowAllFigures();
		pOut->PrintMessage("It's Play Mode : Please select any icon from the tool bar");
	}

	else 
	{
		pOut->PrintMessage("Empty Drawing Area , You can back to \"Draw Mode\" by selecting Draw Icon ");
		return;
	}
}