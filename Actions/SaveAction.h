#ifndef SAVE_ACTION_H
#define SAVE_ACTION_H

#include <fstream>
#include "Action.h"
#include <string>

using namespace std;

class SaveAction : public Action
{
	ofstream file;
	string file_name;

public:

	SaveAction(ApplicationManager *pApp);

	virtual bool ReadActionParameters();

	virtual void Execute();
};



#endif