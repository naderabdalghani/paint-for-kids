#ifndef RES_ACTION_H
#define RES_ACTION_H

#include "Action.h"

//Select Action class
class ResizeAction : public Action
{
	Point P;
	ActionType SCALE;
	double Scale;

public:
	ResizeAction(ApplicationManager *pApp);

	//Reads Scale From User
	virtual bool ReadActionParameters();

	//Resize The Figure
	virtual void Execute();

	//Converting From ActionTybe to Double
	bool GetScale(ActionType S);

};

#endif
