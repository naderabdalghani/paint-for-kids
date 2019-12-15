#ifndef CUT_ACTION_H
#define CUT_ACTION_H

#include "Action.h"

//Cut Figure Action Class
class CutAction : public Action
{
public:

	CutAction(ApplicationManager * pApp);

	bool ReadActionParameters();

	void Execute();
};

#endif