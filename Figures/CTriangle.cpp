#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}

CTriangle::CTriangle()
{
	Corner1.x = 0;
	Corner2.x = 0;
	Corner3.x = 0;
	Corner1.y = 0;
	Corner2.y = 0;
	Corner3.y = 0;
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTria to draw a Triangle on the screen	
	pOut->DrawTri(Corner1, Corner2, Corner3,FigGfxInfo, Selected);
}

bool CTriangle::Get(int x, int y) const
{
	double denominator = ((Corner2.y - Corner3.y)*(Corner1.x - Corner3.x) + (Corner3.x - Corner2.x)*(Corner1.y - Corner3.y));
	double a = ((Corner2.y - Corner3.y)*(x - Corner3.x) + (Corner3.x - Corner2.x)*(y - Corner3.y)) / denominator;
	double b = ((Corner3.y - Corner1.y)*(x - Corner3.x) + (Corner1.x - Corner3.x)*(y - Corner3.y)) / denominator;
	double c = 1 - a - b;
	return (0 <= a && a <= 1 && 0 <= b && b <= 1 && 0 <= c && c <= 1);
}

void CTriangle::printinfo(Output* pOut) const
{
	string FillColor;
	if (FigGfxInfo.isFilled)
		FillColor = "Filling Color \"" + FigGfxInfo.FillClr.Color2String() + "\"";
	else
		FillColor = "Non_Filled";

	pOut->PrintMessage("Triangle   " + to_string(ID) + "    Corner1 (" + to_string(Corner1.x) + " , " + to_string(Corner1.y)
		+ ")   Corner2 (" + to_string(Corner2.x) + " , " + to_string(Corner2.y) + ")   Corner3 (" + to_string(Corner3.x) + " , " +
		to_string(Corner3.y) + ")"
		+ "    Drawing Color \"" + FigGfxInfo.DrawClr.Color2String() + "\"    " + FillColor);
}

void CTriangle::Resize(double Scale) 
{
	Corner2.x = ((Corner2.x - Corner1.x) * Scale) + Corner1.x;
	Corner2.y = ((Corner2.y - Corner1.y) * Scale) + Corner1.y;
	Corner3.x = ((Corner3.x - Corner1.x) * Scale) + Corner1.x;
	Corner3.y = ((Corner3.y - Corner1.y) * Scale) + Corner1.y;
}

void CTriangle::Rotate(int Angle)
{
	int Midx = (Corner1.x + Corner2.x + Corner3.x) / 3;
	int Midy = (Corner1.y + Corner2.y + Corner3.y) / 3;
	Corner1.RotatePoint(Angle, Midx, Midy);
	Corner2.RotatePoint(Angle, Midx, Midy);
	Corner3.RotatePoint(Angle, Midx, Midy);
}

void CTriangle::Save(ofstream & file)
{
	file << "TRIANGLE  " << GetID() << "  " << this->Corner1.x << "  " << this->Corner1.y << "  " << this->Corner2.x << "  " << this->Corner2.y << "  " << this->Corner3.x << "  " << this->Corner3.y << "  ";
	file << FigGfxInfo.DrawClr.Color2String() << "  ";
	if (FigGfxInfo.isFilled != false)
		file << FigGfxInfo.FillClr.Color2String() << endl;
	else
		file << "False" << endl;
}


void CTriangle::Load(ifstream & file)
{
	int n; file >> n; SetID(n);
	int x1, x2, x3, y1, y2, y3;
	file >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	Corner1.x = x1;  Corner1.y = y1;
	Corner2.x = x2;  Corner2.y = y2;
	Corner3.x = x3;  Corner3.y = y3;
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

CFigure* CTriangle::Copy() {
	CTriangle * T = new CTriangle(*this);
	T->SetSelected(false);
	return T;
}

void CTriangle::Paste(Point p, Point Mid) {
	Corner1.x = p.x - (Mid.x - Corner1.x);
	Corner1.y = p.y - (Mid.y - Corner1.y);
	Corner2.x = p.x - (Mid.x - Corner2.x);
	Corner2.y = p.y - (Mid.y - Corner2.y);
	Corner3.x = p.x - (Mid.x - Corner3.x);
	Corner3.y = p.y - (Mid.y - Corner3.y);

}

string CTriangle::GetF()const
{
	return "Triangles";
}

Point CTriangle::GetMid()
{
	Point P;
	P.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	P.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	return P;
}

bool CTriangle::OutsideInterface()
{
	return !((Corner1.x < UI.width || Corner2.x < UI.width || Corner3.x < UI.width)
		&& (Corner1.x > 0 || Corner2.x > 0 || Corner3.x > 0)
		&& (Corner1.y < (UI.height - UI.StatusBarHeight) || Corner2.y < (UI.height - UI.StatusBarHeight) || Corner3.y < (UI.height - UI.StatusBarHeight))
		&& (Corner1.y > UI.ToolBarHeight || Corner2.y > UI.ToolBarHeight || Corner3.y > UI.ToolBarHeight));
}