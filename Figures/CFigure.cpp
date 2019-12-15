#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	LastSelected = false;
	Selected = false;
	Hidden = false;
	ID = 0;
}


CFigure::CFigure()
{
	Selected = false;
	Hidden = false; 
}

void CFigure::SetSelected(bool s)
{	
	Selected = s; 
}

bool CFigure::IsSelected() const
{	
	return Selected; 
}

void CFigure::SetLastSelected(bool s)
{
	LastSelected = s;
}

bool CFigure::IsLastSelected() const
{
	return LastSelected;
}

void CFigure::SetID(int id) {
	ID = (id > 0) ? id : 1;
}

int  CFigure::GetID() {
	return ID;
}

bool CFigure::IsHidden()
{
	return Hidden;
}

void  CFigure::Hide(bool H)
{
	Hidden = H;
}

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

bool CFigure::IsFilled()
{
	return FigGfxInfo.isFilled;
}


color CFigure::GetC()
{
	if (GetF() != "Lines")
		return FigGfxInfo.FillClr;
	else
		return FigGfxInfo.DrawClr;
}


