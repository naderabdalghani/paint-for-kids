#pragma once
#ifndef CCIRC_H
#define CCIRC_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point Circumference;

    int CalcRadius()  const //Utility Function to Calculate radius
	{
		int radius = sqrt(pow((Center.x - Circumference.x), 2) + pow((Center.y - Circumference.y), 2));
		return radius;
	}
	
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	CCircle(); //Default Constractor
	virtual void Draw(Output* pOut) const;
	virtual bool Get(int x,int y) const;
	virtual void printinfo(Output* pOut) const;
	virtual void Resize(double Scale);
	virtual void Rotate(int Angle);
	virtual void Save(ofstream & file);
	virtual void Load(ifstream & file);
	virtual void Paste(Point p,Point Mid);
	virtual CFigure* Copy();
	virtual string GetF()const;
	virtual Point GetMid();
	virtual bool OutsideInterface();
};

#endif