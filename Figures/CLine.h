#ifndef CLIN_H
#define CLIN_H

#include "CFigure.h"
#include <cmath>

class CLine : public CFigure
{
private:
	Point Point1;
	Point Point2;
	int Calclen() const //Utility Function That Calcualte The Length of The Line
	{
		int Len = sqrt(pow((Point1.x - Point2.x), 2) + pow((Point1.y - Point2.y), 2));
		return Len;
	}

public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	CLine(); //Default Constractor
	virtual void Draw(Output* pOut) const;
	virtual bool Get(int x,int y) const;
	virtual void printinfo(Output* pOut) const;
	virtual void Resize(double Scale);
	virtual void Rotate(int Angle);
	virtual void Save(ofstream & file);
	virtual void Load(ifstream & file);
	virtual void Paste(Point p, Point Mid);
	virtual CFigure* Copy();
	virtual string GetF()const;
	virtual Point GetMid();
	virtual bool OutsideInterface();

};

#endif