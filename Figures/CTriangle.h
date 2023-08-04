#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1, Corner2, Corner3;
	GfxInfo TriangleGfxInfo;
public:
	CTriangle(Point, Point, Point, GfxInfo, bool SkipID = false);
	CTriangle();
	virtual void Draw(Output* pOut) const;
	virtual bool IsSelected(int x,int y);
	virtual TYPE GetType();
	virtual void PrintInfo(Output* pOut);
	void Save(ofstream& SavedGraph, Output* pOut);
	void Load(ifstream& LoadedGraph, Output* pOut);
	virtual void Move(Point moveto);

};