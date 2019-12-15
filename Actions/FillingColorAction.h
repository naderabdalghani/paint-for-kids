#ifndef FILL_ACTION_H
#define FILL_ACTION_H

#include "Action.h"

//Filling Color Action class
class FillingColorAction : public Action
{
	ActionType FCOLOR;
	color FColor;

public:
	FillingColorAction(ApplicationManager *pApp);

	//Reads Color parameters
	virtual bool ReadActionParameters();

	//Change Filling Color
	virtual void Execute();

	//Converting From ActionTybe To Color
	bool GetColor(ActionType C);
};

#endif
