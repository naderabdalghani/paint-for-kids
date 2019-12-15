#ifndef TYPE_ACTION_H
#define TYPE_ACTION_H

#include "Action.h"

//Figure type
class PlayWithType : public Action
{
	Point P;
	int Correct;
	int Wrong;
	string Fig;

public:
	PlayWithType(ApplicationManager *pApp);

	//Reads Figure parameters
	virtual bool ReadActionParameters();

	//pick and hide the figure
	virtual void Execute();
};

#endif
