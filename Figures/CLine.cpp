#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
}

CLine::CLine() {
	Point1.x = 0;
	Point1.y = 0;
	Point2.x = 0;
	Point2.y = 0;
}

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a rectangle on the screen	
	pOut->DrawLine(Point1, Point2, FigGfxInfo, Selected);
}

bool CLine::Get(int x, int y) const
{
	if ((Point2.x - Point1.x) == 0) {
		if (Point1.y > Point2.y)
			return (Point2.x == x && y > Point2.y && y < Point1.y);
		if (Point1.y < Point2.y)
			return ((Point2.x >= x-1 && Point2.x <= x+1) && y>Point1.y && y < Point2.y);
	}

	if ((Point2.y - Point1.y) == 0) {
		if (Point1.x > Point2.x)
			return (Point2.y == y && x > Point2.x && x < Point1.x);
		if (Point1.x < Point2.x)
			return ((Point2.y >= y-1 && Point2.y <= y+1) && x>Point1.x && x < Point2.x);
	}

	double VectorAPx = x - Point1.x;
	double VectorAPy = y - Point1.y;
	double VectorABx = Point2.x - Point1.x;
	double VectorABy = Point2.y - Point1.y;
	double MagAB2 = VectorABx*VectorABx + VectorABy*VectorABy;
	double ABdotAP = VectorABx*VectorAPx + VectorABy*VectorAPy;
	double t = ABdotAP / MagAB2;

	Point Closest;
	if (t < 0)
	{
		Closest.x = Point1.x;
		Closest.y = Point1.y;
	}
	else if (t > 1)
	{
		Closest.x = Point2.x;
		Closest.y = Point2.y;
	}
	else
	{
		Closest.x = Point1.x + VectorABx*t;
		Closest.y = Point1.y + VectorABy*t;
	}
	
	//The Distance Between The Closest Point To The Give Point 
	int Distance = sqrt(pow((Closest.x - x), 2) + pow((y - y), 2));
	
	if (Point1.x > Point2.x && Point1.y > Point2.y)
		return(Distance < 3 && x <Point1.x && x >Point2.x && y <Point1.y && y>Point2.y);

	if (Point1.x < Point2.x && Point1.y > Point2.y)
		return(Distance < 3 && x >Point1.x && x <Point2.x && y <Point1.y && y>Point2.y);

	if (Point1.x > Point2.x && Point1.y < Point2.y)
		return(Distance < 3 && x <Point1.x && x >Point2.x && y >Point1.y && y<Point2.y);

	if (Point1.x < Point2.x && Point1.y < Point2.y)
		return(Distance < 3 && x >Point1.x && x <Point2.x && y >Point1.y && y<Point2.y);


}

void CLine::printinfo(Output* pOut) const
{

	pOut->PrintMessage("Line   " + to_string(ID) + "    Point1 (" + to_string(Point1.x) + " , " + to_string(Point1.y)
		+ ")   Point2 (" +to_string(Point2.x) + " , " + to_string(Point2.y)+")    Length= " + to_string(Calclen())
		+ "    Drawing Color \"" + FigGfxInfo.DrawClr.Color2String()+ "\"");
}

void CLine::Resize(double Scale) {
	
	int Midx = (Point1.x + Point2.x) / 2;
	int Midy = (Point1.y + Point2.y) / 2;
	
	if ((Point1.x >= Point2.x && Point1.y <= Point2.y)||(Point1.x <= Point2.x && Point1.y >= Point2.y)) 
	{
		Point1.x = Midx + Scale*abs(Point1.x - Midx);
		Point1.y = Midy - Scale*abs(Midy - Point1.y);
		Point2.x = Midx - Scale*abs(Midx - Point2.x);
		Point2.y = Midy + Scale*abs(Point2.y - Midy);
	}
	else if ((Point1.x >= Point2.x && Point1.y >= Point2.y)|| (Point1.x <= Point2.x && Point1.y <= Point2.y)) {
		Point1.x = Midx + Scale*abs(Point1.x - Midx);
		Point1.y = Midy + Scale*abs(Point1.y - Midy);
		Point2.x = Midx - Scale*abs(Midx - Point2.x);
		Point2.y = Midy - Scale*abs(Midy - Point2.y);
	}
}

void CLine::Rotate(int Angle)
{
	int Midx = (Point1.x + Point2.x) / 2;
	int Midy = (Point1.y + Point2.y) / 2;
	Point1.RotatePoint(Angle, Midx, Midy);
	Point2.RotatePoint(Angle, Midx, Midy);
}

void CLine::Save(ofstream & file)
{
	file << "LINE  " << GetID() << "  " << this->Point1.x << "  " << this->Point1.y << "  " << this->Point2.x << "  " << this->Point2.y << "  ";
	file << FigGfxInfo.DrawClr.Color2String() << endl;
}

void CLine::Load(ifstream & file)
{
	int n; file >> n; SetID(n);
	int x1, x2, y1, y2;
	file >> x1 >> y1 >> x2 >> y2;
	Point1.x = x1;  Point1.y = y1;
	Point2.x = x2;  Point2.y = y2;
	string DrawClr; file >> DrawClr;
	FigGfxInfo.DrawClr.String2Color(DrawClr);
}

CFigure* CLine::Copy() {
	CLine * L = new CLine(*this);
	L->SetSelected(false);
	return L;
}

void CLine::Paste(Point p, Point Mid) {
	Point1.x = p.x - (Mid.x - Point1.x);
	Point1.y = p.y - (Mid.y - Point1.y);
	Point2.x = p.x - (Mid.x - Point2.x);
	Point2.y = p.y - (Mid.y - Point2.y);
}

string CLine::GetF()const
{
	return "Lines";
}

Point CLine::GetMid()
{
	Point P;
	P.x = (Point1.x + Point2.x) / 2;
	P.y = (Point1.y + Point2.y) / 2;
	return P;
}

bool CLine::OutsideInterface()
{
	return !((Point1.x < UI.width || Point2.x < UI.width )
		&& (Point1.x > 0 || Point2.x > 0 )
		&& (Point1.y < (UI.height - UI.StatusBarHeight) || Point2.y < (UI.height - UI.StatusBarHeight))
		&& (Point1.y > UI.ToolBarHeight || Point2.x > UI.ToolBarHeight ));
}