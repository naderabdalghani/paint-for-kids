#ifndef LOAD_ACTION_H
#define LOAD_ACTION_H

#include <fstream>
#include "Action.h"
#include "..\Figures\CFigure.h"
#include <string>
#include <iostream>

using namespace std;

class LoadAction : public Action
{
	ifstream File;
	string FileName;
	CFigure *LFig;

public:

	LoadAction(ApplicationManager *pApp);

	virtual bool ReadActionParameters();

	virtual void Execute();

};

#endif