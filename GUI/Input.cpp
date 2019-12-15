#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

bool Input::InDrawingArea(int x, int y) const
{
	return (y > UI.ToolBarHeight && y < (UI.height - UI.StatusBarHeight));
}

string Input::GetSrting(Output *pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = -1;
			if (x <= 315) {
				ClickedItemOrder = (x / UI.MenuItemWidth) + 1;
			}

			else if (x >= 320 && x <= 427) {
				if (y >= 4 && y <= 25) {
					ClickedItemOrder = 6;
				}
				else if (y >= 30 && y <= 51) {
					ClickedItemOrder = 7;
				}
			}

			else if (x >= 435 && x <= 562) {
				if (y >= 5 && y <= 26) {
					ClickedItemOrder = 2 * (((x - 435) / 26)) + 8;
				}
				else if (y >= 29 && y <= 50) {
					ClickedItemOrder = 2 * (((x - 435) / 26)) + 9;
				}
			}

			else if (x >= 564 && x <= 1001) {
				ClickedItemOrder = ((x - 564) / UI.MenuItemWidth) + 18;
			}

			else if (x >= 1001 && x <= 1026) {
				if (y >= 3 && y <= 28) {
					ClickedItemOrder = 25;
				}
				else if (y >= 28 && y < 56) {
					ClickedItemOrder = 26;
				}
			}

			else if (x >= 1026 && x <= 1051) {
				if (y >= 3 && y <= 28) {
					ClickedItemOrder = 27;
				}
				else if (y >= 28 && y < 56) {
					ClickedItemOrder = 28;
				}
			}

			else if (x > 1051 && x <= 1114) {
				ClickedItemOrder = 29;
			}

			else if (x >= 1118 && x <= 1143) {
				if (y >= 2 && y <= 18) {
					ClickedItemOrder = 30;
				}
				else if (y >= 20 && y < 36) {
					ClickedItemOrder = 31;
				}
				else if (y >= 38 && y < 54) {
					ClickedItemOrder = 32;
				}
			}

			else if (x >= 1153 && x <= 1248) {
				if (y >= 4 && y <= 25) {
					ClickedItemOrder = 33;
				}
				else if (y >= 30 && y < 51) {
					ClickedItemOrder = 34;
				}
			}

			else if (x > 1255 && x <= 1318) {
				ClickedItemOrder = 35;
			}
			else if (x > 1319 && x <= 1382) {
				ClickedItemOrder = 36;
			}
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_HALF:      return HALF;
			case ITM_TWO:       return TWO;
			case ITM_FOUR:      return FOUR;
			case ITM_QUARTER:   return QUARTER;
			case ITM_SELECT:    return SELECT;
			case ITM_LINE:      return DRAW_LINE;
			case ITM_RECT:      return DRAW_RECT;
			case ITM_CIRC:      return DRAW_CIRC;
			case ITM_Tri:       return DRAW_TRI;
			case ITM_DCol:      return CHNG_DRAW_CLR;
			case ITM_FCol:      return CHNG_FILL_CLR;
			case ITM_RED:       return CRED;
			case ITM_BLUE:      return CBLUE;
			case ITM_GREEN:     return CGREEN;
			case ITM_WHITE:     return CWHITE;
			case ITM_BLACK:     return CBLACK;
			case ITM_YELLOW:    return CYELLOW;
			case ITM_ORANGE:    return CORANGE;
			case ITM_PINK:      return CPINK;
			case ITM_DARKRED:   return CDARKRED;
			case ITM_LIGHTBLUE: return CLIGHTBLUE;
			case ITM_COPY:      return COPY;
			case ITM_CUT:       return CUT;
			case ITM_PASTE:     return PASTE;
			case ITM_DELETE:    return DEL;
			case ITM_SAVE:      return SAVE;
			case ITM_LOAD:      return LOAD;
			case ITM_RESIZE:    return RESIZE;
			case ITM_ROTATE:    return ROTATE;
			case ITM_90:        return ROTATE90;
			case ITM_180:       return ROTATE180;
			case ITM_270:       return ROTATE270;
			case ITM_FORWARD:   return FORWARD;
			case ITM_BACKWARD:  return BACKWARD;
			case ITM_PLAY:      return TO_PLAY;
			case ITM_EXIT:      return EXIT;


			default:            return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		if (y >= UI.height - UI.ToolBarHeight && y < UI.height)
		{
			return STATUS;
		}
	}


	else if (UI.InterfaceMode == MODE_PLAY)      //GUI is in PLAY mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y <= UI.ToolBarHeight)
		{
			int ClickedItemOrder = -1;
			if (x >= 2 && x <= 91) {
				ClickedItemOrder = 1;
			}
			else if (x >= 92 && x <= 180) {
				ClickedItemOrder = 2;
			}
			else if (x >= 181 && x <= 284) {
				ClickedItemOrder = 3;
			}
			else if (x >= 1260 && x <= 1321) {
				ClickedItemOrder = 4;
			}
			else if (x > 1322 && x <= 1384) {
				ClickedItemOrder = 5;
			}

			switch (ClickedItemOrder)
			{
			case ITM_BACKDRAW: return TO_DRAW;
			case ITM_COLOR:return COLOR;
			case ITM_FIGURE:return FIGURE;
			case ITM_FIGCOLOR:return FIGCLR;
			case ITM_PEXIT:return EXIT;
			default: return EMPTY;
			}

		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		if (y >= UI.height - UI.ToolBarHeight && y < UI.height)
		{
			return STATUS;
		}

	}

	///TODO:
	//perform checks similar to Draw mode checks above
	//and return the correspoding action
	//just for now. This should be updated
}


/////////////////////////////////

Input::~Input()
{
}
