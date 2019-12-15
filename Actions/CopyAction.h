#ifndef CPY_ACTION_H
#define CPY_ACTION_H

#include "Action.h"

//Copy Figure Action Class
class CopyAction : public Action	
{
public:

	CopyAction(ApplicationManager * pApp);

	bool ReadActionParameters();

	void Execute();

};


#endif

