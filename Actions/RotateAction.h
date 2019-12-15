#ifndef ROT_ACTION_H
#define ROT_ACTION_H

#include "Action.h"

//Select Action class
class RotateAction : public Action
{
	Point P;
	ActionType ANGLE;
	int Angle;

public:
	RotateAction(ApplicationManager *pApp);

	//Reads Degree From User
	virtual bool ReadActionParameters();

	//Rotate The Figure
	virtual void Execute();

	//Converting From ActionTybe to double
	bool GetDegree(ActionType D);

};

#endif
