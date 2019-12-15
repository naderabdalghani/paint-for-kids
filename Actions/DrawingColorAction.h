#ifndef DRAW_ACTION_H
#define DRAW_ACTION_H

#include "Action.h"

//Drawing Color Action class
class DrawingColorAction : public Action
{
	ActionType DCOLOR;
	color DColor;

public:
	DrawingColorAction(ApplicationManager *pApp);

	//Reads Color parameters
	virtual bool ReadActionParameters();

	//Change Drawing Color
	virtual void Execute();

	//Converting From ActionTybe To Color
	bool GetColor(ActionType C);

};

#endif
