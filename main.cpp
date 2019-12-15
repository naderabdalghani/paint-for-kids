#include "ApplicationManager.h"
#include <time.h>



int main()
{
	srand(time(NULL));

	ActionType ActType;

	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	AppManager.GetOutput()->PrintMessage("Welcome to \"Paint For Kids\"");

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the interface
		AppManager.UpdateInterface();	

	}while(ActType != EXIT);
	

	
	return 0;
}

