#ifndef DEL_ACTION_H
#define DEL_ACTION_H

#include "Action.h"

//Delete Figure Action class
class DeleteAction : public Action
{

public:
	DeleteAction(ApplicationManager *pApp);

	virtual bool ReadActionParameters();

	//Deleted Selected Figure
	virtual void Execute();

};

#endif

