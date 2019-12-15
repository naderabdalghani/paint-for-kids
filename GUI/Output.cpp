#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1385;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 56;
	UI.MenuItemWidth = 63;

	UI.DrawColor = BLACK;	                //Drawing color
	UI.FillColor = WHITE;	                //Filling color
	UI.MsgColor = BLACK;		            //Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	        //This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = GRAY;
	UI.PenWidth = 2;	                    //width of the figures frames
    UI.DEFFILL = false;


						//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	string ITM_BACK = "images\\MenuItems\\Untitled-1.jpg";
	pW->DrawImage(ITM_BACK, 0, UI.ToolBarHeight, w, h - UI.ToolBarHeight - UI.StatusBarHeight);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
	pWind->SetPen(BLACK, 1);
	pWind->DrawLine(0, (UI.height - UI.StatusBarHeight), UI.width, (UI.height - UI.StatusBarHeight));
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem

	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_BACKw] = "images\\MenuItems\\Play_Mode.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Select.jpg";
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\Line.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Rect.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Circle.jpg";
	MenuItemImages[ITM_Tri] = "images\\MenuItems\\Triangle.jpg";
	MenuItemImages[ITM_DCol] = "images\\MenuItems\\Drawing_color.jpg";
	MenuItemImages[ITM_FCol] = "images\\MenuItems\\Filling_color.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Red.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Blue.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Green.jpg";
	MenuItemImages[ITM_WHITE] = "images\\MenuItems\\white.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\Black.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\Yellow.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\Orange.jpg";
	MenuItemImages[ITM_PINK] = "images\\MenuItems\\Pink.jpg";
	MenuItemImages[ITM_DARKRED] = "images\\MenuItems\\Nbiti.jpg";
	MenuItemImages[ITM_LIGHTBLUE] = "images\\MenuItems\\Light_BLue.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\Copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Paste.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Delete.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Load.jpg";
	MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\Resize.jpg";
	MenuItemImages[ITM_FOUR] = "images\\MenuItems\\Four.jpg";
	MenuItemImages[ITM_QUARTER] = "images\\MenuItems\\Quarter.jpg";
	MenuItemImages[ITM_TWO] = "images\\MenuItems\\Two.jpg";
	MenuItemImages[ITM_HALF] = "images\\MenuItems\\Half.jpg";
	MenuItemImages[ITM_ROTATE] = "images\\MenuItems\\Rotate.jpg";
	MenuItemImages[ITM_90] = "images\\MenuItems\\90.jpg";
	MenuItemImages[ITM_180] = "images\\MenuItems\\180.jpg";
	MenuItemImages[ITM_270] = "images\\MenuItems\\270.jpg";
	MenuItemImages[ITM_FORWARD] = "images\\MenuItems\\Forward.jpg";
	MenuItemImages[ITM_BACKWARD] = "images\\MenuItems\\Backward.jpg";
	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\Play.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Exit.jpg";


	//TODO: Prepare images for each menu item and add it to the list
	pWind->DrawImage(MenuItemImages[0], 0, 0, UI.width, UI.ToolBarHeight);

	int j = 0;
	for (int i = 1;i < 6;i++)
		pWind->DrawImage(MenuItemImages[i], (j++)*UI.MenuItemWidth, 2, UI.MenuItemWidth, 50);

	pWind->DrawImage(MenuItemImages[6], 320, 4, 107, 21);
	pWind->DrawImage(MenuItemImages[7], 320, 30, 107, 21);

	j = 0;
	for (int i = 8; i < 18; i += 2) {
		pWind->DrawImage(MenuItemImages[i], 435 + (j * 26), 5, 23, 21);
		pWind->DrawImage(MenuItemImages[i + 1], 435 + (j++ * 26), 29, 23, 21);
	}
	j = 0;
	for (int i = 18;i < 25;i++)
		pWind->DrawImage(MenuItemImages[i], 560 + (j++*UI.MenuItemWidth), 2, UI.MenuItemWidth, 50);

	j = 0;

	for (int i = 25; i < 29; i += 2) {
		pWind->DrawImage(MenuItemImages[i], 1001 + (j * 25), 3, 25, 25);
		pWind->DrawImage(MenuItemImages[i + 1], 1001 + (j++ * 25), 28, 25, 25);
	}

	pWind->DrawImage(MenuItemImages[29], 1051, 2, UI.MenuItemWidth, 50);
	
	j = 0;
	for (int i = 30;i < 33;i += 3) {
		pWind->DrawImage(MenuItemImages[i], 1115, 2, 35, 16);
		pWind->DrawImage(MenuItemImages[i + 1], 1115, 20, 35, 16);
		pWind->DrawImage(MenuItemImages[i + 2], 1115, 38, 35, 16);
	}

	j = 0;
	for (int i = 33;i < 35;i += 2) {
		pWind->DrawImage(MenuItemImages[i], 1153, 4, 91, 21);
		pWind->DrawImage(MenuItemImages[i + 1], 1157, 30, 91, 21);
	}

	pWind->DrawImage(MenuItemImages[35], 1250, 2, UI.MenuItemWidth, 50);
	pWind->DrawImage(MenuItemImages[36], 1315, 2, UI.MenuItemWidth, 50);


	//Draw menu item one image at a time
	//for(int i=0; i<DRAW_ITM_COUNT; i++)
	//pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 1);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_BACKW] = "images\\MenuItems\\Play_Mode.jpg";
	MenuItemImages[ITM_FIGURE] = "images\\MenuItems\\Fig_Type.jpg";
	MenuItemImages[ITM_COLOR] = "images\\MenuItems\\Fill_Color.jpg";
	MenuItemImages[ITM_FIGCOLOR] = "images\\MenuItems\\Fig_Color.jpg";
	MenuItemImages[ITM_BACKDRAW] = "images\\MenuItems\\Draw.jpg";
	MenuItemImages[ITM_PEXIT] = "images\\MenuItems\\Exit.jpg";


	pWind->DrawImage(MenuItemImages[0], 0, 0, UI.width, UI.ToolBarHeight);
	pWind->DrawImage(MenuItemImages[1], 2, 2, 89, 54);
	pWind->DrawImage(MenuItemImages[2], 92, 2, 89, 54);
	pWind->DrawImage(MenuItemImages[3], 181, 2, 103, 54);
	pWind->DrawImage(MenuItemImages[4], 1260, 2, UI.MenuItemWidth, 50);
	pWind->DrawImage(MenuItemImages[5], 1322, 5, UI.MenuItemWidth, 50);

	///TODO: write code to create Play mode menu


	pWind->SetPen(BLACK, 1);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);


}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetBrush(UI.BkGrndColor);
	pWind->SetPen(UI.BkGrndColor, 1);
	string ITM_BACK = "images\\MenuItems\\Untitled-1.jpg";
	pWind->DrawImage(ITM_BACK, 0, UI.ToolBarHeight + 1, UI.width, UI.height - UI.ToolBarHeight - UI.StatusBarHeight);
	if (UI.InterfaceMode == MODE_DRAW)
		CreateDrawToolBar();
	else
		CreatePlayToolBar();

}
//////////////////////////////////////////////////////////////////////////////////////////


void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(25, BOLD, BY_NAME, "Aryianna");
	pWind->DrawString(10, (UI.height - (int)(UI.StatusBarHeight) + (UI.StatusBarHeight / 14)), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color& Output::getCrntDrawColor() const	//get current drwawing color
{
	return UI.DrawColor;
}

void Output::SetCrntDrawColor(color C)	//set current drwawing color
{
	UI.DrawColor = C;
}

void Output::DrawImage(string Image) const
{
	pWind->DrawImage(Image, 0, UI.ToolBarHeight + 1, UI.width, UI.height - UI.ToolBarHeight - UI.StatusBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////

color& Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}

void Output::SetCrntFillColor(color C) 	//set current filling color
{
	
	UI.FillColor = C;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}


void Output::SetDefFILL(bool Default) {
	UI.DEFFILL = Default;
}

bool  Output::GetDefFILL() {
	return UI.DEFFILL;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, FRAME);

}

void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}

void Output::DrawCirc(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int Radius = 0.0;
	Radius = sqrt((pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2)));
	pWind->DrawCircle(P1.x, P1.y, Radius, style);

}




//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

