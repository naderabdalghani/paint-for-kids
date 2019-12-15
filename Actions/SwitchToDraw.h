#ifndef Draw_ACTION_H
#define Draw_ACTION_H

#include "Action.h"

//Switch to Draw mode
class SwitchToDraw : public Action
{
public:
	SwitchToDraw(ApplicationManager *pApp);

	//Reads Action parameters
	virtual bool ReadActionParameters();

	//Execute Draw mode toolbar
	virtual void Execute();
};

#endif