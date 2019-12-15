#include "CCircle.h"
#include <cmath>

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Circumference = P2;
}

CCircle::CCircle() {
	Center.x = 0;
	Center.y = 0;
	Circumference.x = 0;
	Circumference.y = 0;
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a Circle on the screen	
	pOut->DrawCirc(Center, Circumference, FigGfxInfo, Selected);
}

bool CCircle::Get(int x,int y) const
{
	int radius = CalcRadius();
	int pDistance = sqrt(pow((Center.x - x), 2) + pow((Center.y - y), 2));
	if (pDistance <= radius)
		return true;
	return false;
}

void CCircle::printinfo(Output* pOut) const
{
	string FillColor;
	if (FigGfxInfo.isFilled)
		FillColor = "Filling Color \"" + FigGfxInfo.FillClr.Color2String() + "\"";
	else
		FillColor = "Non_Filled";

	pOut->PrintMessage("Circle   "+ to_string(ID) + "    Center ("  + to_string(Center.x) + " , " + to_string(Center.y) 
		               + ")   Radius= " + to_string(CalcRadius())
		               +"    Drawing Color \"" + FigGfxInfo.DrawClr.Color2String()
		               +"\"    " + FillColor);
}

void CCircle::Resize(double Scale) {
	Circumference.x = Center.x + Scale*abs(Circumference.x-Center.x);
	Circumference.y = Center.y + Scale*abs(Circumference.y - Center.y);
}

void CCircle::Rotate(int Degree)
{
}

void CCircle::Save(ofstream & file)
{
	file << "CIRCLE  " << GetID() << "  " << this->Center.x << "  " << this->Center.y << "  " << CalcRadius()<< "  ";
	file << FigGfxInfo.DrawClr.Color2String() << "  ";
	if (FigGfxInfo.isFilled != false)
		file << FigGfxInfo.FillClr.Color2String() << endl;
	else
		file << "False" << endl;
}

void CCircle::Load(ifstream & file)
{
	int n; file >> n; SetID(n);
	int x, y, r;
	file >> x >> y >> r;
	Center.x = x;   Center.y = y;
	Circumference.x = x + r; Circumference.y = y;
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

CFigure* CCircle::Copy() {
	CCircle * C = new CCircle(*this);
	C->SetSelected(false);
	return C;
}

void CCircle::Paste(Point p, Point Mid) {
	Center.x = p.x - (Mid.x - Center.x);
	Center.y = p.y - (Mid.y - Center.y);
	Circumference.x = p.x - (Mid.x - Circumference.x);
	Circumference.y = p.y - (Mid.y - Circumference.y);
}

string CCircle::GetF()const
{
	return "Circles";
}

Point CCircle::GetMid()
{
	return Circumference;
}

bool CCircle::OutsideInterface()
{
	return !((Center.x - CalcRadius() < UI.width)
		&& (Center.x + CalcRadius() > 0)
		&& (Center.y - CalcRadius() < (UI.height - UI.StatusBarHeight))
		&& (Center.y + CalcRadius() > UI.ToolBarHeight));	
}