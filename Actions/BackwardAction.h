#ifndef BACW_ACTION_H
#define BACW_ACTION_H

#include "Action.h"

//Backward Figure Action class
class BackwardAction : public Action
{

public:
	BackwardAction(ApplicationManager *pApp);

	virtual bool ReadActionParameters();

	//Backward Selected Figure
	virtual void Execute();

};

#endif

