#ifndef COLOR_ACTION_H
#define COLOR_ACTION_H

#include "Action.h"

//Color type
class PlayWithColor : public Action
{
	Point P;
	int Correct;
	int Wrong;
	color PlayingColor;

public:
	PlayWithColor(ApplicationManager *pApp);

	//Reads Figure parameters
	virtual bool ReadActionParameters();

	//pick and hide the figure
	virtual void Execute();
};

#endif
