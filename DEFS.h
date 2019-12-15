#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_CIRC,		//Draw Circle

	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR, //Change the filling color
	FIGCOLOR,

	DEL,			//Delete a figure(s)
	MOVE,			//Move a figure(s)
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application
	SELECT,
	COPY,
	PASTE,
	CUT,
	RESIZE,
	ROTATE,
	FORWARD,
	BACKWARD,
	COLOR,
	FIGURE,
	FIGCLR,

	CRED,
	CBLUE,
	CBLACK,
	CWHITE,
	CGREEN,
	CYELLOW,
	CORANGE,
	CPINK,
	CLIGHTBLUE,
	CDARKRED,


	DRAWING_AREA,	//A click on the drawing area
	STATUS,	//A click on the status bar
	EMPTY,

	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	HALF,
	QUARTER,
	TWO,
	FOUR,
	ROTATE90,
	ROTATE180,
	ROTATE270,
					///TODO: Add more action types (if needed)
};

class Point	//To be used for figures points
{
public:
	int x, y;
	void RotatePoint(int Angle, int CenterX, int CenterY) {
		int cosTheta;
		int sinTheta;
		int oldx = x;
		int oldy = y;
		if (Angle == 90) {
			cosTheta = 0;
			sinTheta = 1;
		}
		else if (Angle == 180) {
			cosTheta = -1;
			sinTheta = 0;
		}
		else if (Angle == 270) {
			cosTheta = 0;
			sinTheta = -1;
		}
		x = int(cosTheta * (oldx - CenterX) - sinTheta * (oldy - CenterY) + CenterX);
		y = int(sinTheta * (oldx - CenterX) + cosTheta * (oldy - CenterY) + CenterY);
	}
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};


#endif