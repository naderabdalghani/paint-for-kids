#ifndef FORW_ACTION_H
#define FORW_ACTION_H

#include "Action.h"

//Forward Figure Action class
class ForwardAction : public Action
{

public:
	ForwardAction(ApplicationManager *pApp);

	virtual bool ReadActionParameters();

	//Forward Selected Figure
	virtual void Execute();

};

#endif

