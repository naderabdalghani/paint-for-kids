#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <fstream>

//Base class for all figures
class CFigure
{
protected:
	int ID;		             //Each figure has an ID
	bool LastSelected;       //true if The Figure is The last selected Figure
	bool Selected;	         //true if the figure is selected.
	bool Hidden;             //true if the figure is Picked in the play mode
	GfxInfo FigGfxInfo;	     //Figure graphis info
	
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure::CFigure();                                  //Default Constractor

	void SetSelected(bool s);	                       //select/unselect the figure
	bool IsSelected() const;	                       //check whether fig is selected
	void SetLastSelected(bool s);	                   //Make The Figure The Last Selected Figure
	bool IsLastSelected() const;	                   //check whether fig is Last selected Figure
	void SetID(int id);
	int  GetID();
	bool IsFilled();

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual bool Get(int x,int y) const = 0;            //Check if the point inside The Figure :Ahmed 
	virtual void printinfo(Output* pOut) const = 0;  	//print all figure info on the status bar
	virtual void Resize(double Scale) = 0;              //Resize The Figure with certain Scale :Ahmed
	virtual void Rotate(int Angle) = 0;                 //Rotate The Figure with Certain Angle :Ahmed
	virtual CFigure* Copy() = 0;
	virtual void Paste(Point p,Point Mid) = 0;
	virtual Point GetMid() = 0;
	virtual bool OutsideInterface() = 0;
	

	bool IsHidden();
	void Hide(bool H);
	void ChngDrawClr(color Dclr);                 	   //changes the figure's drawing color
	void ChngFillClr(color Fclr);	                   //changes the figure's filling color
	virtual string GetF()const = 0;                      //to know what is the figure you have clicked on :Muhanad
	color GetC();                                     //to get figure color :Muhanad


	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	

	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
};

#endif