#ifndef TYP_Col_ACTION_H
#define TYP_Col_ACTION_H

#include "Action.h"

//Color & type Class Action
class PlayWithTypeColor : public Action
{
	Point P;
	int Correct;
	int Wrong;
	color PlayingColor;
	string Fig;

public:
	PlayWithTypeColor(ApplicationManager *pApp);

	//Reads Figure parameters
	virtual bool ReadActionParameters();

	//pick and hide the figure
	virtual void Execute();
};

#endif
