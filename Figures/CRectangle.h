#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	int width;
	int length;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	CRectangle();
	virtual void Draw(Output* pOut) const;
	virtual bool IsSelected(int x,int y);
	virtual TYPE GetType();
	virtual void PrintInfo(Output* pOut);
	void Save(ofstream& SavedGraph, Output* pOut);
	void Load(ifstream& LoadedGraph, Output* pOut);
	virtual void Move(Point moveto);

};


#endif