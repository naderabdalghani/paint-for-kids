#ifndef CTRI_H
#define CTRI_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;

public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	CTriangle(); //Default Constractor
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