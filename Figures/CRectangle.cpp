#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	
CRectangle::CRectangle() {
	Corner1.x = 0;
	Corner1.y = 0;
	Corner2.x = 0;
	Corner2.y = 0;
}


void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::Get(int x, int y) const
{
	if (((x >= Corner1.x && x <= Corner2.x) || (x <= Corner1.x && x >= Corner2.x)) &&
		((y >= Corner1.y && y <= Corner2.y) || (y <= Corner1.y && y >= Corner2.y)))
		return true;
	return false;
}

void CRectangle::printinfo(Output* pOut) const
{
	string FillColor;
	if (FigGfxInfo.isFilled)
		FillColor = "Filling Color \"" + FigGfxInfo.FillClr.Color2String() + "\"";
	else
		FillColor = "Non_Filled";

	pOut->PrintMessage("Rectangle   " + to_string(ID) + "    Corner1 (" + to_string(Corner1.x) + " , " + to_string(Corner1.y)
		+ ")   Corner2 (" + to_string(Corner2.x) + " , " + to_string(Corner2.y) +  ")    Length= " + to_string(CalcLen()) +
		"    Width= "+ to_string(CalcWid())
		+ "    Drawing Color \"" + FigGfxInfo.DrawClr.Color2String()
		+ "\"    " + FillColor);
}

void CRectangle::Resize(double Scale)
{

	int Midx = (Corner1.x + Corner2.x) / 2;
	int Midy = (Corner1.y + Corner2.y) / 2;
	int oldLen = CalcLen();
	int oldWid = CalcWid();

	if ((Corner1.x > Corner2.x && Corner1.y < Corner2.y) || (Corner1.x <= Corner2.x && Corner1.y >= Corner2.y))
	{
		Corner1.x = Midx + (oldWid*sqrt(Scale) / 2);
		Corner1.y = Midy - (oldLen*sqrt(Scale) / 2);
		Corner2.x = Midx - (oldWid*sqrt(Scale) / 2);
		Corner2.y = Midy + (oldLen*sqrt(Scale) / 2);
	}
	else if ((Corner1.x > Corner2.x && Corner1.y > Corner2.y) || (Corner1.x <= Corner2.x && Corner1.y <= Corner2.y)) {
		Corner1.x = Midx + (oldWid*sqrt(Scale) / 2);
		Corner1.y = Midy + (oldLen*sqrt(Scale) / 2);
		Corner2.x = Midx - (oldWid*sqrt(Scale) / 2);
		Corner2.y = Midy - (oldLen*sqrt(Scale) / 2);
	}
}

void CRectangle::Rotate(int Angle)
{
	int Midx = (Corner1.x + Corner2.x) / 2;
	int Midy = (Corner1.y + Corner2.y) / 2;
	Corner1.RotatePoint(Angle, Midx, Midy);
	Corner2.RotatePoint(Angle, Midx, Midy);
}

void CRectangle::Save(ofstream & file)
{
	file << "RECTANGLE  " << GetID() << "  " << this->Corner1.x << "  " << this->Corner1.y << "  " << this->Corner2.x << "  " << this->Corner2.y << "  ";
	file << FigGfxInfo.DrawClr.Color2String() << "  ";
	if (FigGfxInfo.isFilled != false)
		file << FigGfxInfo.FillClr.Color2String() << endl;
	else
		file << "False" << endl;;
}

void CRectangle::Load(ifstream & file)
{
	int n; file >> n; SetID(n);
	int x1, x2, y1, y2;
	file >> x1 >> y1 >> x2 >> y2;
	Corner1.x = x1;  Corner1.y = y1;
	Corner2.x = x2;  Corner2.y = y2;
	string DrawClr; file >> DrawClr;
	FigGfxInfo.DrawClr.String2Color(DrawClr);
	string FillClr; file >> FillClr;
	if (FillClr != "False") {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr.String2Color(FillClr);
	}
	else
		FigGfxInfo.isFilled = false;
}

CFigure* CRectangle::Copy() {
	CRectangle * R = new CRectangle(*this);
	R->SetSelected(false);
	return R;
}

void CRectangle::Paste(Point p, Point Mid) {
	Corner1.x = p.x - (Mid.x - Corner1.x);
	Corner1.y = p.y - (Mid.y - Corner1.y);
	Corner2.x = p.x - (Mid.x - Corner2.x);
	Corner2.y = p.y - (Mid.y - Corner2.y);
}

string CRectangle::GetF()const
{
	return "Rectangles";
}

Point CRectangle::GetMid()
{
	Point P;
	P.x = (Corner1.x + Corner2.x) / 2;
	P.y = (Corner1.y + Corner2.y) / 2;
	return P;
}

bool CRectangle::OutsideInterface()
{
	return !((Corner1.x < UI.width || Corner2.x < UI.width)
		&& (Corner1.x > 0 || Corner2.x > 0)
		&& (Corner1.y < (UI.height - UI.StatusBarHeight) || Corner2.y < (UI.height - UI.StatusBarHeight))
		&& (Corner1.y > UI.ToolBarHeight || Corner2.x > UI.ToolBarHeight));
}