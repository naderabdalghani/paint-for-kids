#ifndef PST_ACTION_H
#define PST_ACTION_H

#include "Action.h"
#include "..\Figures\CFigure.h"

//Paste Figure Class Action
class PasteAction : public Action
{
	CFigure * F;
	Point P;

public:

	PasteAction(ApplicationManager * pApp);

	bool ReadActionParameters();

	void Execute();

	Point FiguresMid(CFigure ** C,int CCount);

};

#endif

