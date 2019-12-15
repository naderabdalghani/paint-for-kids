#ifndef PLAY_ACTION_H
#define PLAY_ACTION_H

#include "Action.h"

//Switch to play mood
class SwitchToPlay : public Action
{
public:
	SwitchToPlay(ApplicationManager *pApp);

	//Reads Action parameters
	virtual bool ReadActionParameters();

	//Execute Play mode toolbar
	virtual void Execute();

};

#endif

