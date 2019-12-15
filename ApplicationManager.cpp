#include "ApplicationManager.h"
#include "Figures\CLine.h"
#include "Figures\CCircle.h"
#include "Figures\CRectangle.h"
#include "Figures\CTriangle.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\AddTriaAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\SelectAction.h"
#include "Actions\FillingColorAction.h"
#include "Actions\DrawingColorAction.h"
#include "Actions\DeleteAction.h"
#include "Actions\ResizeAction.h"
#include "Actions\ForwardAction.h"
#include "Actions\BackwardAction.h"
#include "Actions\RotateAction.h"
#include "Actions\CopyAction.h"
#include "Actions\PasteAction.h"
#include "Actions\CutAction.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"
#include "Actions\SwitchToPlay.h"
#include "Actions\SwitchToDraw.h"
#include "Actions\PlayWithType.h"
#include "Actions\PlayWithColor.h"
#include "Actions\PlayWithTypeColor.h"
#include <stdlib.h>     
#include <time.h>
#include <string>
#include <fstream>

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	SFigList = new CFigure*[MaxFigCount];         //Array of Pointers to the selected figures
	CFigList = new CFigure*[MaxFigCount];         //Array of Pointer to the figures in Clipbord
	

	CFigCount = 0;
	SFigCount = 0;
	FigCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
	{
		FigList[i] = NULL;
		CFigList[i] = NULL;
		SFigList[i] = NULL;
	}
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}

////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		
		case DRAW_CIRC:
			pAct = new AddCircAction(this);
			break;

		case DRAW_TRI:
			pAct = new AddTriaAction(this);
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;
				
		case SELECT:
			pAct = new SelectAction(this);
			break;

		case CHNG_FILL_CLR:
			pAct = new  FillingColorAction(this);
			break;

		case CHNG_DRAW_CLR:
			pAct = new  DrawingColorAction(this);
			break;

		case DEL:
			pAct = new  DeleteAction(this);
			break;

		case RESIZE:
			pAct = new  ResizeAction(this);
			break;

		case FORWARD:
			pAct = new  ForwardAction(this);
			break;

		case BACKWARD:
			pAct = new  BackwardAction(this);
			break;

		case ROTATE:
			pAct = new  RotateAction(this);
			break;

		case COPY:
			pAct = new CopyAction(this);
			break;

		case PASTE:
			pAct = new PasteAction(this);
			break;

		case CUT:
			pAct = new CutAction(this);
			break;

		case SAVE:
			pAct = new SaveAction(this);
			break;

		case LOAD:
			pAct = new LoadAction(this);
			break;

		case TO_PLAY:
			pAct = new SwitchToPlay(this);
			break;

		case TO_DRAW:
			pAct = new SwitchToDraw(this);
			break;

		case FIGURE:
			pAct = new PlayWithType(this);
			break;

		case COLOR:
			pAct = new PlayWithColor(this);
			break;

		case FIGCLR:
			pAct = new PlayWithTypeColor(this);
			break;

		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount && pFig !=NULL)
		FigList[FigCount++] = pFig;	
	if (FigCount == 1)
		pFig->SetID(1);
	else
	pFig->SetID(FigList[FigCount-2]->GetID()+1);
}

//Delete Figure From The Figure List
void ApplicationManager::DeleteFigure(CFigure *Fig) {
	bool Flag = false;
	UnSelectedFig(Fig);
	for (int i = 0; i < FigCount; i++) {
		if (Fig == FigList[i]) {
			Flag = true;
			delete FigList[i];
			FigList[i] = NULL;
			FigCount--;
		}
		if (Flag) {
			FigList[i] = FigList[i + 1];
		}
	}
	FigList[FigCount] = NULL;
}

void  ApplicationManager::SelectFig(CFigure * pFig) {

	if (SFigCount < MaxFigCount)
	{
		for (int i = 0;i < SFigCount;i++)
			if (SFigList[i]->IsLastSelected())
				SFigList[i]->SetLastSelected(false);

		SFigList[SFigCount++] = pFig;
		SFigList[SFigCount - 1]->SetSelected(true);
		SFigList[SFigCount - 1]->SetLastSelected(true);
	}

	//Arrange The Selected Figure List Base On The Figure List
	if (SFigCount > 1)
	{
		int NewFigIndex, OldIndex;
		int Flag1 = SFigCount - 1;
		int Flag2 = SFigCount - 2;
		CFigure *Temp;
		while (Flag2 >= 0)
		{
			for (int j = 0;j < FigCount;j++)
			{
				if (SFigList[Flag1] == FigList[j])
					NewFigIndex = j;
				if (SFigList[Flag2] == FigList[j])
					OldIndex = j;
			}
			if (NewFigIndex < OldIndex)
			{
				Temp = SFigList[Flag2];
				SFigList[Flag2] = SFigList[Flag1];
				SFigList[Flag1] = Temp;
				Flag1 = Flag2;
			}
			Flag2--;
		}
	}
}

void ApplicationManager::UnSelectedFig(CFigure * pFig)
{
	bool Flag = false;

	for (int i = 0;i < SFigCount;i++)
	{
		if (SFigList[i] == pFig) {
			Flag = true;
			SFigList[i]->SetSelected(false);
			SFigList[i]->SetLastSelected(false);
			SFigList[i] = NULL;
			SFigCount--;
		}

		if (Flag)
		{
			SFigList[i] = SFigList[i + 1];
		}
	}
	SFigList[SFigCount] = NULL;

}

void ApplicationManager::AddClipboardFig(CFigure * pFig) {
	if (CFigCount < MaxFigCount)
		CFigList[CFigCount++] = pFig;
}

////////////////////////////////////////////////////////////////////////////////////

CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	for (int i = FigCount - 1; i >= 0; i--)
		if (FigList[i]->Get(x, y) && !FigList[i]->IsHidden())
			return FigList[i];
		return NULL;

	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
}

int ApplicationManager::GetSFigCount()
{
	return SFigCount;
}

int ApplicationManager::GetCFigCount()
{
	return CFigCount;
}


//Return a pointer to the Selected Figure
CFigure** ApplicationManager::GetSelectedFig() const {
	return SFigList;
}

CFigure** ApplicationManager::GetClipBoardFig() const
{
	return CFigList;
}


//==================================================================================//
//					        	Randomly Choose Figure								//
//==================================================================================//

string ApplicationManager::RandFig(int &Count)const
{
	Count = 0;
	int Rand;
	string Figure;

	if (FigCount != 0)
	{
		if (FigCount != 1)
		{
			//Randomly choose The Figure
			Rand = rand() % FigCount;
			Figure = FigList[Rand]->GetF();
			for (int i = 0;i < FigCount;i++)
			{
				if (FigList[Rand]->GetF() == FigList[i]->GetF())
				{
					Count++;
				}
			}
		}
		else
		{
			Figure = FigList[0]->GetF();
			Count = 1;
		}
		return Figure;
	}
	return "Empty";
}

color ApplicationManager::RandClr(int &Count) const
{
	Count = 0;
	int Rand;
	color Color;

	if (FigCount != 0)
	{
		//Check if There are any Figure That have a Filling Color or There Any Line
		for (int i = 0;i < FigCount;i++)
		{
			if (FigList[i]->IsFilled() || dynamic_cast<CLine*>(FigList[i]))
				break;
			else if (i == FigCount - 1)
				return Empty;
		}


		//Randomly choose The Figure
		if (FigCount != 1)
		{
			do {
				Rand = rand() % FigCount;
			} while (!FigList[Rand]->IsFilled() && !dynamic_cast<CLine*>(FigList[Rand]));

			Color = FigList[Rand]->GetC();
			for (int i = 0;i < FigCount;i++)
			{
				if (FigList[Rand]->GetC() == FigList[i]->GetC())
				{
					Count++;
				}
			}
		}
		else
		{
			Color = FigList[0]->GetC();
			Count = 1;
		}
		return Color;
	}
	return Empty;
}


string ApplicationManager::RandFigClr(int &Count, color &Color) const
{

	if (FigCount != 0)
	{
		Count = 0;
		int Rand;
		string Figure;

		//Check if There are any Figure That have a Filling Color or There Any Line
		for (int i = 0;i < FigCount;i++)
		{
			if (FigList[i]->IsFilled() || dynamic_cast<CLine*>(FigList[i]))
				break;
			else if (i == FigCount - 1)
				return "Empty";
		}

		//Randomly choose The Figure
		if (FigCount != 1)
		{
			do {
				Rand = rand() % FigCount;
			} while (!FigList[Rand]->IsFilled() && !dynamic_cast<CLine*>(FigList[Rand]));

			Color = FigList[Rand]->GetC();
			Figure = FigList[Rand]->GetF();
			for (int i = 0;i < FigCount;i++)
			{
				if (FigList[Rand]->GetC() == FigList[i]->GetC() && FigList[Rand]->GetF() == FigList[i]->GetF())
				{
					Count++;
				}
			}
		}
		else
		{
			Color = FigList[0]->GetC();
			Figure = FigList[0]->GetF();
			Count = 1;
		}
			return Figure;
	}
	return "Empty";
}

////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::SaveAll(ofstream & File) const
{
	File << FigCount << endl;
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(File);
	}
}


////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::ForwardFigure(CFigure *Fig) {
	bool Flag = false;
	CFigure *Temp = NULL;
	if (Fig != FigList[FigCount - 1])       //Check if The Figure already in Front
	{
		for (int i = 0; i < FigCount - 1; i++) {
			if (Fig == FigList[i]) {
				Flag = true;
				Temp = FigList[i];
			}
			if (Flag) {
				FigList[i] = FigList[i + 1];
			}
		}
		FigList[FigCount - 1] = Temp;
		Temp = NULL;
	}

	//Forward Fgure in the Selected FigList too
	if (Fig != SFigList[SFigCount - 1])
	{
		for (int i = 0; i < SFigCount - 1; i++) {
			if (Fig == SFigList[i]) {
				Flag = true;
				Temp = SFigList[i];
			}
			if (Flag) {
				SFigList[i] = SFigList[i + 1];
			}
		}
		SFigList[SFigCount - 1] = Temp;
		Temp = NULL;
	}
}

void ApplicationManager::BackwardFigure(CFigure *Fig) {
	bool Flag = false;
	CFigure *Temp = NULL;
	if (Fig != FigList[0])      //Check if The Figure already in Back
	{
		for (int i = FigCount - 1; i > 0; i--) {
			if (Fig == FigList[i]) {
				Flag = true;
				Temp = FigList[i];
			}
			if (Flag) {
				FigList[i] = FigList[i - 1];
			}
		}
		FigList[0] = Temp;
		Temp = NULL;
	}

	//Backward Fgure in the Selected FigList too
	if (Fig != SFigList[0])
	{
		for (int i = SFigCount - 1; i > 0; i--) {
			if (Fig == SFigList[i]) {
				Flag = true;
				Temp = SFigList[i];
			}
			if (Flag) {
				SFigList[i] = SFigList[i - 1];
			}
		}
		SFigList[0] = Temp;
		Temp = NULL;
	}
}

////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::ClearClipbord()
{
	for (int i = 0;i < CFigCount;i++)
	{
		delete CFigList[i];
		CFigList[i] = NULL;
	}
	CFigCount = 0;
}

void ApplicationManager::ClearSFigList()
{
	for (int i = 0;i < SFigCount;i++)
	{
		SFigList[i]->SetSelected(false);
		SFigList[i] = NULL;
	}

	SFigCount = 0;
}

void ApplicationManager::ClearFigList()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}

	FigCount = 0;
}

void ApplicationManager::ShowAllFigures()
{

	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->IsHidden())
			FigList[i]->Hide(false);

}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	
	for (int i = 0; i < FigCount; i++)
		if (!FigList[i]->IsHidden())
			FigList[i]->Draw(pOut);	  //Call Draw function (virtual member fn)
	
	if (UI.InterfaceMode == MODE_DRAW)
		pOut->CreateDrawToolBar();
	else
		pOut->CreatePlayToolBar();
}

////////////////////////////////////////////////////////////////////////////////////

//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	ClearFigList();

	delete pIn;
	delete pOut;

	ClearSFigList();
	delete []SFigList;
	SFigList = NULL;

	ClearClipbord();
	delete []CFigList;
	CFigList = NULL;
}
