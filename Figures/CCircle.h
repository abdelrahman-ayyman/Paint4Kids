#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;	
	Point EndPoint;
	float Radius;
public:
	CCircle(Point , Point, GfxInfo FigureGfxInfo );
	CCircle();
	virtual void Draw(Output* pOut) const;
	virtual bool IsSelected(int x,int y);
	virtual TYPE GetType();
	virtual void PrintInfo(Output* pOut);
	void Save(ofstream& SavedGraph, Output* pOut);
	void Load(ifstream& LoadedGraph, Output* pOut);
	virtual void Move(Point moveto);

};
