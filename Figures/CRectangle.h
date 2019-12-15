#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	
	int CalcLen() const //Utility Function that Calculate The length of Rectangle
	{
		return abs(Corner2.y - Corner1.y);
	}
	
	int CalcWid() const //Utility Function that Calculate The width of Rectangle
	{
		return abs(Corner2.x - Corner1.x);
	}
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	CRectangle(); //Default Constractor
	virtual void Draw(Output* pOut) const;
	virtual bool Get(int x,int y) const;
	virtual void printinfo(Output* pOut) const;
	virtual void Resize(double Scale);
	virtual void Rotate(int Degree);
	virtual void Save(ofstream & file);
	virtual void Load(ifstream & file);
	virtual void Paste(Point p, Point Mid);
	virtual CFigure* Copy();
	virtual string GetF()const;
	virtual Point GetMid();
	virtual bool OutsideInterface();

};

#endif