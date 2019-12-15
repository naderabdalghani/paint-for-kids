#ifndef SELE_ACTION_H
#define SELE_ACTION_H

#include "Action.h"

//Select Action class
class SelectAction : public Action
{
	Point P;
public:
	SelectAction(ApplicationManager *pApp);

	//Reads Figure parameters
	virtual bool ReadActionParameters();

	//Highlight The Figure
	virtual void Execute();

};

#endif
