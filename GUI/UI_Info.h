#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};
enum DrawBackGroundItem
{
	ITM_BACK,
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_BACKw,
	ITM_SELECT,
	ITM_LINE,
	ITM_RECT,		 //Recangle item in menu
	ITM_CIRC,        //Circle item in menu
	ITM_Tri,

	ITM_DCol, ITM_FCol,
	ITM_RED, ITM_BLUE, ITM_GREEN, ITM_WHITE, ITM_BLACK, ITM_YELLOW, ITM_ORANGE, ITM_PINK,
	ITM_DARKRED, ITM_LIGHTBLUE,

	ITM_COPY, ITM_CUT, ITM_PASTE, ITM_DELETE, ITM_SAVE, ITM_LOAD, ITM_RESIZE,
	ITM_FOUR, ITM_QUARTER, ITM_TWO, ITM_HALF,
	ITM_ROTATE, ITM_90, ITM_180, ITM_270,
	ITM_FORWARD, ITM_BACKWARD, ITM_PLAY,
	
	ITM_EXIT,  //Exit item


			   //TODO: Add more items names here



	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	//TODO: Add more items names here

	ITM_BACKW,
	ITM_FIGURE,
	ITM_COLOR,
	ITM_FIGCOLOR,
	ITM_BACKDRAW,
	ITM_PEXIT,


	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes
	bool DEFFILL;           // the Default Fill or Not

							/// Add more members if needed

}UI;	//create a global object UI

#endif