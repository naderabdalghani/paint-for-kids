#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		                   //Actual number of figures
	CFigure* FigList[MaxFigCount];	       //List of all figures (Array of pointers)
	
	int SFigCount;                         //Actual number of Selected figures
	CFigure** SFigList;                    //Array of Pointers to the selected figures
	
	int CFigCount;                         //Actual number of figures in the Clipbord
	CFigure** CFigList;                    //Array of Pointers to the copied/cut figures
	
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	CFigure* GetFigure(int x, int y) const;  //Search for a figure given a point :Ahmed
	void SelectFig(CFigure * pFig);           //Adds a New Figure To THe Selected List :Ahmed
	void UnSelectedFig(CFigure * pFig);       //Delete Figure From The Selected List   :Ahmed
	void AddClipboardFig(CFigure * pFig);     //Adds Figure To The Clipboard :Nader
	void AddFigure(CFigure* pFig);            //Adds a new figure to the FigList 
    void DeleteFigure(CFigure *Fig);          //Delete Figure From the Figlist :Ahmed
	void ForwardFigure(CFigure *Fig);         //Forward a Figure at The FigList	:Ahmed										
	void BackwardFigure(CFigure *Fig);        //Bacward a Figure at The FigList :Ahmed
	void ClearFigList();                      //Delete All Figures :Nader
	void ClearClipbord();                     //Clear All Figures in The Clipbord :Nader
	void ClearSFigList();                     //Make All Figures UnSelected :Ahmed
	void ShowAllFigures();                    //Func to make all Figures Visible :Muhanad
	CFigure** GetSelectedFig() const;         //Return pointer to the Selected Figures : Ahmed
	CFigure** GetClipBoardFig() const;        //Return pointer to the Copied/cut Figures : Nader
	int GetSFigCount();                       //Return The Actual number of Selectd Figure :Ahmed
	int GetCFigCount();                       //Return The Actual number of Figures in the Clipboard :Nader
	void SaveAll(ofstream & File)const;       //Save All Figures To The File :Sherif
	string RandFig(int &)const;               //to make user choose random figure :Muhanad
	color RandClr(int &)const;                //to make user choose random color :Muhanad
	string RandFigClr(int&, color&)const;     //to select random figure and color:Muhanad
	
	
		
	// -- Interface Management Functions
	Input* GetInput() const;                 //Return pointer to the input
	Output* GetOutput() const;               //Return pointer to the output
	void UpdateInterface() const;	         //Redraws all the drawing window	
	
};

#endif