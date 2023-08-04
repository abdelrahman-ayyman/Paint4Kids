#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point Center;
public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	CHexagon();
	virtual void Draw(Output* pOut) const;
	virtual bool IsSelected(int x,int y);
	virtual TYPE GetType();
	virtual void PrintInfo(Output* pOut);
	void Save(ofstream& SavedGraph, Output* pOut);
	void Load(ifstream& LoadedGraph, Output* pOut);
	virtual void Move(Point moveto);

};